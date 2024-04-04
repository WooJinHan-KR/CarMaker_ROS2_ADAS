# CMRosIF-1.0.0_Sensor_Interface_Example

Example of `CarMaker` Sensor Data + `ROS` Interface

Target CarMaker Version: 11

## Outline

- [Features](#Features)
- [Example 00](#Example_00)
- [Example 01](#Example_01)
- [Example 02](#Example_02)
- [Example 03](#Example_03)

## Features

1. changes in [CMRosIFParameters](Data/Config/CMRosIFParameters) file

    - use new cmrosif library file
        ```
        #Cfg.Lib.Path = libcmnode_hellocm.so
        Cfg.Lib.Path = libcmnode.so
        ```

    - set clock cycle to 1ms
        ```
        Node.nCyclesClock = 1
        ```

2. new CM ROS Interface Node [cmnode](ros/ros1_ws/src/cmnode/)

3. example file in cmnode/src folder
    - exchange file to example file

## Example_00
[Example 00](ros/ros1_ws/src/cmnode/src/Example_00_Topic_Interface/cmnode.cpp)

follow `CM ROS example - Topic Interface`. can check basic topic intereface 

## Example_01
[Example 01](ros/ros1_ws/src/cmnode/src/Example_01_Basic_CMNode/cmnode.cpp)

Explanation about `HELLOCM_EXAMPLE` and `HELLOCM_SERVICE_EXAMPLE` 

## Example_02
[Example 02](ros/ros1_ws/src/cmnode/src/Example_02_simple_node/cmnode.cpp)

Clean CMNode file for User Code.

## Example_03
[Example 03](ros/ros1_ws/src/cmnode/src/Example_03_CM_Interface/cmnode.cpp)

CarMaker Data Interface based on `Example_02`

use TestRun `PerformanceBenchmark`

- LidarRSI Sensor
- CameraRSI Sensor
    ```
    #run RSDS Client - ROS 1
    roslaunch carmaker_vds_client carmaker_vds_client.launch 
    ```
    ```
    #run RSDS Client - ROS 2
    ros2 launch carmaker_vds_client carmaker_vds_client.launch.py 
    ```
- Line Sensor
- Object Sensor

Visualize Data using `Rviz`
- use config file
    - ROS 1 [rviz_config.rviz](Movie/rviz_config.rviz)
    - ROS 2 [rviz_config2.rviz](Movie/rviz_config2.rviz)

![Alt text](/doc/pic/rviz.png)

##
