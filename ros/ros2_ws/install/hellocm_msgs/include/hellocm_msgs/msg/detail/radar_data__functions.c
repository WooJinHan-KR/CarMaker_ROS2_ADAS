// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hellocm_msgs:msg/RadarData.idl
// generated code does not contain a copyright notice
#include "hellocm_msgs/msg/detail/radar_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `frame_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `pointcloud2`
#include "sensor_msgs/msg/detail/point_cloud2__functions.h"
// Member `velocity`
// Member `distance`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
hellocm_msgs__msg__RadarData__init(hellocm_msgs__msg__RadarData * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    hellocm_msgs__msg__RadarData__fini(msg);
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__init(&msg->frame_id)) {
    hellocm_msgs__msg__RadarData__fini(msg);
    return false;
  }
  // pointcloud2
  if (!sensor_msgs__msg__PointCloud2__init(&msg->pointcloud2)) {
    hellocm_msgs__msg__RadarData__fini(msg);
    return false;
  }
  // velocity
  if (!rosidl_runtime_c__double__Sequence__init(&msg->velocity, 0)) {
    hellocm_msgs__msg__RadarData__fini(msg);
    return false;
  }
  // distance
  if (!rosidl_runtime_c__double__Sequence__init(&msg->distance, 0)) {
    hellocm_msgs__msg__RadarData__fini(msg);
    return false;
  }
  return true;
}

void
hellocm_msgs__msg__RadarData__fini(hellocm_msgs__msg__RadarData * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // frame_id
  rosidl_runtime_c__String__fini(&msg->frame_id);
  // pointcloud2
  sensor_msgs__msg__PointCloud2__fini(&msg->pointcloud2);
  // velocity
  rosidl_runtime_c__double__Sequence__fini(&msg->velocity);
  // distance
  rosidl_runtime_c__double__Sequence__fini(&msg->distance);
}

bool
hellocm_msgs__msg__RadarData__are_equal(const hellocm_msgs__msg__RadarData * lhs, const hellocm_msgs__msg__RadarData * rhs)
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
  // frame_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->frame_id), &(rhs->frame_id)))
  {
    return false;
  }
  // pointcloud2
  if (!sensor_msgs__msg__PointCloud2__are_equal(
      &(lhs->pointcloud2), &(rhs->pointcloud2)))
  {
    return false;
  }
  // velocity
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->velocity), &(rhs->velocity)))
  {
    return false;
  }
  // distance
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->distance), &(rhs->distance)))
  {
    return false;
  }
  return true;
}

bool
hellocm_msgs__msg__RadarData__copy(
  const hellocm_msgs__msg__RadarData * input,
  hellocm_msgs__msg__RadarData * output)
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
  // frame_id
  if (!rosidl_runtime_c__String__copy(
      &(input->frame_id), &(output->frame_id)))
  {
    return false;
  }
  // pointcloud2
  if (!sensor_msgs__msg__PointCloud2__copy(
      &(input->pointcloud2), &(output->pointcloud2)))
  {
    return false;
  }
  // velocity
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->velocity), &(output->velocity)))
  {
    return false;
  }
  // distance
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->distance), &(output->distance)))
  {
    return false;
  }
  return true;
}

hellocm_msgs__msg__RadarData *
hellocm_msgs__msg__RadarData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__msg__RadarData * msg = (hellocm_msgs__msg__RadarData *)allocator.allocate(sizeof(hellocm_msgs__msg__RadarData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hellocm_msgs__msg__RadarData));
  bool success = hellocm_msgs__msg__RadarData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hellocm_msgs__msg__RadarData__destroy(hellocm_msgs__msg__RadarData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hellocm_msgs__msg__RadarData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hellocm_msgs__msg__RadarData__Sequence__init(hellocm_msgs__msg__RadarData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__msg__RadarData * data = NULL;

  if (size) {
    data = (hellocm_msgs__msg__RadarData *)allocator.zero_allocate(size, sizeof(hellocm_msgs__msg__RadarData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hellocm_msgs__msg__RadarData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hellocm_msgs__msg__RadarData__fini(&data[i - 1]);
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
hellocm_msgs__msg__RadarData__Sequence__fini(hellocm_msgs__msg__RadarData__Sequence * array)
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
      hellocm_msgs__msg__RadarData__fini(&array->data[i]);
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

hellocm_msgs__msg__RadarData__Sequence *
hellocm_msgs__msg__RadarData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__msg__RadarData__Sequence * array = (hellocm_msgs__msg__RadarData__Sequence *)allocator.allocate(sizeof(hellocm_msgs__msg__RadarData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hellocm_msgs__msg__RadarData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hellocm_msgs__msg__RadarData__Sequence__destroy(hellocm_msgs__msg__RadarData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hellocm_msgs__msg__RadarData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hellocm_msgs__msg__RadarData__Sequence__are_equal(const hellocm_msgs__msg__RadarData__Sequence * lhs, const hellocm_msgs__msg__RadarData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hellocm_msgs__msg__RadarData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hellocm_msgs__msg__RadarData__Sequence__copy(
  const hellocm_msgs__msg__RadarData__Sequence * input,
  hellocm_msgs__msg__RadarData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hellocm_msgs__msg__RadarData);
    hellocm_msgs__msg__RadarData * data =
      (hellocm_msgs__msg__RadarData *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hellocm_msgs__msg__RadarData__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          hellocm_msgs__msg__RadarData__fini(&data[i]);
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
    if (!hellocm_msgs__msg__RadarData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
