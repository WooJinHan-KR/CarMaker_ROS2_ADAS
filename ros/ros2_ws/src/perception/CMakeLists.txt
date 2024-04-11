cmake_minimum_required(VERSION 3.5)
project(perception)

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

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(cmrosutils REQUIRED)
find_package(hellocm_msgs REQUIRED)
find_package(image_transport REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)

add_library(${PROJECT_NAME} SHARED
  src/cmnode.cpp
  src/LidarRSI_IF.cpp
  src/RadarRSI_IF.cpp
)


include_directories(
  include
  include ${rclcpp_INCLUDE_DIRS}
  include ${image_transport_INCLUDE_DIRS}
  include ${tf2_INCLUDE_DIRS}
  include ${tf2_ros_INCLUDE_DIRS}
  include ${tf2_geometry_msgs_INCLUDE_DIRS}
)

ament_target_dependencies(${PROJECT_NAME}
    rclcpp
    cmrosutils
    hellocm_msgs
    tf2
    tf2_ros
    tf2_geometry_msgs
    nav_msgs
    sensor_msgs
    visualization_msgs
 )

add_executable(${PROJECT_NAME}_node src/carmaker_vds_client_node.cpp)
ament_target_dependencies(${PROJECT_NAME}_node rclcpp image_transport tf2 tf2_ros tf2_geometry_msgs)


install(TARGETS
   ${PROJECT_NAME}
   DESTINATION lib
 )

install(TARGETS ${PROJECT_NAME}_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

install(
  PROGRAMS launch/IPGMovie_VDS_helper.sh
  DESTINATION lib/${PROJECT_NAME}
)

#install(DIRECTORY include/
#  DESTINATION include
# )

ament_export_libraries(${PROJECT_NAME})

ament_export_dependencies(rclcpp)
ament_export_dependencies(cmrosutils)
ament_export_dependencies(hellocm_msgs)
ament_export_dependencies(tf2)
ament_export_dependencies(tf2_ros)
ament_export_dependencies(tf2_geometry_msgs)
ament_export_dependencies(nav_msgs)
ament_export_dependencies(sensor_msgs)
ament_export_dependencies(visualization_msgs)
ament_export_dependencies(rosidl_default_runtime)

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
