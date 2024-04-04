// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cmrosutils:srv/CMRemoteControl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cmrosutils/srv/detail/cm_remote_control__rosidl_typesupport_introspection_c.h"
#include "cmrosutils/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cmrosutils/srv/detail/cm_remote_control__functions.h"
#include "cmrosutils/srv/detail/cm_remote_control__struct.h"


// Include directives for member types
// Member `type`
// Member `msg`
// Member `data`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void CMRemoteControl_Request__rosidl_typesupport_introspection_c__CMRemoteControl_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cmrosutils__srv__CMRemoteControl_Request__init(message_memory);
}

void CMRemoteControl_Request__rosidl_typesupport_introspection_c__CMRemoteControl_Request_fini_function(void * message_memory)
{
  cmrosutils__srv__CMRemoteControl_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember CMRemoteControl_Request__rosidl_typesupport_introspection_c__CMRemoteControl_Request_message_member_array[3] = {
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cmrosutils__srv__CMRemoteControl_Request, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "msg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cmrosutils__srv__CMRemoteControl_Request, msg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cmrosutils__srv__CMRemoteControl_Request, data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CMRemoteControl_Request__rosidl_typesupport_introspection_c__CMRemoteControl_Request_message_members = {
  "cmrosutils__srv",  // message namespace
  "CMRemoteControl_Request",  // message name
  3,  // number of fields
  sizeof(cmrosutils__srv__CMRemoteControl_Request),
  CMRemoteControl_Request__rosidl_typesupport_introspection_c__CMRemoteControl_Request_message_member_array,  // message members
  CMRemoteControl_Request__rosidl_typesupport_introspection_c__CMRemoteControl_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  CMRemoteControl_Request__rosidl_typesupport_introspection_c__CMRemoteControl_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CMRemoteControl_Request__rosidl_typesupport_introspection_c__CMRemoteControl_Request_message_type_support_handle = {
  0,
  &CMRemoteControl_Request__rosidl_typesupport_introspection_c__CMRemoteControl_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cmrosutils
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cmrosutils, srv, CMRemoteControl_Request)() {
  if (!CMRemoteControl_Request__rosidl_typesupport_introspection_c__CMRemoteControl_Request_message_type_support_handle.typesupport_identifier) {
    CMRemoteControl_Request__rosidl_typesupport_introspection_c__CMRemoteControl_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CMRemoteControl_Request__rosidl_typesupport_introspection_c__CMRemoteControl_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "cmrosutils/srv/detail/cm_remote_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "cmrosutils/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "cmrosutils/srv/detail/cm_remote_control__functions.h"
// already included above
// #include "cmrosutils/srv/detail/cm_remote_control__struct.h"


// Include directives for member types
// Member `msg`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void CMRemoteControl_Response__rosidl_typesupport_introspection_c__CMRemoteControl_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cmrosutils__srv__CMRemoteControl_Response__init(message_memory);
}

void CMRemoteControl_Response__rosidl_typesupport_introspection_c__CMRemoteControl_Response_fini_function(void * message_memory)
{
  cmrosutils__srv__CMRemoteControl_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember CMRemoteControl_Response__rosidl_typesupport_introspection_c__CMRemoteControl_Response_message_member_array[2] = {
  {
    "res",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cmrosutils__srv__CMRemoteControl_Response, res),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "msg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cmrosutils__srv__CMRemoteControl_Response, msg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CMRemoteControl_Response__rosidl_typesupport_introspection_c__CMRemoteControl_Response_message_members = {
  "cmrosutils__srv",  // message namespace
  "CMRemoteControl_Response",  // message name
  2,  // number of fields
  sizeof(cmrosutils__srv__CMRemoteControl_Response),
  CMRemoteControl_Response__rosidl_typesupport_introspection_c__CMRemoteControl_Response_message_member_array,  // message members
  CMRemoteControl_Response__rosidl_typesupport_introspection_c__CMRemoteControl_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  CMRemoteControl_Response__rosidl_typesupport_introspection_c__CMRemoteControl_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CMRemoteControl_Response__rosidl_typesupport_introspection_c__CMRemoteControl_Response_message_type_support_handle = {
  0,
  &CMRemoteControl_Response__rosidl_typesupport_introspection_c__CMRemoteControl_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cmrosutils
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cmrosutils, srv, CMRemoteControl_Response)() {
  if (!CMRemoteControl_Response__rosidl_typesupport_introspection_c__CMRemoteControl_Response_message_type_support_handle.typesupport_identifier) {
    CMRemoteControl_Response__rosidl_typesupport_introspection_c__CMRemoteControl_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CMRemoteControl_Response__rosidl_typesupport_introspection_c__CMRemoteControl_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "cmrosutils/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "cmrosutils/srv/detail/cm_remote_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers cmrosutils__srv__detail__cm_remote_control__rosidl_typesupport_introspection_c__CMRemoteControl_service_members = {
  "cmrosutils__srv",  // service namespace
  "CMRemoteControl",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // cmrosutils__srv__detail__cm_remote_control__rosidl_typesupport_introspection_c__CMRemoteControl_Request_message_type_support_handle,
  NULL  // response message
  // cmrosutils__srv__detail__cm_remote_control__rosidl_typesupport_introspection_c__CMRemoteControl_Response_message_type_support_handle
};

static rosidl_service_type_support_t cmrosutils__srv__detail__cm_remote_control__rosidl_typesupport_introspection_c__CMRemoteControl_service_type_support_handle = {
  0,
  &cmrosutils__srv__detail__cm_remote_control__rosidl_typesupport_introspection_c__CMRemoteControl_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cmrosutils, srv, CMRemoteControl_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cmrosutils, srv, CMRemoteControl_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cmrosutils
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cmrosutils, srv, CMRemoteControl)() {
  if (!cmrosutils__srv__detail__cm_remote_control__rosidl_typesupport_introspection_c__CMRemoteControl_service_type_support_handle.typesupport_identifier) {
    cmrosutils__srv__detail__cm_remote_control__rosidl_typesupport_introspection_c__CMRemoteControl_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)cmrosutils__srv__detail__cm_remote_control__rosidl_typesupport_introspection_c__CMRemoteControl_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cmrosutils, srv, CMRemoteControl_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cmrosutils, srv, CMRemoteControl_Response)()->data;
  }

  return &cmrosutils__srv__detail__cm_remote_control__rosidl_typesupport_introspection_c__CMRemoteControl_service_type_support_handle;
}
