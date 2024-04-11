
CarMaker 13.0.1 & ROS2 Interface + Autonomous Driving Algorithm



## Outline

- [Installation](#installation)
- [Start Procedure](#Start-Procedure)
- [CMRosIFParameters](#CMRosIFParameters)


## Installation

1. Create `CarMaker` Project Folder
![Alt text](/doc/pic/create_project_folder.png)
![Alt text](/doc/pic/create_project_folder2.png)
    - check `Sources / Build Environment` checkbox
2. Copy `CMRosIF-1.0.0-linux64-Release` to your project folder
3. Run patch command
    ```bash
    cd ./src_cmrosif
    # Set command following `CarMaker` version
    # CM_09, CM_10, CM_11, CM_12, CM_13
    ./patch.sh CM_13
    ```
4. Build `CarMaker`(./src) and `ROS` workspace(./ros/ros2_ws/src)

    ```bash
    # ROS 2
    ./build.sh 2
    ```

## Start Procedure

1. Open `CarMaker` using specific command
    ```bash
    ./CMStart.sh
    ```
2. Run `Launch & Start Application`
![Alt text](/doc/pic/launch_&_start_application.png)
3. Open `TestRun`
4. Run Simulation

## CMRosIFParameters
- [CMRosIFParameters](Data/Config/CMRosIFParameters)

Access CMRosIFParameters with `Edit Parameters` on {CarMaker Main GUI}/Extras

ROS Library Path
```
Cfg.Lib.Path = libperception.so
```

Namespace settings

    ```
    ## Remapping arguments for ROS 2
    Cfg.Args = --ros-args -r __ns:=/carmaker -r /carmaker/ext2cm:=/hellocm/ext2cm
    ```

Launch File setting

    ```
    ## Launch arguments for ROS 2 (ros2 launch <args>)
    Launch.Args = hellocm hellocm.launch.py use_sim_time:=True
    ```

set using Clock Server
```
Node.UseSimTime = 1
```

set Clock time step (ms)
```
Node.nCyclesClock = 1
```