#ifndef CMNODE_OBJECT_SENS_H
#define CMNODE_OBJECT_SENS_H

// CarMaker ROS Interface header
#include "cmrosutils/cmrosif.h"
#include "cmnode.h"

// ROS Package header
#include "tf2/LinearMath/Quaternion.h"                  /* Ros TF2 quaternion */
#include "tf2_ros/static_transform_broadcaster.h"
#include <visualization_msgs/MarkerArray.h>

// CarMaker header
#include "CarMaker.h"
#include "Vehicle/Sensor_Object.h"

struct {
    geometry_msgs::TransformStamped TF;
    tf2_ros::StaticTransformBroadcaster *TF_br;
    
} Object_Sens_IF;

void    Object_Sens_IF_Data_Fill(visualization_msgs::MarkerArray::Ptr& msg);
int     CMNode_Object_Sens_IF_TestrunStartAtEnd(cm_ros::CMNode *CMNode);
int     CMNode_Object_Sens_IF_TestrunEnd(cm_ros::CMNode *CMNode);

#endif  // CMNODE_OBJECT_SENS_H