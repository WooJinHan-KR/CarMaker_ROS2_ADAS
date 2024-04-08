// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hellocm_msgs:msg/RadarData.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__MSG__DETAIL__RADAR_DATA__STRUCT_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__RADAR_DATA__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'pointcloud'
#include "sensor_msgs/msg/detail/point_cloud__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hellocm_msgs__msg__RadarData __attribute__((deprecated))
#else
# define DEPRECATED__hellocm_msgs__msg__RadarData __declspec(deprecated)
#endif

namespace hellocm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RadarData_
{
  using Type = RadarData_<ContainerAllocator>;

  explicit RadarData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    pointcloud(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_id = "";
      this->velocity = 0.0;
      this->distance = 0.0;
    }
  }

  explicit RadarData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    frame_id(_alloc),
    pointcloud(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_id = "";
      this->velocity = 0.0;
      this->distance = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _frame_id_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _frame_id_type frame_id;
  using _pointcloud_type =
    sensor_msgs::msg::PointCloud_<ContainerAllocator>;
  _pointcloud_type pointcloud;
  using _velocity_type =
    double;
  _velocity_type velocity;
  using _distance_type =
    double;
  _distance_type distance;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__frame_id(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->frame_id = _arg;
    return *this;
  }
  Type & set__pointcloud(
    const sensor_msgs::msg::PointCloud_<ContainerAllocator> & _arg)
  {
    this->pointcloud = _arg;
    return *this;
  }
  Type & set__velocity(
    const double & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__distance(
    const double & _arg)
  {
    this->distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hellocm_msgs::msg::RadarData_<ContainerAllocator> *;
  using ConstRawPtr =
    const hellocm_msgs::msg::RadarData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hellocm_msgs::msg::RadarData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hellocm_msgs::msg::RadarData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::msg::RadarData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::msg::RadarData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::msg::RadarData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::msg::RadarData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hellocm_msgs::msg::RadarData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hellocm_msgs::msg::RadarData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hellocm_msgs__msg__RadarData
    std::shared_ptr<hellocm_msgs::msg::RadarData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hellocm_msgs__msg__RadarData
    std::shared_ptr<hellocm_msgs::msg::RadarData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RadarData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->frame_id != other.frame_id) {
      return false;
    }
    if (this->pointcloud != other.pointcloud) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const RadarData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RadarData_

// alias to use template instance with default allocator
using RadarData =
  hellocm_msgs::msg::RadarData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__MSG__DETAIL__RADAR_DATA__STRUCT_HPP_
