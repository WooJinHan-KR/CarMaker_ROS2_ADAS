// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hellocm_msgs:msg/CM2Ext.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__CM2_EXT__BUILDER_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__CM2_EXT__BUILDER_HPP_

#include "hellocm_msgs/msg/detail/cm2_ext__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hellocm_msgs
{

namespace msg
{

namespace builder
{

class Init_CM2Ext_synthdelay
{
public:
  explicit Init_CM2Ext_synthdelay(::hellocm_msgs::msg::CM2Ext & msg)
  : msg_(msg)
  {}
  ::hellocm_msgs::msg::CM2Ext synthdelay(::hellocm_msgs::msg::CM2Ext::_synthdelay_type arg)
  {
    msg_.synthdelay = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hellocm_msgs::msg::CM2Ext msg_;
};

class Init_CM2Ext_cycleno
{
public:
  explicit Init_CM2Ext_cycleno(::hellocm_msgs::msg::CM2Ext & msg)
  : msg_(msg)
  {}
  Init_CM2Ext_synthdelay cycleno(::hellocm_msgs::msg::CM2Ext::_cycleno_type arg)
  {
    msg_.cycleno = std::move(arg);
    return Init_CM2Ext_synthdelay(msg_);
  }

private:
  ::hellocm_msgs::msg::CM2Ext msg_;
};

class Init_CM2Ext_time
{
public:
  explicit Init_CM2Ext_time(::hellocm_msgs::msg::CM2Ext & msg)
  : msg_(msg)
  {}
  Init_CM2Ext_cycleno time(::hellocm_msgs::msg::CM2Ext::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_CM2Ext_cycleno(msg_);
  }

private:
  ::hellocm_msgs::msg::CM2Ext msg_;
};

class Init_CM2Ext_header
{
public:
  Init_CM2Ext_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CM2Ext_time header(::hellocm_msgs::msg::CM2Ext::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_CM2Ext_time(msg_);
  }

private:
  ::hellocm_msgs::msg::CM2Ext msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hellocm_msgs::msg::CM2Ext>()
{
  return hellocm_msgs::msg::builder::Init_CM2Ext_header();
}

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__CM2_EXT__BUILDER_HPP_
