/*
******************************************************************************
**  CarMaker - Version 11.1
**  Vehicle Dynamic Simulation Toolkit
**
**  Copyright (C)   IPG Automotive GmbH
**                  Bannwaldallee 60             Phone  +49.721.98520.0
**                  76185 Karlsruhe              Fax    +49.721.98520.99
**                  Germany                      WWW    http://www.ipg.de
******************************************************************************
*/

#include "rclcpp/rclcpp.hpp"
#include "image_transport/image_transport.h"
#include "sensor_msgs/image_encodings.hpp"
#include "tf2_ros/static_transform_broadcaster.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include <angles/angles.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <signal.h>
#include <inttypes.h>
#include <unistd.h>

#ifdef WIN32
#  include <winsock2.h>
#else
#  include <sys/socket.h>
#  include <sys/types.h>
#  include <net/if.h>
#  include <netinet/in.h>
#  include <arpa/inet.h>
#  include <netdb.h>
#endif

typedef enum {
    SaveFormat_DataNotSaved = 0,
    SaveFormat_Raw,
    SaveFormat_PPM,
    SaveFormat_PGM_byte,
    SaveFormat_PGM_short,
    SaveFormat_PGM_float
} tSaveFormat;

static struct {
    FILE *EmbeddedDataCollectionFile;
    std::string MovieHost; /* pc on which IPGMovie runs          */
    int MoviePort; /* TCP/IP port for VDS                */
    int sock; /* TCP/IP Socket                      */
    char sbuf[64]; /* Buffer for transmitted information */
    int RecvFlags; /* Receive Flags                      */
    int Verbose; /* Logging Output     			*/
    int ConnectionTries;
    tSaveFormat SaveFormat;
    int TerminationRequested;
} VDScfg;

struct {
    double tFirstDataTime;
    double tStartSim;
    double tEndSim;
    double tLastSimTime;
    unsigned long long int nBytesTotal;
    unsigned long long int nBytesSim;
    unsigned long int nImagesTotal;
    unsigned long int nImagesSim;
    unsigned char nChannels;
} VDSIF;

static void VDS_PrintSimInfo();
// Helpers for VDSIF : VDS information ( stats about current status)
void VDSIF_AddDataToStats(unsigned int len);
void VDSIF_UpdateStats(unsigned int ImgLen, const char *ImgType, int Channel, int ImgWidth, int ImgHeight, float SimTime);
void VDSIF_UpdateEndSimTime();

std::shared_ptr<rclcpp::Node> Node;

/*
 ** VDS_RecvHdr
 **
 ** Scan TCP/IP Socket and writes to buffer
 */
static int VDS_RecvHdr(int sock, char *hdr)
{
    const int HdrSize = 64;
    int len = 0;
    int nSkipped = 0;
    int i;

    while (1) {
        if (VDScfg.TerminationRequested)
            return -1;
        for (; len < HdrSize; len += i) {
            if ((i = recv(sock, hdr + len, HdrSize - len, VDScfg.RecvFlags)) <= 0) {
                if (!VDScfg.TerminationRequested)
                    RCLCPP_ERROR(Node->get_logger(), "VDS_RecvHdr Error during recv (received: '%s' (%d))", hdr, len);
                return -1;
            }
        }
        if (hdr[0] == '*' && hdr[1] >= 'A' && hdr[1] <= 'Z') {
            /* remove white spaces at end of line */
            while (len > 0 && hdr[len - 1] <= ' ')
                len--;
            hdr[len] = 0;
            if (VDScfg.Verbose == 1 && nSkipped > 0)
                RCLCPP_ERROR(Node->get_logger(), "VDS: HDR resync, %d bytes skipped", nSkipped);
            return 0;
        }
        for (i = 1; i < len && hdr[i] != '*'; i++)
            ;
        len -= i;
        nSkipped += i;
        memmove(hdr, hdr + i, len);
    }
}

/*
 ** VDS_Connect
 **
 ** Connect over TCP/IP socket
 */
