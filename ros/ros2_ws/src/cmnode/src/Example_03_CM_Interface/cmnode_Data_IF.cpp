#include "cmnode_Data_IF.hpp"

using CMJob::Log;

void Odomnetry_Data_Fill(nav_msgs::msg::Odometry& msg)
{
    msg.header.stamp = rclcpp::Time(SimCore.Time);
    msg.header.frame_id = "map";
    msg.child_frame_id = "Fr1";
    msg.pose.pose.position.x = Vehicle.Fr1A.t_0[0];
    msg.pose.pose.position.y = Vehicle.Fr1A.t_0[1];
    msg.pose.pose.position.z = Vehicle.Fr1A.t_0[2];

    tf2::Quaternion rotation;
    rotation.setRPY(Vehicle.Fr1A.r_zyx[0], Vehicle.Fr1A.r_zyx[1], Vehicle.Fr1A.r_zyx[2]);
    msg.pose.pose.orientation.x = rotation.x();
    msg.pose.pose.orientation.y = rotation.y();
    msg.pose.pose.orientation.z = rotation.z();
    msg.pose.pose.orientation.w = rotation.w();
    
    msg.twist.twist.linear.x = Vehicle.Fr1A.v_0[0];
    msg.twist.twist.linear.x = Vehicle.Fr1A.v_0[1];
    msg.twist.twist.linear.z = Vehicle.Fr1A.v_0[2];
    msg.twist.twist.angular.x = Vehicle.Fr1A.omega_0[0];
    msg.twist.twist.angular.x = Vehicle.Fr1A.omega_0[1];
    msg.twist.twist.angular.z = Vehicle.Fr1A.omega_0[2];

    geometry_msgs::msg::TransformStamped tf;
    tf.transform.rotation = msg.pose.pose.orientation;
    tf.transform.translation.x = msg.pose.pose.position.x;
    tf.transform.translation.y = msg.pose.pose.position.y;
    tf.transform.translation.z = msg.pose.pose.position.z;
    tf.header = msg.header;
    tf.child_frame_id = msg.child_frame_id;
    Data_IF.TF_br->sendTransform(tf);

}

int
CMNode_Data_IF_TestrunStartAtEnd(cm_ros::CMNode *CMNode)
{
    typedef CMJob::RosPublisher<nav_msgs::msg::Odometry> Odometry_example;
    rclcpp::Node::SharedPtr nhp = CMNode->getNodeHandle();
    CMJob::JobScheduler& scheduler = CMNode->getScheduler();

    auto job = std::make_shared<Odometry_example>(nhp, "Odometry_example");
	job->setCycleTime(1);
    job->setCycleOffset(0);
	job->setCallbackHook(CMJob::CallbackHook::Calc);
	job->registerCallback(&Odomnetry_Data_Fill);
    scheduler.addJob(job);

    Data_IF.TF_br = std::make_shared<tf2_ros::StaticTransformBroadcaster>(nhp);

    return 1;
}

int
CMNode_Data_IF_TestrunEnd(cm_ros::CMNode *CMNode)
{
    CMJob::JobScheduler& scheduler = CMNode->getScheduler();

    scheduler.deleteJob("Odometry_example");
}
