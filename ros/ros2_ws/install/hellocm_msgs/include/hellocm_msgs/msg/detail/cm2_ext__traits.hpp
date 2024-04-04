// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hellocm_msgs:msg/CM2Ext.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__CM2_EXT__TRAITS_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__CM2_EXT__TRAITS_HPP_

#include "hellocm_msgs/msg/detail/cm2_ext__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'time'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hellocm_msgs::msg::CM2Ext>()
{
  return "hellocm_msgs::msg::CM2Ext";
}

template<>
inline const char * name<hellocm_msgs::msg::CM2Ext>()
{
  return "hellocm_msgs/msg/CM2Ext";
}

template<>
struct has_fixed_size<hellocm_msgs::msg::CM2Ext>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<hellocm_msgs::msg::CM2Ext>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<hellocm_msgs::msg::CM2Ext>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HELLOCM_MSGS__MSG__DETAIL__CM2_EXT__TRAITS_HPP_
