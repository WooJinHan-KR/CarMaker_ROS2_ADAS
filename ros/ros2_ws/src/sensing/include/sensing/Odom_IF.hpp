#ifndef ODOM_IF_HPP
#define ODOM_IF_HPP

// CarMaker ROS Interface header
#include "cmrosutils/cmrosif.hpp"
#include "cmnode.hpp"

// ROS Package header
#include "tf2/LinearMath/Quaternion.h"                  /* Ros TF2 quaternion */
#include "tf2_ros/static_transform_broadcaster.h"
#include "nav_msgs/msg/odometry.hpp"

// CarMaker header
#include "CarMaker.h"

struct {
    std::shared_ptr<tf2_ros::StaticTransformBroadcaster> TF_br;
    
} Data_IF;

void    Odomnetry_Data_Fill(nav_msgs::msg::Odometry& msg);
int     CMNode_Odom_IF_TestrunStartAtEnd(cm_ros::CMNode *CMNode);
int     CMNode_Odom_IF_TestrunEnd(cm_ros::CMNode *CMNode);

#endif  // ODOM_IF_HPP