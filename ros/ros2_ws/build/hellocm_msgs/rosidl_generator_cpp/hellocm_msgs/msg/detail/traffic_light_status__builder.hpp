// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hellocm_msgs:msg/TrafficLightStatus.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__TRAFFIC_LIGHT_STATUS__BUILDER_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__TRAFFIC_LIGHT_STATUS__BUILDER_HPP_

#include "hellocm_msgs/msg/detail/traffic_light_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hellocm_msgs
{

namespace msg
{

namespace builder
{

class Init_TrafficLightStatus_trafficlightstatus
{
public:
  explicit Init_TrafficLightStatus_trafficlightstatus(::hellocm_msgs::msg::TrafficLightStatus & msg)
  : msg_(msg)
  {}
  ::hellocm_msgs::msg::TrafficLightStatus trafficlightstatus(::hellocm_msgs::msg::TrafficLightStatus::_trafficlightstatus_type arg)
  {
    msg_.trafficlightstatus = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hellocm_msgs::msg::TrafficLightStatus msg_;
};

class Init_TrafficLightStatus_trafficlightype
{
public:
  explicit Init_TrafficLightStatus_trafficlightype(::hellocm_msgs::msg::TrafficLightStatus & msg)
  : msg_(msg)
  {}
  Init_TrafficLightStatus_trafficlightstatus trafficlightype(::hellocm_msgs::msg::TrafficLightStatus::_trafficlightype_type arg)
  {
    msg_.trafficlightype = std::move(arg);
    return Init_TrafficLightStatus_trafficlightstatus(msg_);
  }

private:
  ::hellocm_msgs::msg::TrafficLightStatus msg_;
};

class Init_TrafficLightStatus_trafficlightindex
{
public:
  explicit Init_TrafficLightStatus_trafficlightindex(::hellocm_msgs::msg::TrafficLightStatus & msg)
  : msg_(msg)
  {}
  Init_TrafficLightStatus_trafficlightype trafficlightindex(::hellocm_msgs::msg::TrafficLightStatus::_trafficlightindex_type arg)
  {
    msg_.trafficlightindex = std::move(arg);
    return Init_TrafficLightStatus_trafficlightype(msg_);
  }

private:
  ::hellocm_msgs::msg::TrafficLightStatus msg_;
};

class Init_TrafficLightStatus_header
{
public:
  Init_TrafficLightStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrafficLightStatus_trafficlightindex header(::hellocm_msgs::msg::TrafficLightStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TrafficLightStatus_trafficlightindex(msg_);
  }

private:
  ::hellocm_msgs::msg::TrafficLightStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hellocm_msgs::msg::TrafficLightStatus>()
{
  return hellocm_msgs::msg::builder::Init_TrafficLightStatus_header();
}

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__TRAFFIC_LIGHT_STATUS__BUILDER_HPP_
