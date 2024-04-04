// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cmrosutils:srv/CMRemoteControl.idl
// generated code does not contain a copyright notice

#ifndef CMROSUTILS__SRV__DETAIL__CM_REMOTE_CONTROL__STRUCT_H_
#define CMROSUTILS__SRV__DETAIL__CM_REMOTE_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'type'
// Member 'msg'
// Member 'data'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/CMRemoteControl in the package cmrosutils.
typedef struct cmrosutils__srv__CMRemoteControl_Request
{
  rosidl_runtime_c__String type;
  rosidl_runtime_c__String msg;
  rosidl_runtime_c__String data;
} cmrosutils__srv__CMRemoteControl_Request;

// Struct for a sequence of cmrosutils__srv__CMRemoteControl_Request.
typedef struct cmrosutils__srv__CMRemoteControl_Request__Sequence
{
  cmrosutils__srv__CMRemoteControl_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cmrosutils__srv__CMRemoteControl_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'msg'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in srv/CMRemoteControl in the package cmrosutils.
typedef struct cmrosutils__srv__CMRemoteControl_Response
{
  int32_t res;
  rosidl_runtime_c__String msg;
} cmrosutils__srv__CMRemoteControl_Response;

// Struct for a sequence of cmrosutils__srv__CMRemoteControl_Response.
typedef struct cmrosutils__srv__CMRemoteControl_Response__Sequence
{
  cmrosutils__srv__CMRemoteControl_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cmrosutils__srv__CMRemoteControl_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CMROSUTILS__SRV__DETAIL__CM_REMOTE_CONTROL__STRUCT_H_