static int VDS_Connect(void)
{
#ifdef WIN32
    WSADATA WSAdata;
    if (WSAStartup(MAKEWORD(2,2), &WSAdata) != 0) {
        fprintf (stderr, "VDS: WSAStartup ((2,2),0) => %d\n", WSAGetLastError());
        return -1;
    }
#endif

    struct sockaddr_in DestAddr;
    struct hostent *he;
    int tries = VDScfg.ConnectionTries;

    if ((he = gethostbyname(VDScfg.MovieHost.c_str())) == NULL) {
        RCLCPP_ERROR(Node->get_logger(), "VDS: unknown host: %s", VDScfg.MovieHost.c_str());
        return -2;
    }
    DestAddr.sin_family = AF_INET;
    DestAddr.sin_port = htons((unsigned short) VDScfg.MoviePort);
    DestAddr.sin_addr.s_addr = *(unsigned *) he->h_addr;
    VDScfg.sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    while (connect(VDScfg.sock, (struct sockaddr *) &DestAddr, sizeof(DestAddr)) < 0 && tries > 0) {
        RCLCPP_INFO(Node->get_logger(), "VDS: can't connect '%s:%d'", VDScfg.MovieHost.c_str(), VDScfg.MoviePort);
        if (tries > 1) {
            RCLCPP_INFO(Node->get_logger(), "\tretrying in 1 second... (%d)", --tries);
            sleep(1);
        } else {
            return -4;
        }
    }
    if (VDS_RecvHdr(VDScfg.sock, VDScfg.sbuf) < 0)
        return -3;

    RCLCPP_INFO(Node->get_logger(), "VDS: Connected: %s", VDScfg.sbuf + 1);

    memset(VDScfg.sbuf, 0, 64);

    return 0;
}

/*
 ** VDS_GetData
 **
 ** data and image processing
 */
//static int VDS_GetData(sensor_msgs::ImagePtr& image)
static int VDS_GetData(sensor_msgs::msg::Image::SharedPtr image)
{
    unsigned int len = 0;
    ssize_t res = 0;

    /* Variables for Image Processing */
    char ImgType[32], AniMode[16];
    int ImgWidth, ImgHeight, Channel;
    float SimTime;
    unsigned int ImgLen, dataLen;

    if (sscanf(VDScfg.sbuf, "*RSDS %d %s %f %dx%d %d", &Channel, ImgType, &SimTime, &ImgWidth, &ImgHeight, &ImgLen) == 6) {
	
        VDSIF_UpdateStats(ImgLen, ImgType, Channel, ImgWidth, ImgHeight, SimTime);

        if (VDScfg.Verbose == 1)
            RCLCPP_DEBUG(Node->get_logger(), "%-6.3f : %-2d : %-8s %dx%d %d", SimTime, Channel, ImgType, ImgWidth, ImgHeight, ImgLen);

        if (ImgLen > 0) {

            image->data.resize(ImgLen);
            // this is how we get the data
            for (len = 0; len < ImgLen; len += res) {
                if ((res = recv(VDScfg.sock, &image->data[0] + len, ImgLen - len, VDScfg.RecvFlags)) < 0) {
                    RCLCPP_ERROR(Node->get_logger(), "VDS: Socket Reading Failure");
                    break;
                }
            }

            const std::string encoding = static_cast<std::string>(ImgType);

            if (encoding == "rgb") {
                image->encoding = sensor_msgs::image_encodings::RGB8;
             } else if  (encoding == "grey") {
                image->encoding = sensor_msgs::image_encodings::MONO8;
             } else if  (encoding == "grey16") {
                image->encoding = sensor_msgs::image_encodings::MONO16;
             } else if  (encoding == "depth16") {
                image->encoding = sensor_msgs::image_encodings::MONO16;
             } else {
                RCLCPP_ERROR(Node->get_logger(), "Incompatible image type/encoding: %s. Supported output formats: rgb, grey, grey16 and depth16.", ImgType);
             }

            image->width = static_cast<uint>(ImgWidth);
            image->height = static_cast<uint>(ImgHeight);
            image->step = image->width * static_cast<uint>(sensor_msgs::image_encodings::numChannels(image->encoding)
                                                 * 0.125 * sensor_msgs::image_encodings::bitDepth(image->encoding));
            image->is_bigendian = false;

            image->header.stamp = rclcpp::Clock().now();
			
            VDSIF_AddDataToStats(len);
        }
        // needed for all channels, since we want the time until the last image
        VDSIF_UpdateEndSimTime();
    } else if (sscanf(VDScfg.sbuf, "*RSDSEmbeddedData %d %f %d %s", &Channel, &SimTime, &dataLen, AniMode) == 4) {

        if (VDScfg.Verbose == 1)
            RCLCPP_INFO(Node->get_logger(), "Embedded Data: %d %f %d %s", Channel, SimTime, dataLen, AniMode);

        if (dataLen > 0) {
            char *data = (char *) malloc(dataLen);

            // get the data
            for (len = 0; len < dataLen; len += res) {
                if ((res = recv(VDScfg.sock, data + len, dataLen - len, VDScfg.RecvFlags)) < 0) {
                    RCLCPP_ERROR(Node->get_logger(), "VDS: Socket Reading Failure");
					free(data);
                    break;
                }
            }

            free(data);
        }
    } else {
        RCLCPP_INFO(Node->get_logger(), "VDS: not handled: %s", VDScfg.sbuf);
    }

    return 0;
}

