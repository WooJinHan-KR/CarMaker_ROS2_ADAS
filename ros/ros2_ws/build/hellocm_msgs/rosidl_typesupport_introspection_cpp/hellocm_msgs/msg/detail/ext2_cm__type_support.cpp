// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from hellocm_msgs:msg/Ext2CM.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "hellocm_msgs/msg/detail/ext2_cm__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace hellocm_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Ext2CM_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) hellocm_msgs::msg::Ext2CM(_init);
}

void Ext2CM_fini_function(void * message_memory)
{
  auto typed_message = static_cast<hellocm_msgs::msg::Ext2CM *>(message_memory);
  typed_message->~Ext2CM();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Ext2CM_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs::msg::Ext2CM, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs::msg::Ext2CM, time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "cycleno",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hellocm_msgs::msg::Ext2CM, cycleno),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Ext2CM_message_members = {
  "hellocm_msgs::msg",  // message namespace
  "Ext2CM",  // message name
  3,  // number of fields
  sizeof(hellocm_msgs::msg::Ext2CM),
  Ext2CM_message_member_array,  // message members
  Ext2CM_init_function,  // function to initialize message memory (memory has to be allocated)
  Ext2CM_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Ext2CM_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Ext2CM_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace hellocm_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<hellocm_msgs::msg::Ext2CM>()
{
  return &::hellocm_msgs::msg::rosidl_typesupport_introspection_cpp::Ext2CM_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, hellocm_msgs, msg, Ext2CM)() {
  return &::hellocm_msgs::msg::rosidl_typesupport_introspection_cpp::Ext2CM_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
