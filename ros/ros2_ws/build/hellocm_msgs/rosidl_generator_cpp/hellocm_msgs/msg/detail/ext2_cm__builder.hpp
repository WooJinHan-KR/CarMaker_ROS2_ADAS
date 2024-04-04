// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hellocm_msgs:msg/Ext2CM.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__EXT2_CM__BUILDER_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__EXT2_CM__BUILDER_HPP_

#include "hellocm_msgs/msg/detail/ext2_cm__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hellocm_msgs
{

namespace msg
{

namespace builder
{

class Init_Ext2CM_cycleno
{
public:
  explicit Init_Ext2CM_cycleno(::hellocm_msgs::msg::Ext2CM & msg)
  : msg_(msg)
  {}
  ::hellocm_msgs::msg::Ext2CM cycleno(::hellocm_msgs::msg::Ext2CM::_cycleno_type arg)
  {
    msg_.cycleno = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hellocm_msgs::msg::Ext2CM msg_;
};

class Init_Ext2CM_time
{
public:
  explicit Init_Ext2CM_time(::hellocm_msgs::msg::Ext2CM & msg)
  : msg_(msg)
  {}
  Init_Ext2CM_cycleno time(::hellocm_msgs::msg::Ext2CM::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_Ext2CM_cycleno(msg_);
  }

private:
  ::hellocm_msgs::msg::Ext2CM msg_;
};

class Init_Ext2CM_header
{
public:
  Init_Ext2CM_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Ext2CM_time header(::hellocm_msgs::msg::Ext2CM::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Ext2CM_time(msg_);
  }

private:
  ::hellocm_msgs::msg::Ext2CM msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hellocm_msgs::msg::Ext2CM>()
{
  return hellocm_msgs::msg::builder::Init_Ext2CM_header();
}

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__EXT2_CM__BUILDER_HPP_
