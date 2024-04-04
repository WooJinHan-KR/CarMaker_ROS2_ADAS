// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hellocm_msgs:msg/Ext2CM.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__EXT2_CM__STRUCT_H_
#define HELLOCM_MSGS__MSG__DETAIL__EXT2_CM__STRUCT_H_

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
// Member 'time'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in msg/Ext2CM in the package hellocm_msgs.
typedef struct hellocm_msgs__msg__Ext2CM
{
  std_msgs__msg__Header header;
  builtin_interfaces__msg__Time time;
  int64_t cycleno;
} hellocm_msgs__msg__Ext2CM;

// Struct for a sequence of hellocm_msgs__msg__Ext2CM.
typedef struct hellocm_msgs__msg__Ext2CM__Sequence
{
  hellocm_msgs__msg__Ext2CM * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hellocm_msgs__msg__Ext2CM__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HELLOCM_MSGS__MSG__DETAIL__EXT2_CM__STRUCT_H_
