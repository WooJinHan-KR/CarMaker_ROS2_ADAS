// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hellocm_msgs:msg/TrafficLightStatus.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__TRAFFIC_LIGHT_STATUS__TRAITS_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__TRAFFIC_LIGHT_STATUS__TRAITS_HPP_

#include "hellocm_msgs/msg/detail/traffic_light_status__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "hellocm_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hellocm_msgs::msg::TrafficLightStatus>()
{
  return "hellocm_msgs::msg::TrafficLightStatus";
}

template<>
inline const char * name<hellocm_msgs::msg::TrafficLightStatus>()
{
  return "hellocm_msgs/msg/TrafficLightStatus";
}

template<>
struct has_fixed_size<hellocm_msgs::msg::TrafficLightStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hellocm_msgs::msg::TrafficLightStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hellocm_msgs::msg::TrafficLightStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HELLOCM_MSGS__MSG__DETAIL__TRAFFIC_LIGHT_STATUS__TRAITS_HPP_
