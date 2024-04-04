// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hellocm_msgs:srv/Init.idl
// generated code does not contain a copyright notice

#ifndef HELLOCM_MSGS__SRV__DETAIL__INIT__STRUCT_HPP_
#define HELLOCM_MSGS__SRV__DETAIL__INIT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__hellocm_msgs__srv__Init_Request __attribute__((deprecated))
#else
# define DEPRECATED__hellocm_msgs__srv__Init_Request __declspec(deprecated)
#endif

namespace hellocm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Init_Request_
{
  using Type = Init_Request_<ContainerAllocator>;

  explicit Init_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
    }
  }

  explicit Init_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
    }
  }

  // field types and members
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hellocm_msgs::srv::Init_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hellocm_msgs::srv::Init_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hellocm_msgs::srv::Init_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hellocm_msgs::srv::Init_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::srv::Init_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::srv::Init_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::srv::Init_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::srv::Init_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hellocm_msgs::srv::Init_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hellocm_msgs::srv::Init_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hellocm_msgs__srv__Init_Request
    std::shared_ptr<hellocm_msgs::srv::Init_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hellocm_msgs__srv__Init_Request
    std::shared_ptr<hellocm_msgs::srv::Init_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Init_Request_ & other) const
  {
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const Init_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Init_Request_

// alias to use template instance with default allocator
using Init_Request =
  hellocm_msgs::srv::Init_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hellocm_msgs


#ifndef _WIN32
# define DEPRECATED__hellocm_msgs__srv__Init_Response __attribute__((deprecated))
#else
# define DEPRECATED__hellocm_msgs__srv__Init_Response __declspec(deprecated)
#endif

namespace hellocm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Init_Response_
{
  using Type = Init_Response_<ContainerAllocator>;

  explicit Init_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->cycletime = 0l;
      this->message = "";
    }
  }

  explicit Init_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->cycletime = 0l;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _cycletime_type =
    int32_t;
  _cycletime_type cycletime;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__cycletime(
    const int32_t & _arg)
  {
    this->cycletime = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hellocm_msgs::srv::Init_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hellocm_msgs::srv::Init_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hellocm_msgs::srv::Init_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hellocm_msgs::srv::Init_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::srv::Init_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::srv::Init_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hellocm_msgs::srv::Init_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hellocm_msgs::srv::Init_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hellocm_msgs::srv::Init_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hellocm_msgs::srv::Init_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hellocm_msgs__srv__Init_Response
    std::shared_ptr<hellocm_msgs::srv::Init_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hellocm_msgs__srv__Init_Response
    std::shared_ptr<hellocm_msgs::srv::Init_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Init_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->cycletime != other.cycletime) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const Init_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Init_Response_

// alias to use template instance with default allocator
using Init_Response =
  hellocm_msgs::srv::Init_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hellocm_msgs

namespace hellocm_msgs
{

namespace srv
{

struct Init
{
  using Request = hellocm_msgs::srv::Init_Request;
  using Response = hellocm_msgs::srv::Init_Response;
};

}  // namespace srv

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__SRV__DETAIL__INIT__STRUCT_HPP_
