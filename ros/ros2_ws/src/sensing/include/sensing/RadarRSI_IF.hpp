#ifndef RADAR_HPP
#define RADAR_HPP

// CarMaker ROS Interface header
#include "cmrosutils/cmrosif.hpp"
#include "cmnode.hpp"

// ROS Package header
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "sensor_msgs/point_cloud_conversion.hpp"
#include "tf2/LinearMath/Quaternion.h"                  /* Ros TF2 quaternion */
#include "tf2_ros/transform_broadcaster.h"              /* Publish TF2 transforms */
#include "tf2_ros/static_transform_broadcaster.h"
#include <angles/angles.h>
#include <cmath>

// CarMaker header
#include "CarMaker.h"
#include "Vehicle/Sensor_RadarRSI.h"

struct {
    int             Beam_nRow;
    double*         BeamTable;

    geometry_msgs::msg::TransformStamped TF;
    std::shared_ptr<tf2_ros::StaticTransformBroadcaster> TF_br;
    
} RadarRSI_IF;

void    RadarRSI_Data_Fill (sensor_msgs::msg::PointCloud2& msg);
int     CMNode_RadarRSI_IF_TestrunStartAtEnd(cm_ros::CMNode *CMNode);
int     CMNode_RadarRSI_IF_TestrunEnd (cm_ros::CMNode *CMNode);

#endif  // RADAR_HPP