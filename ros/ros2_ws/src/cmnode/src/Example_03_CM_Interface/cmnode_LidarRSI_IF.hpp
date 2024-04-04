#ifndef CMNODE_LIDAR_HPP
#define CMNODE_LIDAR_HPP

// CarMaker ROS Interface header
#include "cmrosutils/cmrosif.hpp"
#include "cmnode.hpp"

// ROS Package header
#include "sensor_msgs/point_cloud_conversion.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "tf2/LinearMath/Quaternion.h"                  /* Ros TF2 quaternion */
#include "tf2_ros/transform_broadcaster.h"              /* Publish TF2 transforms */
#include "tf2_ros/static_transform_broadcaster.h"
#include <angles/angles.h>

// CarMaker header
#include "CarMaker.h"
#include "Vehicle/Sensor_LidarRSI.h"

#define VLP_16_NUMBER_OF_POINTS 28800

struct {
    int             Beam_nRow;
    double*         BeamTable;

    geometry_msgs::msg::TransformStamped TF;
    std::shared_ptr<tf2_ros::StaticTransformBroadcaster> TF_br;
    
} LidarRSI_IF;

void    LidarRSI_Data_Fill (sensor_msgs::msg::PointCloud2& msg);
int     CMNode_LidarRSI_IF_TestrunStartAtEnd(cm_ros::CMNode *CMNode);
int     CMNode_LidarRSI_IF_TestrunEnd (cm_ros::CMNode *CMNode);

#endif  // CMNODE_LIDAR_HPP