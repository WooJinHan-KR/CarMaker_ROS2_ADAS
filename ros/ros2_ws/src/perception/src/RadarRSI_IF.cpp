#include "perception/RadarRSI_IF.hpp"

using CMJob::Log;

void
RadarRSI_Data_Fill (hellocm_msgs::msg::RadarData& msg)
{
    geometry_msgs::msg::Point32 points;
	sensor_msgs::msg::ChannelFloat32 channels;
	channels.name = "Power";
	sensor_msgs::msg::PointCloud pointcloud;

	//clearing vector data to avoid overflows
	channels.values.clear();

	//Radar Quantity processing

	for (int j = 0; j < RadarRSI[0].nDetections; j++) {

		const double x = RadarRSI[0].DetPoints[j].Coordinates[0];
		const double y = RadarRSI[0].DetPoints[j].Coordinates[1];
		const double z = RadarRSI[0].DetPoints[j].Coordinates[2];

		points.x = x;
		points.y = y;
		points.z = z;

        double distance = std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));

		pointcloud.points.push_back(points);
		channels.values.push_back(RadarRSI[0].DetPoints[j].Power);
        msg.distance.push_back(distance);
        msg.velocity.push_back(RadarRSI[0].DetPoints[j].Velocity);
	}
	
	msg.pointcloud.channels.push_back(channels);
	msg.pointcloud.points.push_back(points);

	msg.header.stamp = rclcpp::Clock().now();
	msg.header.frame_id = "Radar_RSI";

}

int
CMNode_RadarRSI_IF_TestrunStartAtEnd (cm_ros::CMNode *CMNode)
{
    Log("\n");
    Log("RadarRSI_Sensor_Count: %d\n", RadarRSICount);
    Log("\n");
    
    if(RadarRSICount < 1) return 0;

    typedef CMJob::RosPublisher<sensor_msgs::msg::Radar_Data> Radar_RSI;
	rclcpp::Node::SharedPtr nhp = CMNode->getNodeHandle();
    CMJob::JobScheduler& scheduler = CMNode->getScheduler();
    
    auto job = std::make_shared<Radar_RSI>(nhp, "Radar_RSI");
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
}
