// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hellocm_msgs:msg/RadarData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hellocm_msgs/msg/detail/radar_data__rosidl_typesupport_introspection_c.h"
#include "hellocm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hellocm_msgs/msg/detail/radar_data__functions.h"
#include "hellocm_msgs/msg/detail/radar_data__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `frame_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `pointcloud`
#include "sensor_msgs/msg/point_cloud.h"
// Member `pointcloud`
#include "sensor_msgs/msg/detail/point_cloud__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RadarData__rosidl_typesupport_introspection_c__RadarData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hellocm_msgs__msg__RadarData__init(message_memory);
}

void RadarData__rosidl_typesupport_introspection_c__RadarData_fini_function(void * message_memory)
{
  hellocm_msgs__msg__RadarData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember RadarData__rosidl_typesupport_introspection_c__RadarData_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs__msg__RadarData, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs__msg__RadarData, frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pointcloud",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs__msg__RadarData, pointcloud),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs__msg__RadarData, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs__msg__RadarData, distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers RadarData__rosidl_typesupport_introspection_c__RadarData_message_members = {
  "hellocm_msgs__msg",  // message namespace
  "RadarData",  // message name
  5,  // number of fields
  sizeof(hellocm_msgs__msg__RadarData),
  RadarData__rosidl_typesupport_introspection_c__RadarData_message_member_array,  // message members
  RadarData__rosidl_typesupport_introspection_c__RadarData_init_function,  // function to initialize message memory (memory has to be allocated)
  RadarData__rosidl_typesupport_introspection_c__RadarData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t RadarData__rosidl_typesupport_introspection_c__RadarData_message_type_support_handle = {
  0,
  &RadarData__rosidl_typesupport_introspection_c__RadarData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hellocm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hellocm_msgs, msg, RadarData)() {
  RadarData__rosidl_typesupport_introspection_c__RadarData_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  RadarData__rosidl_typesupport_introspection_c__RadarData_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, PointCloud)();
  if (!RadarData__rosidl_typesupport_introspection_c__RadarData_message_type_support_handle.typesupport_identifier) {
    RadarData__rosidl_typesupport_introspection_c__RadarData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &RadarData__rosidl_typesupport_introspection_c__RadarData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
