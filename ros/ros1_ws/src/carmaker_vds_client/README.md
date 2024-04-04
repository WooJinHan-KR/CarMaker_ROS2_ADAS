# VDS ROS Client Node

## How-To Run
While CarMaker is in idle, run in a new terminal:
`source /opt/ros/<ros-distro>/setup.bash`
`source ./ros/ros1_ws/devel/setup.bash`
`roslaunch carmaker_vds_client carmaker_vds_client.launch start_movie:=true`

To launch multiple VDS clients simultaneously you can use the following launchfile:
`roslaunch carmaker_vds_client multicam_example.launch`

To see available arguments, check the launch file or run:
`roslaunch carmaker_vds_client carmaker_vds_client.launch --ros-args` or
`roslaunch carmaker_vds_client multicam_example.launch --ros-args`.

## Performance Suggestions
For better performance, run Movie instances in Performance mode (needs to be activated before running VDS client, if ExclusiceMode is on):
`IPGMovie -> View -> Qualitiy Settings... -> Mode`

## Visualization Errors
If the camera views are not initialized correctly, try starting the simulation paused (F2 button):
 - choose TestRun
 - launch VDS client(s)
 - pause simulation (hit F2)
 - start TestRun
 - release paused mode (hit F2 again)

If you are launching multiple VDS clients simultaneously and the camera views are not initialized correctly, try increasing the delay_factor or startup_delay parameters:
`roslaunch carmaker_vds_client multicam_example.launch delay_factor:=1.5`
