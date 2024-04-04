#include "cmnode_Line_Sens_IF.hpp"

using CMJob::Log;

void Line_Sens_IF_Data_Fill(visualization_msgs::msg::MarkerArray& msg)
{
    msg.markers.clear();  // Clear existing markers in the array

    // Add a marker with DELETEALL action to clear all previous markers
    visualization_msgs::msg::Marker delete_all_marker;
    delete_all_marker.header.frame_id = "Line_example";
    delete_all_marker.header.stamp = rclcpp::Clock().now();
    delete_all_marker.ns = "line_strips";
    delete_all_marker.action = visualization_msgs::msg::Marker::DELETEALL;
    delete_all_marker.id = -1;
    msg.markers.push_back(delete_all_marker);

    // Assuming you have a loop or some logic to generate multiple lines
    for (int i = 0; i < LineSensor[0].LLines.nLine; i++)
    {
        visualization_msgs::msg::Marker line_strip;
        line_strip.header.frame_id = "Line_example";
        line_strip.header.stamp = rclcpp::Clock().now();
        line_strip.ns = "line_strips";
        line_strip.action = visualization_msgs::msg::Marker::ADD;
        line_strip.pose.orientation.w = 1.0;
        line_strip.id = i;
        line_strip.type = visualization_msgs::msg::Marker::LINE_STRIP;
        line_strip.scale.x = 0.1;  // Line width

        // Set color (RGBA)
        line_strip.color.r = 1.0;
        line_strip.color.g = 1.0;
        line_strip.color.b = 1.0;
        line_strip.color.a = 1.0;

        geometry_msgs::msg::Point p;
        for (int j = 0; j < LineSensor[0].LLines.L[i].nP; j++)
        {
            p.x = LineSensor[0].LLines.L[i].ds[j][0];
            p.y = LineSensor[0].LLines.L[i].ds[j][1];
            p.z = LineSensor[0].LLines.L[i].ds[j][2];
            line_strip.points.push_back(p);
        }

        msg.markers.push_back(line_strip);
    }
    
    for (int i = 0; i < LineSensor[0].RLines.nLine; i++)
    {
        visualization_msgs::msg::Marker line_strip;
        line_strip.header.frame_id = "Line_example";
        line_strip.header.stamp = rclcpp::Clock().now();
        line_strip.ns = "line_strips";
        line_strip.action = visualization_msgs::msg::Marker::ADD;
        line_strip.pose.orientation.w = 1.0;
        line_strip.id = LSMAXTRACKS + i; // LSMAXTRACKS == 100
        line_strip.type = visualization_msgs::msg::Marker::LINE_STRIP;
        line_strip.scale.x = 0.1;  // Line width

        // Set color (RGBA)
        line_strip.color.r = 1.0;
        line_strip.color.g = 1.0;
        line_strip.color.b = 1.0;
        line_strip.color.a = 1.0;

        geometry_msgs::msg::Point p;
        for (int j = 0; j < LineSensor[0].RLines.L[i].nP; j++)
        {
            p.x = LineSensor[0].RLines.L[i].ds[j][0];
            p.y = LineSensor[0].RLines.L[i].ds[j][1];
            p.z = LineSensor[0].RLines.L[i].ds[j][2];
            line_strip.points.push_back(p);
        }

        msg.markers.push_back(line_strip);
    }

}

int
CMNode_Line_Sens_IF_TestrunStartAtEnd (cm_ros::CMNode *CMNode)
{
    Log("\n");
    Log("Line_Sensor_Count: %d\n", LineSensorCount);
    Log("\n");
    
    if(LineSensorCount < 1) return 0;

    typedef CMJob::RosPublisher<visualization_msgs::msg::MarkerArray> Line_example;
	rclcpp::Node::SharedPtr nhp = CMNode->getNodeHandle();
    CMJob::JobScheduler& scheduler = CMNode->getScheduler();

    auto job = std::make_shared<Line_example>(nhp, "Line_example");
	job->setCycleTime(35);
    job->setCycleOffset(0);
	job->setCallbackHook(CMJob::CallbackHook::Calc);
	job->registerCallback(&Line_Sens_IF_Data_Fill);
    scheduler.addJob(job);
    
    tf2::Quaternion q;
    double position[3];
    double rotation[3];
    
    position[0] = 2.6;  //x
    position[1] = 0;    //y
    position[2] = 1.2;  //z
    rotation[0] = 0;    //x
    rotation[1] = 0;    //y
    rotation[2] = 0;    //z

    q.setRPY(rotation[0] * (M_PI / 180.0), rotation[1] * (M_PI / 180.0), rotation[2] * (M_PI / 180.0));
    Line_Sens_IF.TF.transform.rotation.x  = q.x();
    Line_Sens_IF.TF.transform.rotation.y  = q.y();
    Line_Sens_IF.TF.transform.rotation.z  = q.z();
    Line_Sens_IF.TF.transform.rotation.w  = q.w();
    Line_Sens_IF.TF.transform.translation.x = position[0];
    Line_Sens_IF.TF.transform.translation.y = position[1];
    Line_Sens_IF.TF.transform.translation.z = position[2];
    Line_Sens_IF.TF.header.frame_id       = "Fr1";
    Line_Sens_IF.TF.child_frame_id        = "Line_example";

    Line_Sens_IF.TF_br = std::make_shared<tf2_ros::StaticTransformBroadcaster>(nhp);
    Line_Sens_IF.TF_br->sendTransform(Line_Sens_IF.TF);

    return 1;
}

int
CMNode_Line_Sens_IF_TestrunEnd(cm_ros::CMNode *CMNode)
{
    CMJob::JobScheduler& scheduler = CMNode->getScheduler();

    scheduler.deleteJob("Line_example");
}
