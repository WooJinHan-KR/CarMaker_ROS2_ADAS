// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hellocm_msgs:srv/Init.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hellocm_msgs/srv/detail/init__rosidl_typesupport_introspection_c.h"
#include "hellocm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hellocm_msgs/srv/detail/init__functions.h"
#include "hellocm_msgs/srv/detail/init__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Init_Request__rosidl_typesupport_introspection_c__Init_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hellocm_msgs__srv__Init_Request__init(message_memory);
}

void Init_Request__rosidl_typesupport_introspection_c__Init_Request_fini_function(void * message_memory)
{
  hellocm_msgs__srv__Init_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Init_Request__rosidl_typesupport_introspection_c__Init_Request_message_member_array[1] = {
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs__srv__Init_Request, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Init_Request__rosidl_typesupport_introspection_c__Init_Request_message_members = {
  "hellocm_msgs__srv",  // message namespace
  "Init_Request",  // message name
  1,  // number of fields
  sizeof(hellocm_msgs__srv__Init_Request),
  Init_Request__rosidl_typesupport_introspection_c__Init_Request_message_member_array,  // message members
  Init_Request__rosidl_typesupport_introspection_c__Init_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Init_Request__rosidl_typesupport_introspection_c__Init_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Init_Request__rosidl_typesupport_introspection_c__Init_Request_message_type_support_handle = {
  0,
  &Init_Request__rosidl_typesupport_introspection_c__Init_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hellocm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hellocm_msgs, srv, Init_Request)() {
  if (!Init_Request__rosidl_typesupport_introspection_c__Init_Request_message_type_support_handle.typesupport_identifier) {
    Init_Request__rosidl_typesupport_introspection_c__Init_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Init_Request__rosidl_typesupport_introspection_c__Init_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hellocm_msgs/srv/detail/init__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hellocm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hellocm_msgs/srv/detail/init__functions.h"
// already included above
// #include "hellocm_msgs/srv/detail/init__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Init_Response__rosidl_typesupport_introspection_c__Init_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hellocm_msgs__srv__Init_Response__init(message_memory);
}

void Init_Response__rosidl_typesupport_introspection_c__Init_Response_fini_function(void * message_memory)
{
  hellocm_msgs__srv__Init_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Init_Response__rosidl_typesupport_introspection_c__Init_Response_message_member_array[3] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs__srv__Init_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cycletime",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs__srv__Init_Response, cycletime),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs__srv__Init_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Init_Response__rosidl_typesupport_introspection_c__Init_Response_message_members = {
  "hellocm_msgs__srv",  // message namespace
  "Init_Response",  // message name
  3,  // number of fields
  sizeof(hellocm_msgs__srv__Init_Response),
  Init_Response__rosidl_typesupport_introspection_c__Init_Response_message_member_array,  // message members
  Init_Response__rosidl_typesupport_introspection_c__Init_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Init_Response__rosidl_typesupport_introspection_c__Init_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Init_Response__rosidl_typesupport_introspection_c__Init_Response_message_type_support_handle = {
  0,
  &Init_Response__rosidl_typesupport_introspection_c__Init_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hellocm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hellocm_msgs, srv, Init_Response)() {
  if (!Init_Response__rosidl_typesupport_introspection_c__Init_Response_message_type_support_handle.typesupport_identifier) {
    Init_Response__rosidl_typesupport_introspection_c__Init_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Init_Response__rosidl_typesupport_introspection_c__Init_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "hellocm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "hellocm_msgs/srv/detail/init__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers hellocm_msgs__srv__detail__init__rosidl_typesupport_introspection_c__Init_service_members = {
  "hellocm_msgs__srv",  // service namespace
  "Init",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // hellocm_msgs__srv__detail__init__rosidl_typesupport_introspection_c__Init_Request_message_type_support_handle,
  NULL  // response message
  // hellocm_msgs__srv__detail__init__rosidl_typesupport_introspection_c__Init_Response_message_type_support_handle
};

static rosidl_service_type_support_t hellocm_msgs__srv__detail__init__rosidl_typesupport_introspection_c__Init_service_type_support_handle = {
  0,
  &hellocm_msgs__srv__detail__init__rosidl_typesupport_introspection_c__Init_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hellocm_msgs, srv, Init_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hellocm_msgs, srv, Init_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hellocm_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hellocm_msgs, srv, Init)() {
  if (!hellocm_msgs__srv__detail__init__rosidl_typesupport_introspection_c__Init_service_type_support_handle.typesupport_identifier) {
    hellocm_msgs__srv__detail__init__rosidl_typesupport_introspection_c__Init_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)hellocm_msgs__srv__detail__init__rosidl_typesupport_introspection_c__Init_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hellocm_msgs, srv, Init_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hellocm_msgs, srv, Init_Response)()->data;
  }

  return &hellocm_msgs__srv__detail__init__rosidl_typesupport_introspection_c__Init_service_type_support_handle;
}
