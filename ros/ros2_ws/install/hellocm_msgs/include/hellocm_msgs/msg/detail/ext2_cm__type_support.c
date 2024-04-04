// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hellocm_msgs:msg/Ext2CM.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hellocm_msgs/msg/detail/ext2_cm__rosidl_typesupport_introspection_c.h"
#include "hellocm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hellocm_msgs/msg/detail/ext2_cm__functions.h"
#include "hellocm_msgs/msg/detail/ext2_cm__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `time`
#include "builtin_interfaces/msg/time.h"
// Member `time`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Ext2CM__rosidl_typesupport_introspection_c__Ext2CM_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hellocm_msgs__msg__Ext2CM__init(message_memory);
}

void Ext2CM__rosidl_typesupport_introspection_c__Ext2CM_fini_function(void * message_memory)
{
  hellocm_msgs__msg__Ext2CM__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Ext2CM__rosidl_typesupport_introspection_c__Ext2CM_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs__msg__Ext2CM, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs__msg__Ext2CM, time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cycleno",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs__msg__Ext2CM, cycleno),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Ext2CM__rosidl_typesupport_introspection_c__Ext2CM_message_members = {
  "hellocm_msgs__msg",  // message namespace
  "Ext2CM",  // message name
  3,  // number of fields
  sizeof(hellocm_msgs__msg__Ext2CM),
  Ext2CM__rosidl_typesupport_introspection_c__Ext2CM_message_member_array,  // message members
  Ext2CM__rosidl_typesupport_introspection_c__Ext2CM_init_function,  // function to initialize message memory (memory has to be allocated)
  Ext2CM__rosidl_typesupport_introspection_c__Ext2CM_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Ext2CM__rosidl_typesupport_introspection_c__Ext2CM_message_type_support_handle = {
  0,
  &Ext2CM__rosidl_typesupport_introspection_c__Ext2CM_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hellocm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hellocm_msgs, msg, Ext2CM)() {
  Ext2CM__rosidl_typesupport_introspection_c__Ext2CM_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  Ext2CM__rosidl_typesupport_introspection_c__Ext2CM_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!Ext2CM__rosidl_typesupport_introspection_c__Ext2CM_message_type_support_handle.typesupport_identifier) {
    Ext2CM__rosidl_typesupport_introspection_c__Ext2CM_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Ext2CM__rosidl_typesupport_introspection_c__Ext2CM_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