/*
 ** VDS_Init
 **
 ** Initialize Data Struct
 */
void VDS_Init(void)
{
    VDScfg.MovieHost = "localhost";
    VDScfg.MoviePort = 2210;
    VDScfg.Verbose = 0;
    VDScfg.SaveFormat = SaveFormat_DataNotSaved;
    VDScfg.EmbeddedDataCollectionFile = NULL;
    VDScfg.RecvFlags = 0;
    VDScfg.ConnectionTries = 5;
    VDScfg.TerminationRequested = 0;

    VDSIF.tFirstDataTime = 0.0;
    VDSIF.tStartSim = 0.0;
    VDSIF.tEndSim = 0.0;
    VDSIF.tLastSimTime = -1.0;
    VDSIF.nImagesSim = 0;
    VDSIF.nImagesTotal = 0;
    VDSIF.nBytesTotal = 0;
    VDSIF.nBytesSim = 0;
    VDSIF.nChannels = 0;
}


static void VDS_PrintSimInfo()
{
    double dtSimReal = VDSIF.tEndSim - VDSIF.tStartSim;
    // at least 1 sec of data is required
    if (dtSimReal > 1.0) {
        RCLCPP_INFO(Node->get_logger(), "\nLast Simulation------------------");
        double MiBytes = VDSIF.nBytesSim / (1024.0 * 1024.0);
        RCLCPP_INFO(Node->get_logger(), "Duration: %.3f (real) %.3f (sim) -> x%.2f", dtSimReal, VDSIF.tLastSimTime, VDSIF.tLastSimTime / dtSimReal);
        RCLCPP_INFO(Node->get_logger(), "Channels: %d", VDSIF.nChannels);
        RCLCPP_INFO(Node->get_logger(), "Images:   %ld (%.3f FPS)", VDSIF.nImagesSim, VDSIF.nImagesSim / dtSimReal);
        RCLCPP_INFO(Node->get_logger(), "Bytes:    %.3f MiB (%.3f MiB/s)\n", MiBytes, MiBytes / dtSimReal);
    }
    if (VDScfg.EmbeddedDataCollectionFile != NULL)
        fflush(VDScfg.EmbeddedDataCollectionFile);

}

static void VDS_PrintClosingInfo()
{
    // from the very first image to the very last
    double dtSession = VDSIF.tEndSim - VDSIF.tFirstDataTime;
    RCLCPP_INFO(Node->get_logger(), "\n-> Closing VDS-Client...");

    // at least 1 sec of data is required
    if (dtSession > 1.0) {
        VDS_PrintSimInfo();
        RCLCPP_INFO(Node->get_logger(), "Session--------------------------");
        double MiBytes = VDSIF.nBytesTotal / (1024.0 * 1024.0);
        RCLCPP_INFO(Node->get_logger(), "Duration: %g seconds", dtSession);
        RCLCPP_INFO(Node->get_logger(), "Images:   %ld (%.3f FPS)", VDSIF.nImagesTotal, VDSIF.nImagesTotal / dtSession);
        RCLCPP_INFO(Node->get_logger(), "Bytes:    %.3f MiB (%.3f MiB per second)", MiBytes, MiBytes / dtSession);
    }
    fflush(stdout);

    if (VDScfg.EmbeddedDataCollectionFile != NULL)
        fclose(VDScfg.EmbeddedDataCollectionFile);
}

// on a system with properly configured timers, calling this function should need less then 0.1us
static inline double GetTime()  // in seconds
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

void VDSIF_AddDataToStats(unsigned int len)
{
    VDSIF.nImagesTotal++;
    VDSIF.nBytesTotal += len;
    VDSIF.nImagesSim++;
    VDSIF.nBytesSim += len;
}

void VDSIF_UpdateStats(unsigned int ImgLen, const char *ImgType, int Channel, int ImgWidth, int ImgHeight, float SimTime)
{
    if (VDSIF.tFirstDataTime == 0.0)
        VDSIF.tFirstDataTime = GetTime();

    if (SimTime < 0.005 || VDSIF.tLastSimTime < 0) {
        if (Channel == 0) {
            if (VDSIF.tLastSimTime > 0)
                VDS_PrintSimInfo();
            RCLCPP_INFO(Node->get_logger(), "-> Simulation started... (@ %.3f)", SimTime);
            VDSIF.tStartSim = GetTime();
            VDSIF.nBytesSim = 0;
            VDSIF.nImagesSim = 0;
            VDSIF.nChannels = 1;
        }
        // this text will appear only for the first img of each channel
        if (VDScfg.Verbose == 2)
            RCLCPP_INFO(Node->get_logger(), "%-6.3f : %-2d : %-8s %dx%d %d", SimTime, Channel, ImgType, ImgWidth, ImgHeight, ImgLen);
    }
    if (Channel == 0)
        VDSIF.tLastSimTime = SimTime;

    if (Channel >= VDSIF.nChannels)
        VDSIF.nChannels = Channel + 1;
}

