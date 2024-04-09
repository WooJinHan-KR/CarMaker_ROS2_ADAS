// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hellocm_msgs:msg/RadarData.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__RADAR_DATA__STRUCT_H_
#define HELLOCM_MSGS__MSG__DETAIL__RADAR_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'frame_id'
#include "rosidl_runtime_c/string.h"
// Member 'pointcloud2'
#include "sensor_msgs/msg/detail/point_cloud2__struct.h"
// Member 'velocity'
// Member 'distance'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/RadarData in the package hellocm_msgs.
typedef struct hellocm_msgs__msg__RadarData
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String frame_id;
  sensor_msgs__msg__PointCloud2 pointcloud2;
  rosidl_runtime_c__double__Sequence velocity;
  rosidl_runtime_c__double__Sequence distance;
} hellocm_msgs__msg__RadarData;

// Struct for a sequence of hellocm_msgs__msg__RadarData.
typedef struct hellocm_msgs__msg__RadarData__Sequence
{
  hellocm_msgs__msg__RadarData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hellocm_msgs__msg__RadarData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HELLOCM_MSGS__MSG__DETAIL__RADAR_DATA__STRUCT_H_
