// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hellocm_msgs:msg/CM2Ext.idl
// generated code does not contain a copyright notice
#include "hellocm_msgs/msg/detail/cm2_ext__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `time`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
hellocm_msgs__msg__CM2Ext__init(hellocm_msgs__msg__CM2Ext * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    hellocm_msgs__msg__CM2Ext__fini(msg);
    return false;
  }
  // time
  if (!builtin_interfaces__msg__Time__init(&msg->time)) {
    hellocm_msgs__msg__CM2Ext__fini(msg);
    return false;
  }
  // cycleno
  // synthdelay
  return true;
}

void
hellocm_msgs__msg__CM2Ext__fini(hellocm_msgs__msg__CM2Ext * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // time
  builtin_interfaces__msg__Time__fini(&msg->time);
  // cycleno
  // synthdelay
}

bool
hellocm_msgs__msg__CM2Ext__are_equal(const hellocm_msgs__msg__CM2Ext * lhs, const hellocm_msgs__msg__CM2Ext * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // time
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->time), &(rhs->time)))
  {
    return false;
  }
  // cycleno
  if (lhs->cycleno != rhs->cycleno) {
    return false;
  }
  // synthdelay
  if (lhs->synthdelay != rhs->synthdelay) {
    return false;
  }
  return true;
}

bool
hellocm_msgs__msg__CM2Ext__copy(
  const hellocm_msgs__msg__CM2Ext * input,
  hellocm_msgs__msg__CM2Ext * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // time
  if (!builtin_interfaces__msg__Time__copy(
      &(input->time), &(output->time)))
  {
    return false;
  }
  // cycleno
  output->cycleno = input->cycleno;
  // synthdelay
  output->synthdelay = input->synthdelay;
  return true;
}

hellocm_msgs__msg__CM2Ext *
hellocm_msgs__msg__CM2Ext__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__msg__CM2Ext * msg = (hellocm_msgs__msg__CM2Ext *)allocator.allocate(sizeof(hellocm_msgs__msg__CM2Ext), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hellocm_msgs__msg__CM2Ext));
  bool success = hellocm_msgs__msg__CM2Ext__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hellocm_msgs__msg__CM2Ext__destroy(hellocm_msgs__msg__CM2Ext * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hellocm_msgs__msg__CM2Ext__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hellocm_msgs__msg__CM2Ext__Sequence__init(hellocm_msgs__msg__CM2Ext__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__msg__CM2Ext * data = NULL;

  if (size) {
    data = (hellocm_msgs__msg__CM2Ext *)allocator.zero_allocate(size, sizeof(hellocm_msgs__msg__CM2Ext), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hellocm_msgs__msg__CM2Ext__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hellocm_msgs__msg__CM2Ext__fini(&data[i - 1]);
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
hellocm_msgs__msg__CM2Ext__Sequence__fini(hellocm_msgs__msg__CM2Ext__Sequence * array)
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
      hellocm_msgs__msg__CM2Ext__fini(&array->data[i]);
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

hellocm_msgs__msg__CM2Ext__Sequence *
hellocm_msgs__msg__CM2Ext__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__msg__CM2Ext__Sequence * array = (hellocm_msgs__msg__CM2Ext__Sequence *)allocator.allocate(sizeof(hellocm_msgs__msg__CM2Ext__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hellocm_msgs__msg__CM2Ext__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hellocm_msgs__msg__CM2Ext__Sequence__destroy(hellocm_msgs__msg__CM2Ext__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hellocm_msgs__msg__CM2Ext__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hellocm_msgs__msg__CM2Ext__Sequence__are_equal(const hellocm_msgs__msg__CM2Ext__Sequence * lhs, const hellocm_msgs__msg__CM2Ext__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hellocm_msgs__msg__CM2Ext__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hellocm_msgs__msg__CM2Ext__Sequence__copy(
  const hellocm_msgs__msg__CM2Ext__Sequence * input,
  hellocm_msgs__msg__CM2Ext__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hellocm_msgs__msg__CM2Ext);
    hellocm_msgs__msg__CM2Ext * data =
      (hellocm_msgs__msg__CM2Ext *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hellocm_msgs__msg__CM2Ext__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          hellocm_msgs__msg__CM2Ext__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hellocm_msgs__msg__CM2Ext__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
