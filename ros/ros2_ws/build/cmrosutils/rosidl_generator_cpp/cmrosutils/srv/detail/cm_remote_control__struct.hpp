// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cmrosutils:srv/CMRemoteControl.idl
// generated code does not contain a copyright notice

#ifndef CMROSUTILS__SRV__DETAIL__CM_REMOTE_CONTROL__STRUCT_HPP_
#define CMROSUTILS__SRV__DETAIL__CM_REMOTE_CONTROL__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__cmrosutils__srv__CMRemoteControl_Request __attribute__((deprecated))
#else
# define DEPRECATED__cmrosutils__srv__CMRemoteControl_Request __declspec(deprecated)
#endif

namespace cmrosutils
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CMRemoteControl_Request_
{
  using Type = CMRemoteControl_Request_<ContainerAllocator>;

  explicit CMRemoteControl_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = "";
      this->msg = "";
      this->data = "";
    }
  }

  explicit CMRemoteControl_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : type(_alloc),
    msg(_alloc),
    data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = "";
      this->msg = "";
      this->data = "";
    }
  }

  // field types and members
  using _type_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _type_type type;
  using _msg_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _msg_type msg;
  using _data_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__type(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__msg(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->msg = _arg;
    return *this;
  }
  Type & set__data(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cmrosutils::srv::CMRemoteControl_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cmrosutils::srv::CMRemoteControl_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cmrosutils::srv::CMRemoteControl_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cmrosutils::srv::CMRemoteControl_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cmrosutils::srv::CMRemoteControl_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cmrosutils::srv::CMRemoteControl_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cmrosutils::srv::CMRemoteControl_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cmrosutils::srv::CMRemoteControl_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cmrosutils::srv::CMRemoteControl_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cmrosutils::srv::CMRemoteControl_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cmrosutils__srv__CMRemoteControl_Request
    std::shared_ptr<cmrosutils::srv::CMRemoteControl_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cmrosutils__srv__CMRemoteControl_Request
    std::shared_ptr<cmrosutils::srv::CMRemoteControl_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CMRemoteControl_Request_ & other) const
  {
    if (this->type != other.type) {
      return false;
    }
    if (this->msg != other.msg) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const CMRemoteControl_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CMRemoteControl_Request_

// alias to use template instance with default allocator
using CMRemoteControl_Request =
  cmrosutils::srv::CMRemoteControl_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cmrosutils


#ifndef _WIN32
# define DEPRECATED__cmrosutils__srv__CMRemoteControl_Response __attribute__((deprecated))
#else
# define DEPRECATED__cmrosutils__srv__CMRemoteControl_Response __declspec(deprecated)
#endif

namespace cmrosutils
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CMRemoteControl_Response_
{
  using Type = CMRemoteControl_Response_<ContainerAllocator>;

  explicit CMRemoteControl_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->res = 0l;
      this->msg = "";
    }
  }

  explicit CMRemoteControl_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->res = 0l;
      this->msg = "";
    }
  }

  // field types and members
  using _res_type =
    int32_t;
  _res_type res;
  using _msg_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _msg_type msg;

  // setters for named parameter idiom
  Type & set__res(
    const int32_t & _arg)
  {
    this->res = _arg;
    return *this;
  }
  Type & set__msg(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->msg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cmrosutils::srv::CMRemoteControl_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cmrosutils::srv::CMRemoteControl_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cmrosutils::srv::CMRemoteControl_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cmrosutils::srv::CMRemoteControl_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cmrosutils::srv::CMRemoteControl_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cmrosutils::srv::CMRemoteControl_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cmrosutils::srv::CMRemoteControl_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cmrosutils::srv::CMRemoteControl_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cmrosutils::srv::CMRemoteControl_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cmrosutils::srv::CMRemoteControl_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cmrosutils__srv__CMRemoteControl_Response
    std::shared_ptr<cmrosutils::srv::CMRemoteControl_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cmrosutils__srv__CMRemoteControl_Response
    std::shared_ptr<cmrosutils::srv::CMRemoteControl_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CMRemoteControl_Response_ & other) const
  {
    if (this->res != other.res) {
      return false;
    }
    if (this->msg != other.msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const CMRemoteControl_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CMRemoteControl_Response_

// alias to use template instance with default allocator
using CMRemoteControl_Response =
  cmrosutils::srv::CMRemoteControl_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cmrosutils

namespace cmrosutils
{

namespace srv
{

struct CMRemoteControl
{
  using Request = cmrosutils::srv::CMRemoteControl_Request;
  using Response = cmrosutils::srv::CMRemoteControl_Response;
};

}  // namespace srv

}  // namespace cmrosutils

#endif  // CMROSUTILS__SRV__DETAIL__CM_REMOTE_CONTROL__STRUCT_HPP_
