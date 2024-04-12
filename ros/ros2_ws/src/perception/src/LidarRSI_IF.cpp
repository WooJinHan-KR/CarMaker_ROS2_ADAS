#include "perception/LidarRSI_IF.hpp"

using CMJob::Log;

void
LidarRSI_Data_Fill (sensor_msgs::msg::PointCloud2& msg)
{
    geometry_msgs::msg::Point32 points;
	sensor_msgs::msg::ChannelFloat32 channels;
	channels.name = "intensity";
	sensor_msgs::msg::PointCloud pointcloud;

	//clearing vector data to avoid overflows
	channels.values.clear();

	//Lidar Quantity processing
	for (int j = 0; j < LidarRSI[0].nScanPoints; j++) {

		//const int beam_id = LidarRSI[0].ScanPoint[j].BeamID;
		const double azimuth    = angles::from_degrees(LidarRSI_IF.BeamTable[4*LidarRSI_IF.Beam_nRow + LidarRSI[0].ScanPoint[j].BeamID]);      // BeamID is the table row, and Azimuth is column 5
		const double elevation  = angles::from_degrees(LidarRSI_IF.BeamTable[5*LidarRSI_IF.Beam_nRow + LidarRSI[0].ScanPoint[j].BeamID]);      // BeamID is the table row, and Elevation is column 6
		const double ray_length = 0.5 * LidarRSI[0].ScanPoint[j].LengthOF; // length of flight is back and forth

		//XYZ-coordinates of scan point
		points.x = ray_length * cos(elevation) * cos(azimuth);
		points.y = ray_length * cos(elevation) * sin(azimuth);
		points.z = ray_length * sin(elevation);

		pointcloud.points.push_back(points);
		channels.values.push_back(LidarRSI[0].ScanPoint[j].Intensity);

	}
	
	pointcloud.channels.push_back(channels);

	sensor_msgs::convertPointCloudToPointCloud2(pointcloud, msg);

	msg.header.stamp = rclcpp::Clock().now();
	msg.header.frame_id = "Lidar_example";

}

/*
void LidarRSI_Data_Fill(sensor_msgs::msg::PointCloud2& msg)
{
    const int num_points = LidarRSI[0].nScanPoints;
    const size_t point_step = 16; // 4 floats for x, y, z, intensity

    // Clearing vector data to avoid overflows
    std::vector<float> point_cloud_data(num_points * point_step);
    
    // Lidar Quantity processing
    for (int j = 0; j < num_points; ++j) {
        const double azimuth = angles::from_degrees(LidarRSI_IF.BeamTable[4 * LidarRSI_IF.Beam_nRow + LidarRSI[0].ScanPoint[j].BeamID]);
        const double elevation = angles::from_degrees(LidarRSI_IF.BeamTable[5 * LidarRSI_IF.Beam_nRow + LidarRSI[0].ScanPoint[j].BeamID]);
        const double ray_length = 0.5 * LidarRSI[0].ScanPoint[j].LengthOF;

        // XYZ-coordinates of scan point
        const float x = ray_length * cos(elevation) * cos(azimuth);
        const float y = ray_length * cos(elevation) * sin(azimuth);
        const float z = ray_length * sin(elevation);

        // Intensity value
        const float intensity = LidarRSI[0].ScanPoint[j].Intensity;

        // Offset for the current point in the point cloud data buffer
        const size_t offset = j * point_step;

        // Fill in point data
        std::memcpy(&point_cloud_data[offset], &x, sizeof(float));
        std::memcpy(&point_cloud_data[offset + 4], &y, sizeof(float));
        std::memcpy(&point_cloud_data[offset + 8], &z, sizeof(float));
        std::memcpy(&point_cloud_data[offset + 12], &intensity, sizeof(float));
    }

    // Fill in the header of the PointCloud2 message
    msg.header.stamp = rclcpp::Clock().now();
    msg.header.frame_id = "Lidar_example";
    msg.height = 1;
    msg.width = num_points; // Number of points
    msg.fields.resize(4); // x, y, z, intensity
    msg.fields[0].name = "x";
    msg.fields[0].offset = 0;
    msg.fields[0].datatype = sensor_msgs::msg::PointField::FLOAT32;
    msg.fields[0].count = 1;
    msg.fields[1].name = "y";
    msg.fields[1].offset = 4;
    msg.fields[1].datatype = sensor_msgs::msg::PointField::FLOAT32;
    msg.fields[1].count = 1;
    msg.fields[2].name = "z";
    msg.fields[2].offset = 8;
    msg.fields[2].datatype = sensor_msgs::msg::PointField::FLOAT32;
    msg.fields[2].count = 1;
    msg.fields[3].name = "intensity";
    msg.fields[3].offset = 12;
    msg.fields[3].datatype = sensor_msgs::msg::PointField::FLOAT32;
    msg.fields[3].count = 1;
    msg.is_bigendian = false;
    msg.point_step = point_step; // Size of a single point in bytes (x, y, z, intensity)
    msg.row_step = point_step * num_points; // Total size of the point cloud in bytes
    msg.is_dense = true; // All points are finite

    // Resize the data buffer to hold all points
    msg.data.resize(num_points * point_step);

    // Copy point data into the message data buffer
    std::memcpy(&msg.data[0], &point_cloud_data[0], num_points * point_step * sizeof(float));
}*/

