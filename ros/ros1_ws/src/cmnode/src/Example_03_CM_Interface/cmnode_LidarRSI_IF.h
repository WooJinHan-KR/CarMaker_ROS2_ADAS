#ifndef CMNODE_LIDAR_H
#define CMNODE_LIDAR_H

// CarMaker ROS Interface header
#include "cmrosutils/cmrosif.h"
#include "cmnode.h"

// ROS Package header
#include <sensor_msgs/point_cloud_conversion.h>
#include "sensor_msgs/PointCloud2.h"
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

    geometry_msgs::TransformStamped TF;
    tf2_ros::StaticTransformBroadcaster *TF_br;
    
} LidarRSI_IF;

void    LidarRSI_Data_Fill (sensor_msgs::PointCloud2::Ptr& msg);
int     CMNode_LidarRSI_IF_TestrunStartAtEnd(cm_ros::CMNode *CMNode);
int     CMNode_LidarRSI_IF_TestrunEnd (cm_ros::CMNode *CMNode);

#endif  // CMNODE_LIDAR_H