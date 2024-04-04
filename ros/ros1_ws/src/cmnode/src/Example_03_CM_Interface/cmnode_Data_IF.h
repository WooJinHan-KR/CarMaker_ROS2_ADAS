#ifndef CMNODE_DATA_IF_H
#define CMNODE_DATA_IF_H

// CarMaker ROS Interface header
#include "cmrosutils/cmrosif.h"
#include "cmnode.h"

// ROS Package header
#include "tf2/LinearMath/Quaternion.h"                  /* Ros TF2 quaternion */
#include "tf2_ros/static_transform_broadcaster.h"
#include "nav_msgs/Odometry.h"

// CarMaker header
#include "CarMaker.h"

struct {
    tf2_ros::StaticTransformBroadcaster *TF_br;
    
} Data_IF;

void    Odomnetry_Data_Fill(nav_msgs::Odometry::Ptr& msg);
int     CMNode_Data_IF_TestrunStartAtEnd(cm_ros::CMNode *CMNode);
int     CMNode_Data_IF_TestrunEnd(cm_ros::CMNode *CMNode);

#endif  // CMNODE_DATA_IF_H