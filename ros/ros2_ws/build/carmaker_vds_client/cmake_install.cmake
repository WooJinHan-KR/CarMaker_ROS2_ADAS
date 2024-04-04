# Install script for directory: /home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/src/carmaker_vds_client

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/install/carmaker_vds_client")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/carmaker_vds_client/carmaker_vds_client_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/carmaker_vds_client/carmaker_vds_client_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/carmaker_vds_client/carmaker_vds_client_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/carmaker_vds_client" TYPE EXECUTABLE FILES "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/build/carmaker_vds_client/carmaker_vds_client_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/carmaker_vds_client/carmaker_vds_client_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/carmaker_vds_client/carmaker_vds_client_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/carmaker_vds_client/carmaker_vds_client_node"
         OLD_RPATH "/opt/ros/foxy/lib:/opt/ros/foxy/lib/x86_64-linux-gnu:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/carmaker_vds_client/carmaker_vds_client_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/carmaker_vds_client" TYPE DIRECTORY FILES "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/src/carmaker_vds_client/launch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/carmaker_vds_client" TYPE PROGRAM FILES "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/src/carmaker_vds_client/launch/IPGMovie_VDS_helper.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/build/carmaker_vds_client/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/carmaker_vds_client")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/build/carmaker_vds_client/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/carmaker_vds_client")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/carmaker_vds_client/environment" TYPE FILE FILES "/opt/ros/foxy/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/carmaker_vds_client/environment" TYPE FILE FILES "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/build/carmaker_vds_client/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/carmaker_vds_client/environment" TYPE FILE FILES "/opt/ros/foxy/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/carmaker_vds_client/environment" TYPE FILE FILES "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/build/carmaker_vds_client/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/carmaker_vds_client" TYPE FILE FILES "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/build/carmaker_vds_client/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/carmaker_vds_client" TYPE FILE FILES "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/build/carmaker_vds_client/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/carmaker_vds_client" TYPE FILE FILES "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/build/carmaker_vds_client/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/carmaker_vds_client" TYPE FILE FILES "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/build/carmaker_vds_client/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/carmaker_vds_client" TYPE FILE FILES "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/build/carmaker_vds_client/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/build/carmaker_vds_client/ament_cmake_index/share/ament_index/resource_index/packages/carmaker_vds_client")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/carmaker_vds_client/cmake" TYPE FILE FILES
    "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/build/carmaker_vds_client/ament_cmake_core/carmaker_vds_clientConfig.cmake"
    "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/build/carmaker_vds_client/ament_cmake_core/carmaker_vds_clientConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/carmaker_vds_client" TYPE FILE FILES "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/src/carmaker_vds_client/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ipg-pc-30/CM-Projects/work_woh/240404_CM13_ROS2/ros/ros2_ws/build/carmaker_vds_client/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
