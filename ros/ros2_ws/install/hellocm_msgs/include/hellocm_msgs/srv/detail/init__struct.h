// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hellocm_msgs:srv/Init.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__SRV__DETAIL__INIT__STRUCT_H_
#define HELLOCM_MSGS__SRV__DETAIL__INIT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/Init in the package hellocm_msgs.
typedef struct hellocm_msgs__srv__Init_Request
{
  rosidl_runtime_c__String message;
} hellocm_msgs__srv__Init_Request;

// Struct for a sequence of hellocm_msgs__srv__Init_Request.
typedef struct hellocm_msgs__srv__Init_Request__Sequence
{
  hellocm_msgs__srv__Init_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hellocm_msgs__srv__Init_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in srv/Init in the package hellocm_msgs.
typedef struct hellocm_msgs__srv__Init_Response
{
  bool success;
  int32_t cycletime;
  rosidl_runtime_c__String message;
} hellocm_msgs__srv__Init_Response;

// Struct for a sequence of hellocm_msgs__srv__Init_Response.
typedef struct hellocm_msgs__srv__Init_Response__Sequence
{
  hellocm_msgs__srv__Init_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hellocm_msgs__srv__Init_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HELLOCM_MSGS__SRV__DETAIL__INIT__STRUCT_H_
