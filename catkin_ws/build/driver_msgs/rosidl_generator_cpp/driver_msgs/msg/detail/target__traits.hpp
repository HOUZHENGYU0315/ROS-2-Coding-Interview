// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from driver_msgs:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef DRIVER_MSGS__MSG__DETAIL__TARGET__TRAITS_HPP_
#define DRIVER_MSGS__MSG__DETAIL__TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "driver_msgs/msg/detail/target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'target'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace driver_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Target & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: count
  {
    out << "count: ";
    rosidl_generator_traits::value_to_yaml(msg.count, out);
    out << ", ";
  }

  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << ", ";
  }

  // member: target
  {
    out << "target: ";
    to_flow_style_yaml(msg.target, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Target & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "count: ";
    rosidl_generator_traits::value_to_yaml(msg.count, out);
    out << "\n";
  }

  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }

  // member: target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target:\n";
    to_block_style_yaml(msg.target, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Target & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace driver_msgs

namespace rosidl_generator_traits
{

[[deprecated("use driver_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const driver_msgs::msg::Target & msg,
  std::ostream & out, size_t indentation = 0)
{
  driver_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use driver_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const driver_msgs::msg::Target & msg)
{
  return driver_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<driver_msgs::msg::Target>()
{
  return "driver_msgs::msg::Target";
}

template<>
inline const char * name<driver_msgs::msg::Target>()
{
  return "driver_msgs/msg/Target";
}

template<>
struct has_fixed_size<driver_msgs::msg::Target>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<driver_msgs::msg::Target>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<driver_msgs::msg::Target>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DRIVER_MSGS__MSG__DETAIL__TARGET__TRAITS_HPP_
