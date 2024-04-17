#include "sensing/RadarRSI_IF.hpp"

using CMJob::Log;

void
RadarRSI_Data_Fill (hellocm_msgs::msg::RadarData& msg)
{
    //geometry_msgs::msg::Point32 points;
	//sensor_msgs::msg::ChannelFloat32 channels;
	//channels.name = "Power";
	//sensor_msgs::msg::PointCloud pointcloud;
	//clearing vector data to avoid overflows
	//channels.values.clear();

	//Radar Quantity processing
    sensor_msgs::msg::PointCloud2 pointcloud;

    // Set the fields
    pointcloud.height = 1;  // Height of the pointcloud, typically 1 for unordered point clouds
    pointcloud.width = RadarRSI[0].nDetections;  // Number of points in the pointcloud
    pointcloud.fields.resize(3);  // Resize the fields array to hold x, y, z fields
    pointcloud.fields[0].name = "x";  // Name of the first field
    pointcloud.fields[0].offset = 0;  // Offset of the first field in bytes
    pointcloud.fields[0].datatype = sensor_msgs::msg::PointField::FLOAT32;  // Data type of the first field
    pointcloud.fields[0].count = 1;  // Number of elements in the first field
    pointcloud.fields[1].name = "y";  // Name of the second field
    pointcloud.fields[1].offset = 4;  // Offset of the second field in bytes (FLOAT32 is 4 bytes)
    pointcloud.fields[1].datatype = sensor_msgs::msg::PointField::FLOAT32;  // Data type of the second field
    pointcloud.fields[1].count = 1;  // Number of elements in the second field
    pointcloud.fields[2].name = "z";  // Name of the third field
    pointcloud.fields[2].offset = 8;  // Offset of the third field in bytes
    pointcloud.fields[2].datatype = sensor_msgs::msg::PointField::FLOAT32;  // Data type of the third field
    pointcloud.fields[2].count = 1;  // Number of elements in the third field

    // Calculate the total size of each point in the pointcloud (x, y, z fields)
    pointcloud.point_step = 12;  // 3 fields * 4 bytes per field (FLOAT32)
    pointcloud.row_step = pointcloud.point_step * RadarRSI[0].nDetections;  // Total size of all points in the pointcloud

    // Resize the data array to hold all the points
    pointcloud.data.resize(pointcloud.row_step * pointcloud.height);

	for (int j = 0; j < RadarRSI[0].nDetections; j++) {

		const double x = RadarRSI[0].DetPoints[j].Coordinates[0];
		const double y = RadarRSI[0].DetPoints[j].Coordinates[1];
		const double z = RadarRSI[0].DetPoints[j].Coordinates[2];

		//points.x = x;
		//points.y = y;
		//points.z = z;

        size_t offset = j * pointcloud.point_step;

        double distance = std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));

		//pointcloud.points.push_back(points);
		//channels.values.push_back(RadarRSI[0].DetPoints[j].Power);
        memcpy(&pointcloud.data[offset], &x, sizeof(float));
        memcpy(&pointcloud.data[offset + 4], &y, sizeof(float));
        memcpy(&pointcloud.data[offset + 8], &z, sizeof(float));
        msg.distance.push_back(distance);
        msg.velocity.push_back(RadarRSI[0].DetPoints[j].Velocity);
	}
	
	//pointcloud.channels.push_back(channels);
    //sensor_msgs::convertPointCloudToPointCloud2(pointcloud, msg.pointcloud2);

	pointcloud.header.stamp = rclcpp::Clock().now();
	pointcloud.header.frame_id = "Radar_RSI";

    // Set other fields of the pointcloud message
    pointcloud.is_bigendian = false;  // Endianness of the data (false for little endian)
    pointcloud.is_dense = true;  // Whether the pointcloud contains all finite points

    // Set the pointcloud message in the RadarData message
    msg.pointcloud2 = pointcloud;

}

int
CMNode_RadarRSI_IF_TestrunStartAtEnd (cm_ros::CMNode *CMNode)
{
    Log("\n");
    Log("RadarRSI_Sensor_Count: %d\n", RadarRSICount);
    Log("\n");
    
    if(RadarRSICount < 1) return 0;

    typedef CMJob::RosPublisher<hellocm_msgs::msg::RadarData> Radar_RSI;
	rclcpp::Node::SharedPtr nhp = CMNode->getNodeHandle();
    CMJob::JobScheduler& scheduler = CMNode->getScheduler();
    
    auto job = std::make_shared<Radar_RSI>(nhp, "/sensing/Radar_RSI");
	job->setCycleTime(100);
    job->setCycleOffset(0);
	job->setCallbackHook(CMJob::CallbackHook::Calc);
	job->registerCallback(&RadarRSI_Data_Fill);
    scheduler.addJob(job);
    
    tf2::Quaternion q;
    double position[3];
    double rotation[3];
    
    position[0] = 4.4;  //x
    position[1] = 0;    //y
    position[2] = 0.4;  //z
    rotation[0] = 0;    //x
    rotation[1] = 0;    //y
    rotation[2] = 0;    //z

    q.setRPY(rotation[0] * (M_PI / 180.0), rotation[1] * (M_PI / 180.0), rotation[2] * (M_PI / 180.0));
    RadarRSI_IF.TF.transform.rotation.x  = q.x();
    RadarRSI_IF.TF.transform.rotation.y  = q.y();
    RadarRSI_IF.TF.transform.rotation.z  = q.z();
    RadarRSI_IF.TF.transform.rotation.w  = q.w();
    RadarRSI_IF.TF.transform.translation.x = position[0];
    RadarRSI_IF.TF.transform.translation.y = position[1];
    RadarRSI_IF.TF.transform.translation.z = position[2];
    RadarRSI_IF.TF.header.frame_id       = "Fr1";
    RadarRSI_IF.TF.child_frame_id        = "Radar_RSI";

    RadarRSI_IF.TF_br = std::make_shared<tf2_ros::StaticTransformBroadcaster>(nhp);
    RadarRSI_IF.TF_br->sendTransform(RadarRSI_IF.TF);
    
    return 1;
}

int
CMNode_RadarRSI_IF_TestrunEnd (cm_ros::CMNode *CMNode)
{
    CMJob::JobScheduler& scheduler = CMNode->getScheduler();

    scheduler.deleteJob("Radar_RSI");

    return 0;
}
