// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hellocm_msgs:msg/TrafficLightStatus.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__TRAFFIC_LIGHT_STATUS__STRUCT_H_
#define HELLOCM_MSGS__MSG__DETAIL__TRAFFIC_LIGHT_STATUS__STRUCT_H_

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
#include "hellocm_msgs/msg/detail/header__struct.h"
// Member 'trafficlightindex'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/TrafficLightStatus in the package hellocm_msgs.
typedef struct hellocm_msgs__msg__TrafficLightStatus
{
  hellocm_msgs__msg__Header header;
  rosidl_runtime_c__String trafficlightindex;
  int32_t trafficlightype;
  int32_t trafficlightstatus;
} hellocm_msgs__msg__TrafficLightStatus;

// Struct for a sequence of hellocm_msgs__msg__TrafficLightStatus.
typedef struct hellocm_msgs__msg__TrafficLightStatus__Sequence
{
  hellocm_msgs__msg__TrafficLightStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hellocm_msgs__msg__TrafficLightStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HELLOCM_MSGS__MSG__DETAIL__TRAFFIC_LIGHT_STATUS__STRUCT_H_
