// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hellocm_msgs:msg/TrafficLightStatus.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__TRAFFIC_LIGHT_STATUS__STRUCT_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__TRAFFIC_LIGHT_STATUS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "hellocm_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hellocm_msgs__msg__TrafficLightStatus __attribute__((deprecated))
#else
# define DEPRECATED__hellocm_msgs__msg__TrafficLightStatus __declspec(deprecated)
#endif

namespace hellocm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TrafficLightStatus_
{
  using Type = TrafficLightStatus_<ContainerAllocator>;

  explicit TrafficLightStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->trafficlightindex = "";
      this->trafficlightype = 0l;
      this->trafficlightstatus = 0l;
    }
  }

  explicit TrafficLightStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    trafficlightindex(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->trafficlightindex = "";
      this->trafficlightype = 0l;
      this->trafficlightstatus = 0l;
    }
  }

  // field types and members
  using _header_type =
    hellocm_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _trafficlightindex_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _trafficlightindex_type trafficlightindex;
  using _trafficlightype_type =
    int32_t;
  _trafficlightype_type trafficlightype;
  using _trafficlightstatus_type =
    int32_t;
  _trafficlightstatus_type trafficlightstatus;

  // setters for named parameter idiom
  Type & set__header(
    const hellocm_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__trafficlightindex(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->trafficlightindex = _arg;
    return *this;
  }
  Type & set__trafficlightype(
    const int32_t & _arg)
  {
    this->trafficlightype = _arg;
    return *this;
  }
  Type & set__trafficlightstatus(
    const int32_t & _arg)
  {
    this->trafficlightstatus = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hellocm_msgs::msg::TrafficLightStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const hellocm_msgs::msg::TrafficLightStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hellocm_msgs::msg::TrafficLightStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hellocm_msgs::msg::TrafficLightStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::msg::TrafficLightStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::msg::TrafficLightStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::msg::TrafficLightStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::msg::TrafficLightStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hellocm_msgs::msg::TrafficLightStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hellocm_msgs::msg::TrafficLightStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hellocm_msgs__msg__TrafficLightStatus
    std::shared_ptr<hellocm_msgs::msg::TrafficLightStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hellocm_msgs__msg__TrafficLightStatus
    std::shared_ptr<hellocm_msgs::msg::TrafficLightStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrafficLightStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->trafficlightindex != other.trafficlightindex) {
      return false;
    }
    if (this->trafficlightype != other.trafficlightype) {
      return false;
    }
    if (this->trafficlightstatus != other.trafficlightstatus) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrafficLightStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrafficLightStatus_

// alias to use template instance with default allocator
using TrafficLightStatus =
  hellocm_msgs::msg::TrafficLightStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__TRAFFIC_LIGHT_STATUS__STRUCT_HPP_
