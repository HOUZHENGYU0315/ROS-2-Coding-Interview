// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from driver_msgs:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef DRIVER_MSGS__MSG__DETAIL__TARGET__STRUCT_H_
#define DRIVER_MSGS__MSG__DETAIL__TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'target'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/Target in the package driver_msgs.
typedef struct driver_msgs__msg__Target
{
  rosidl_runtime_c__String name;
  uint64_t count;
  double time;
  geometry_msgs__msg__Vector3 target;
} driver_msgs__msg__Target;

// Struct for a sequence of driver_msgs__msg__Target.
typedef struct driver_msgs__msg__Target__Sequence
{
  driver_msgs__msg__Target * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} driver_msgs__msg__Target__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRIVER_MSGS__MSG__DETAIL__TARGET__STRUCT_H_
