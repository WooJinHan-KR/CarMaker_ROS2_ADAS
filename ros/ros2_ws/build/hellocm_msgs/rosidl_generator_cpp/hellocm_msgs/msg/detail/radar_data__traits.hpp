// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hellocm_msgs:msg/RadarData.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__RADAR_DATA__TRAITS_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__RADAR_DATA__TRAITS_HPP_

#include "hellocm_msgs/msg/detail/radar_data__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pointcloud'
#include "sensor_msgs/msg/detail/point_cloud__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hellocm_msgs::msg::RadarData>()
{
  return "hellocm_msgs::msg::RadarData";
}

template<>
inline const char * name<hellocm_msgs::msg::RadarData>()
{
  return "hellocm_msgs/msg/RadarData";
}

template<>
struct has_fixed_size<hellocm_msgs::msg::RadarData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hellocm_msgs::msg::RadarData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hellocm_msgs::msg::RadarData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HELLOCM_MSGS__MSG__DETAIL__RADAR_DATA__TRAITS_HPP_
