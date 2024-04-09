// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hellocm_msgs:msg/RadarData.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__RADAR_DATA__BUILDER_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__RADAR_DATA__BUILDER_HPP_

#include "hellocm_msgs/msg/detail/radar_data__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hellocm_msgs
{

namespace msg
{

namespace builder
{

class Init_RadarData_distance
{
public:
  explicit Init_RadarData_distance(::hellocm_msgs::msg::RadarData & msg)
  : msg_(msg)
  {}
  ::hellocm_msgs::msg::RadarData distance(::hellocm_msgs::msg::RadarData::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hellocm_msgs::msg::RadarData msg_;
};

class Init_RadarData_velocity
{
public:
  explicit Init_RadarData_velocity(::hellocm_msgs::msg::RadarData & msg)
  : msg_(msg)
  {}
  Init_RadarData_distance velocity(::hellocm_msgs::msg::RadarData::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_RadarData_distance(msg_);
  }

private:
  ::hellocm_msgs::msg::RadarData msg_;
};

class Init_RadarData_pointcloud2
{
public:
  explicit Init_RadarData_pointcloud2(::hellocm_msgs::msg::RadarData & msg)
  : msg_(msg)
  {}
  Init_RadarData_velocity pointcloud2(::hellocm_msgs::msg::RadarData::_pointcloud2_type arg)
  {
    msg_.pointcloud2 = std::move(arg);
    return Init_RadarData_velocity(msg_);
  }

private:
  ::hellocm_msgs::msg::RadarData msg_;
};

class Init_RadarData_frame_id
{
public:
  explicit Init_RadarData_frame_id(::hellocm_msgs::msg::RadarData & msg)
  : msg_(msg)
  {}
  Init_RadarData_pointcloud2 frame_id(::hellocm_msgs::msg::RadarData::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return Init_RadarData_pointcloud2(msg_);
  }

private:
  ::hellocm_msgs::msg::RadarData msg_;
};

class Init_RadarData_header
{
public:
  Init_RadarData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RadarData_frame_id header(::hellocm_msgs::msg::RadarData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RadarData_frame_id(msg_);
  }

private:
  ::hellocm_msgs::msg::RadarData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hellocm_msgs::msg::RadarData>()
{
  return hellocm_msgs::msg::builder::Init_RadarData_header();
}

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__RADAR_DATA__BUILDER_HPP_
