from launch import LaunchDescription
import launch_ros.actions
from launch import Condition
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

import math

#<!-- IPGMovie -->
start_movie="false"
carmaker_host="localhost"
vds_config="0"
project_folder="./../../../../../"
delay_factor="0.5"
startup_delay="bash -c 'sleep " + str(float(delay_factor) * int(vds_config)) + "; $0 $@' "
#<!-- IPGMovie -->

#<!-- VDS client -->
vds_host=carmaker_host
vds_port=str(2210 + int(vds_config))
connection_tries="5"
camera_name="vds_node_" + vds_host + "_" + vds_port
camera_frame=camera_name
#<!-- VDS client -->

start_rqt_image_view="true"

#<!-- External Coordinate Transformation -->
param_trans_rot="[2.8, 0., 1.3, 0., 0., 0.]"
#<!-- External Coordinate Transformation -->

#<!-- Camera calibration -->
fov_deg="20"
width="640"
height="480"
c_x=str(0.5 * int(width))
c_y=str(0.5 * int(height))
fov_rad=str(float(fov_deg) * 3.1415 / 180.)
f_x=str(float(c_x) / math.tan(0.5 * float(fov_rad)))
f_y=str(float(c_y) / math.tan(0.5 * float(fov_rad)))

if float(f_x) >= float(f_y):
    max_f = f_x
else:
    max_f = f_y
    
calib_mat_k=str([float(max_f), 0., float(c_x), 0., float(max_f), float(c_y), 0., 0., 1.])
calib_mat_r="[1., 0., 0., 0., 1., 0., 0., 0., 1.]"
calib_mat_p=str([float(max_f), 0., float(c_x), 0., 0., float(max_f), float(c_y), 0., 0., 0., 1., 0.])
calib_mat_d="[0.0]"
distortion_model=""
binning_x="0"
binning_y="0"
#<!-- Camera calibration -->

def generate_launch_description():
    
    return LaunchDescription([
        DeclareLaunchArgument('start_movie', default_value=start_movie),
        DeclareLaunchArgument('vds_config', default_value=vds_config),
        DeclareLaunchArgument('project_folder', default_value=project_folder),
        DeclareLaunchArgument('carmaker_host', default_value=carmaker_host),
        DeclareLaunchArgument('startup_delay', default_value=startup_delay),
        launch_ros.actions.Node(
            package="carmaker_vds_client",
            node_executable="IPGMovie_VDS_helper.sh",
            node_name="vds_movie_helper_"+vds_config,
            emulate_tty=True,
            arguments= ['vds_config', 'project_folder', 'carmaker_host'],
            prefix=[LaunchConfiguration('startup_delay')],
            condition=IfCondition(LaunchConfiguration('start_movie')),
        ),

        DeclareLaunchArgument('camera_name', default_value=camera_name),
        DeclareLaunchArgument('vds_host', default_value=vds_host),
        DeclareLaunchArgument('vds_port', default_value=vds_port),
        DeclareLaunchArgument('connection_tries', default_value=connection_tries),
        DeclareLaunchArgument('camera_frame', default_value=camera_frame),
        DeclareLaunchArgument('param_trans_rot', default_value=param_trans_rot),
        DeclareLaunchArgument('calib_mat_k', default_value=calib_mat_k),
        DeclareLaunchArgument('calib_mat_r', default_value=calib_mat_r),
        DeclareLaunchArgument('calib_mat_p', default_value=calib_mat_p),
        DeclareLaunchArgument('calib_mat_d', default_value=calib_mat_d),
        DeclareLaunchArgument('distortion_model', default_value=distortion_model),
        DeclareLaunchArgument('binning_x', default_value=binning_x),
        DeclareLaunchArgument('binning_y', default_value=binning_y),
        launch_ros.actions.Node(
            package="carmaker_vds_client",
            node_executable="carmaker_vds_client_node",
            node_namespace=LaunchConfiguration('camera_name'),
            node_name="node",
            emulate_tty=True,
            output="screen",
            prefix=[LaunchConfiguration('startup_delay')],
            parameters=[
                {"vds_host": LaunchConfiguration('vds_host')},
                {"vds_port": LaunchConfiguration('vds_port')},
                {"connection_tries": LaunchConfiguration('connection_tries')},
                {"camera_frame": LaunchConfiguration('camera_frame')},
                {"param_trans_rot": LaunchConfiguration('param_trans_rot')},
                {"calib_mat_k": LaunchConfiguration('calib_mat_k')},
                {"calib_mat_r": LaunchConfiguration('calib_mat_r')},
                {"calib_mat_p": LaunchConfiguration('calib_mat_p')},
                {"calib_mat_d": LaunchConfiguration('calib_mat_d')},
                {"distortion_model": LaunchConfiguration('distortion_model')},
                {"binning_x": LaunchConfiguration('binning_x')},
                {"binning_y": LaunchConfiguration('binning_y')},
            ]
        ),
        
        DeclareLaunchArgument('start_rqt_image_view', default_value=start_rqt_image_view),
        DeclareLaunchArgument('camera_name_rqt', default_value='/' + camera_name + '/image_raw'),
        launch_ros.actions.Node(
            package="rqt_image_view",
            node_executable="rqt_image_view",
            node_name="image_view",
            emulate_tty=True,
            arguments=[LaunchConfiguration('camera_name_rqt')],
            condition=IfCondition(LaunchConfiguration('start_rqt_image_view')),
        ),
    
    ])