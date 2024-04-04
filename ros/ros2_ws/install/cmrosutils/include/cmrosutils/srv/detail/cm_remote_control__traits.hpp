// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cmrosutils:srv/CMRemoteControl.idl
// generated code does not contain a copyright notice

#ifndef CMROSUTILS__SRV__DETAIL__CM_REMOTE_CONTROL__TRAITS_HPP_
#define CMROSUTILS__SRV__DETAIL__CM_REMOTE_CONTROL__TRAITS_HPP_

#include "cmrosutils/srv/detail/cm_remote_control__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cmrosutils::srv::CMRemoteControl_Request>()
{
  return "cmrosutils::srv::CMRemoteControl_Request";
}

template<>
inline const char * name<cmrosutils::srv::CMRemoteControl_Request>()
{
  return "cmrosutils/srv/CMRemoteControl_Request";
}

template<>
struct has_fixed_size<cmrosutils::srv::CMRemoteControl_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cmrosutils::srv::CMRemoteControl_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cmrosutils::srv::CMRemoteControl_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cmrosutils::srv::CMRemoteControl_Response>()
{
  return "cmrosutils::srv::CMRemoteControl_Response";
}

template<>
inline const char * name<cmrosutils::srv::CMRemoteControl_Response>()
{
  return "cmrosutils/srv/CMRemoteControl_Response";
}

template<>
struct has_fixed_size<cmrosutils::srv::CMRemoteControl_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cmrosutils::srv::CMRemoteControl_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cmrosutils::srv::CMRemoteControl_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cmrosutils::srv::CMRemoteControl>()
{
  return "cmrosutils::srv::CMRemoteControl";
}

template<>
inline const char * name<cmrosutils::srv::CMRemoteControl>()
{
  return "cmrosutils/srv/CMRemoteControl";
}

template<>
struct has_fixed_size<cmrosutils::srv::CMRemoteControl>
  : std::integral_constant<
    bool,
    has_fixed_size<cmrosutils::srv::CMRemoteControl_Request>::value &&
    has_fixed_size<cmrosutils::srv::CMRemoteControl_Response>::value
  >
{
};

template<>
struct has_bounded_size<cmrosutils::srv::CMRemoteControl>
  : std::integral_constant<
    bool,
    has_bounded_size<cmrosutils::srv::CMRemoteControl_Request>::value &&
    has_bounded_size<cmrosutils::srv::CMRemoteControl_Response>::value
  >
{
};

template<>
struct is_service<cmrosutils::srv::CMRemoteControl>
  : std::true_type
{
};

template<>
struct is_service_request<cmrosutils::srv::CMRemoteControl_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cmrosutils::srv::CMRemoteControl_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CMROSUTILS__SRV__DETAIL__CM_REMOTE_CONTROL__TRAITS_HPP_