int
CMNode_LidarRSI_IF_TestrunStartAtEnd (cm_ros::CMNode *CMNode)
{
    Log("\n");
    Log("LidarRSI_Sensor_Count: %d\n", LidarRSICount);
    Log("\n");
    
    if(LidarRSICount < 1) return 0;

    tInfos *Inf_Sensor = nullptr;
    tErrorMsg *err = nullptr;
	
    //Create infofile handle
    Inf_Sensor = InfoNew();
    iRead2(&err, Inf_Sensor, "Data/Sensor/LidarRSI_VLP_16", "");
    LidarRSI_IF.BeamTable = (double*)malloc(VLP_16_NUMBER_OF_POINTS * 6 * sizeof(double));
    //Read infofile parameters
    iGetTableOpt(Inf_Sensor, "Beams", LidarRSI_IF.BeamTable, VLP_16_NUMBER_OF_POINTS * 6, 6, &LidarRSI_IF.Beam_nRow);
	InfoDelete(Inf_Sensor);

    typedef CMJob::RosPublisher<sensor_msgs::msg::PointCloud2> Lidar_RSI;
	rclcpp::Node::SharedPtr nhp = CMNode->getNodeHandle();
    CMJob::JobScheduler& scheduler = CMNode->getScheduler();
    
    auto job = std::make_shared<Lidar_RSI>(nhp, "Lidar_RSI");
	job->setCycleTime(100);
    job->setCycleOffset(0);
	job->setCallbackHook(CMJob::CallbackHook::Calc);
	job->registerCallback(&LidarRSI_Data_Fill);
    scheduler.addJob(job);
    
    tf2::Quaternion q;
    double position[3];
    double rotation[3];
    
    position[0] = 2.2;  //x
    position[1] = 0;    //y
    position[2] = 1.6;  //z
    rotation[0] = 0;    //x
    rotation[1] = 0;    //y
    rotation[2] = 0;    //z

    q.setRPY(rotation[0] * (M_PI / 180.0), rotation[1] * (M_PI / 180.0), rotation[2] * (M_PI / 180.0));
    LidarRSI_IF.TF.transform.rotation.x  = q.x();
    LidarRSI_IF.TF.transform.rotation.y  = q.y();
    LidarRSI_IF.TF.transform.rotation.z  = q.z();
    LidarRSI_IF.TF.transform.rotation.w  = q.w();
    LidarRSI_IF.TF.transform.translation.x = position[0];
    LidarRSI_IF.TF.transform.translation.y = position[1];
    LidarRSI_IF.TF.transform.translation.z = position[2];
    LidarRSI_IF.TF.header.frame_id       = "Fr1";
    LidarRSI_IF.TF.child_frame_id        = "Lidar_RSI";

    LidarRSI_IF.TF_br = std::make_shared<tf2_ros::StaticTransformBroadcaster>(nhp);
    LidarRSI_IF.TF_br->sendTransform(LidarRSI_IF.TF);
    
    return 1;
}

int
CMNode_LidarRSI_IF_TestrunEnd (cm_ros::CMNode *CMNode)
{
    CMJob::JobScheduler& scheduler = CMNode->getScheduler();

    scheduler.deleteJob("Lidar_RSI");
}
