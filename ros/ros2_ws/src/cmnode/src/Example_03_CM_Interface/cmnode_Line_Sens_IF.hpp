#ifndef CMNODE_LINE_SENS_HPP
#define CMNODE_LINE_SENS_HPP

// CarMaker ROS Interface header
#include "cmrosutils/cmrosif.hpp"
#include "cmnode.hpp"

// ROS Package header
#include "tf2/LinearMath/Quaternion.h"                  /* Ros TF2 quaternion */
#include "tf2_ros/static_transform_broadcaster.h"
#include "visualization_msgs/msg/marker_array.hpp"

// CarMaker header
#include "CarMaker.h"
#include "Vehicle/Sensor_Line.h"

struct {
    geometry_msgs::msg::TransformStamped TF;
    std::shared_ptr<tf2_ros::StaticTransformBroadcaster> TF_br;
    
} Line_Sens_IF;

void    Line_Sens_IF_Data_Fill(visualization_msgs::msg::MarkerArray& msg);
int     CMNode_Line_Sens_IF_TestrunStartAtEnd(cm_ros::CMNode *CMNode);
int     CMNode_Line_Sens_IF_TestrunEnd(cm_ros::CMNode *CMNode);

#endif  // CMNODE_LINE_SENS_HPP