void VDSIF_UpdateEndSimTime()
{
    VDSIF.tEndSim = GetTime();
}

void PrintEmbeddedData (const char* data, unsigned int dataLen)
{
    double * buf = (double *)data;
    unsigned int len =  dataLen/sizeof(double), i;
    for (i = 0; i < len; i++ ) {
        RCLCPP_INFO(Node->get_logger(), "(%d) %f ", i, buf[i]);
    }
}

void termination_handler(int signum)
{
    VDScfg.TerminationRequested = 1;
    rclcpp::shutdown();
    VDS_PrintClosingInfo();
#ifdef WIN32
    WSACleanup();
#endif
    exit(0);
}


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
	Node = std::make_shared<rclcpp::Node>("carmaker_vds_client_node");

    // shared image message
    sensor_msgs::msg::Image::SharedPtr img_ = std::make_shared<sensor_msgs::msg::Image>();
    image_transport::CameraPublisher image_pub_;
    sensor_msgs::msg::CameraInfo::SharedPtr ci = std::make_shared<sensor_msgs::msg::CameraInfo>();

    std::shared_ptr<tf2_ros::StaticTransformBroadcaster> br = std::make_shared<tf2_ros::StaticTransformBroadcaster>(Node);
	
    // advertise the main image topic
    image_transport::ImageTransport it(Node);
    image_pub_ = it.advertiseCamera("image_raw", 1);

    int i;

    VDS_Init();

    std::string param_host = "localhost";
    Node->declare_parameter("vds_host");
	rclcpp::Parameter MovieHost_get;
	Node->get_parameter_or("vds_host", MovieHost_get, rclcpp::Parameter("vds_host", param_host));
	VDScfg.MovieHost = MovieHost_get.value_to_string();

    Node->declare_parameter("vds_port");
	rclcpp::Parameter MoviePort_get;
	Node->get_parameter_or("vds_port", MoviePort_get, rclcpp::Parameter("vds_port", 2210));
	VDScfg.MoviePort = MoviePort_get.as_int();
	
	Node->declare_parameter("connection_tries");
	rclcpp::Parameter connection_tries_get;
	Node->get_parameter_or("connection_tries", connection_tries_get, rclcpp::Parameter("connection_tries", 5));
	VDScfg.ConnectionTries = connection_tries_get.as_int();

    std::string camera_frame = "";
	Node->declare_parameter("camera_frame");
	rclcpp::Parameter frame_id_get;
	Node->get_parameter_or("camera_frame", frame_id_get, rclcpp::Parameter("camera_frame", camera_frame));
	img_->header.frame_id = frame_id_get.value_to_string();
	
    // translation and rotation
    std::vector<double> param_trans_rot;
    param_trans_rot.assign(6, 0);
    Node->declare_parameter("param_trans_rot");
	rclcpp::Parameter param_trans_rot_get;
	Node->get_parameter_or("param_trans_rot", param_trans_rot_get, rclcpp::Parameter("param_trans_rot", param_trans_rot));
	param_trans_rot = param_trans_rot_get.as_double_array();
	
    geometry_msgs::msg::TransformStamped tf;
    tf.header.stamp = rclcpp::Clock().now();
    tf.header.frame_id = "Fr1";
    tf.child_frame_id = img_->header.frame_id;
	tf.transform.translation.x = param_trans_rot[0];
	tf.transform.translation.y = param_trans_rot[1];
	tf.transform.translation.z = param_trans_rot[2];
    tf2::Quaternion rot;
    tf2::Vector3 default_offset(0, 0, 0);
    rot.setRPY(angles::from_degrees(param_trans_rot[3] + default_offset[0]),
               angles::from_degrees(param_trans_rot[4] + default_offset[1]),
               angles::from_degrees(param_trans_rot[5] + default_offset[2]));
    tf.transform.rotation = tf2::toMsg(rot);
    br->sendTransform(tf);
	
    int param_binning_x;
    Node->declare_parameter("binning_x");
	rclcpp::Parameter param_binning_x_get;
	Node->get_parameter_or("binning_x", param_binning_x_get, rclcpp::Parameter("binning_x", 0));
	param_binning_x = param_binning_x_get.as_int();
    ci->binning_x = static_cast<uint>(param_binning_x);

    int param_binning_y;
    Node->declare_parameter("binning_y");
	rclcpp::Parameter param_binning_y_get;
	Node->get_parameter_or("binning_y", param_binning_y_get, rclcpp::Parameter("binning_y", 0));
	param_binning_y = param_binning_y_get.as_int();
    ci->binning_y = static_cast<uint>(param_binning_y);

    std::string distortion_model = "";
    Node->declare_parameter("distortion_model");
	rclcpp::Parameter distortion_model_get;
	Node->get_parameter_or("distortion_model", distortion_model_get, rclcpp::Parameter("distortion_model", distortion_model));
	ci->distortion_model = distortion_model_get.value_to_string();

    std::vector<double> calib_mat_k;
    calib_mat_k.assign(9, 0);
    Node->declare_parameter("calib_mat_k");
	rclcpp::Parameter calib_mat_k_get;
	Node->get_parameter_or("calib_mat_k", calib_mat_k_get, rclcpp::Parameter("calib_mat_k", calib_mat_k));
	calib_mat_k = calib_mat_k_get.as_double_array();


    std::array<double, 9> mat_K = {calib_mat_k[0], calib_mat_k[1], calib_mat_k[2],
                                     calib_mat_k[3], calib_mat_k[4], calib_mat_k[5],
                                     calib_mat_k[6], calib_mat_k[7], calib_mat_k[8]};


    std::vector<double> calib_mat_r;
    calib_mat_r.assign(9, 0);
    Node->declare_parameter("calib_mat_r");
	rclcpp::Parameter calib_mat_r_get;
	Node->get_parameter_or("calib_mat_r", calib_mat_r_get, rclcpp::Parameter("calib_mat_r", calib_mat_r));
	calib_mat_r = calib_mat_r_get.as_double_array();

	
    std::array<double, 9> mat_R = {calib_mat_r[0], calib_mat_r[1], calib_mat_r[2],
                                     calib_mat_r[3], calib_mat_r[4], calib_mat_r[5],
                                     calib_mat_r[6], calib_mat_r[7], calib_mat_r[8]};

    std::vector<double> calib_mat_p;
    calib_mat_p.assign(12, 0);
    Node->declare_parameter("calib_mat_p");
	rclcpp::Parameter calib_mat_p_get;
	Node->get_parameter_or("calib_mat_p", calib_mat_p_get, rclcpp::Parameter("calib_mat_p", calib_mat_p));
	calib_mat_p = calib_mat_p_get.as_double_array();
	

    std::array<double, 12> mat_P = {calib_mat_p[0], calib_mat_p[1], calib_mat_p[2],  calib_mat_p[3],
                                      calib_mat_p[4], calib_mat_p[5], calib_mat_p[6],  calib_mat_p[7],
                                      calib_mat_p[8], calib_mat_p[9], calib_mat_p[10], calib_mat_p[11]};


    std::vector<double> calib_mat_d;
    calib_mat_d.assign(1, 0);
    Node->declare_parameter("calib_mat_d");
	rclcpp::Parameter calib_mat_d_get;
	Node->get_parameter_or("calib_mat_d", calib_mat_d_get, rclcpp::Parameter("calib_mat_d", calib_mat_d));
	calib_mat_d = calib_mat_d_get.as_double_array();
	
    ci->k = mat_K;
    ci->r = mat_R;
    ci->p = mat_P;
    ci->d = calib_mat_d;

    // handle Ctrl-C
    if (signal(SIGINT, termination_handler) == SIG_IGN)
        signal(SIGINT, SIG_IGN);

    /* Connect to VDS Server */
    if ((i = VDS_Connect()) != 0) {
        RCLCPP_ERROR(Node->get_logger(), "Can't initialise vds client (returns %d, %s)", i, i == -4 ? "No server": strerror(errno));
    }

    while (rclcpp::ok())
    {

        /* Read from TCP/IP-Port and process the image */
        if (VDS_RecvHdr(VDScfg.sock,VDScfg.sbuf) != 0 || VDScfg.TerminationRequested) {
            break;
        }

        VDS_GetData(img_);

        // grab the camera info
        ci->header = img_->header;
        ci->height = img_->height;
        ci->width = img_->width;

         // publish the image
        image_pub_.publish(img_, ci);

        rclcpp::spin_some(Node);
    }

    VDS_PrintClosingInfo();

#ifdef WIN32
    closesocket (VDScfg.sock);
    WSACleanup();
#else
    close(VDScfg.sock);
#endif

    return 0;
}
