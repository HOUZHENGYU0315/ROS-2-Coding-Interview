// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from driver_msgs:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef DRIVER_MSGS__MSG__DETAIL__TARGET__BUILDER_HPP_
#define DRIVER_MSGS__MSG__DETAIL__TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "driver_msgs/msg/detail/target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace driver_msgs
{

namespace msg
{

namespace builder
{

class Init_Target_target
{
public:
  explicit Init_Target_target(::driver_msgs::msg::Target & msg)
  : msg_(msg)
  {}
  ::driver_msgs::msg::Target target(::driver_msgs::msg::Target::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::driver_msgs::msg::Target msg_;
};

class Init_Target_time
{
public:
  explicit Init_Target_time(::driver_msgs::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_target time(::driver_msgs::msg::Target::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_Target_target(msg_);
  }

private:
  ::driver_msgs::msg::Target msg_;
};

class Init_Target_count
{
public:
  explicit Init_Target_count(::driver_msgs::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_time count(::driver_msgs::msg::Target::_count_type arg)
  {
    msg_.count = std::move(arg);
    return Init_Target_time(msg_);
  }

private:
  ::driver_msgs::msg::Target msg_;
};

class Init_Target_name
{
public:
  Init_Target_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Target_count name(::driver_msgs::msg::Target::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Target_count(msg_);
  }

private:
  ::driver_msgs::msg::Target msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::driver_msgs::msg::Target>()
{
  return driver_msgs::msg::builder::Init_Target_name();
}

}  // namespace driver_msgs

#endif  // DRIVER_MSGS__MSG__DETAIL__TARGET__BUILDER_HPP_
