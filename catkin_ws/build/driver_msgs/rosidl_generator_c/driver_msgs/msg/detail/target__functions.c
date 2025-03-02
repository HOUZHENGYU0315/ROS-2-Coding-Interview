// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from driver_msgs:msg/Target.idl
// generated code does not contain a copyright notice
#include "driver_msgs/msg/detail/target__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `target`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
driver_msgs__msg__Target__init(driver_msgs__msg__Target * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    driver_msgs__msg__Target__fini(msg);
    return false;
  }
  // count
  // time
  // target
  if (!geometry_msgs__msg__Vector3__init(&msg->target)) {
    driver_msgs__msg__Target__fini(msg);
    return false;
  }
  return true;
}

void
driver_msgs__msg__Target__fini(driver_msgs__msg__Target * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // count
  // time
  // target
  geometry_msgs__msg__Vector3__fini(&msg->target);
}

bool
driver_msgs__msg__Target__are_equal(const driver_msgs__msg__Target * lhs, const driver_msgs__msg__Target * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // count
  if (lhs->count != rhs->count) {
    return false;
  }
  // time
  if (lhs->time != rhs->time) {
    return false;
  }
  // target
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->target), &(rhs->target)))
  {
    return false;
  }
  return true;
}

bool
driver_msgs__msg__Target__copy(
  const driver_msgs__msg__Target * input,
  driver_msgs__msg__Target * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // count
  output->count = input->count;
  // time
  output->time = input->time;
  // target
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->target), &(output->target)))
  {
    return false;
  }
  return true;
}

driver_msgs__msg__Target *
driver_msgs__msg__Target__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  driver_msgs__msg__Target * msg = (driver_msgs__msg__Target *)allocator.allocate(sizeof(driver_msgs__msg__Target), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(driver_msgs__msg__Target));
  bool success = driver_msgs__msg__Target__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
driver_msgs__msg__Target__destroy(driver_msgs__msg__Target * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    driver_msgs__msg__Target__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
driver_msgs__msg__Target__Sequence__init(driver_msgs__msg__Target__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  driver_msgs__msg__Target * data = NULL;

  if (size) {
    data = (driver_msgs__msg__Target *)allocator.zero_allocate(size, sizeof(driver_msgs__msg__Target), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = driver_msgs__msg__Target__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        driver_msgs__msg__Target__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
driver_msgs__msg__Target__Sequence__fini(driver_msgs__msg__Target__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      driver_msgs__msg__Target__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

driver_msgs__msg__Target__Sequence *
driver_msgs__msg__Target__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  driver_msgs__msg__Target__Sequence * array = (driver_msgs__msg__Target__Sequence *)allocator.allocate(sizeof(driver_msgs__msg__Target__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = driver_msgs__msg__Target__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
driver_msgs__msg__Target__Sequence__destroy(driver_msgs__msg__Target__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    driver_msgs__msg__Target__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
driver_msgs__msg__Target__Sequence__are_equal(const driver_msgs__msg__Target__Sequence * lhs, const driver_msgs__msg__Target__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!driver_msgs__msg__Target__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
driver_msgs__msg__Target__Sequence__copy(
  const driver_msgs__msg__Target__Sequence * input,
  driver_msgs__msg__Target__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(driver_msgs__msg__Target);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    driver_msgs__msg__Target * data =
      (driver_msgs__msg__Target *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!driver_msgs__msg__Target__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          driver_msgs__msg__Target__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!driver_msgs__msg__Target__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
