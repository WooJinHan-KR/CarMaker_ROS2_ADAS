cmake_minimum_required(VERSION 3.5)
project(planning)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(
  include
  ${cmrosutils_INCLUDE_DIRS}
  ${hellocm_msgs_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
  ${sensor_msgs_INCLUDE_DIRS}
  include ${rclcpp_INCLUDE_DIRS}
  include ${image_transport_INCLUDE_DIRS}
  include ${tf2_INCLUDE_DIRS}
  include ${tf2_ros_INCLUDE_DIRS}
  include ${tf2_geometry_msgs_INCLUDE_DIRS}
)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(cmrosutils REQUIRED)
find_package(hellocm_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

add_executable(${PROJECT_NAME} src/planning.cpp)
add_executable(global_path src/global_path.cpp)

ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  cmrosutils
  hellocm_msgs
  std_msgs
  sensor_msgs
 )

ament_target_dependencies(global_path
  rclcpp
  cmrosutils
  hellocm_msgs
  std_msgs
  sensor_msgs
  nav_msgs
)

install(TARGETS
 ${PROJECT_NAME}
 global_path
 DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_export_libraries(
  ${PROJECT_NAME}
  global_path
)

ament_export_dependencies(
  rclcpp
  cmrosutils
  hellocm_msgs
  rosidl_default_runtime
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()