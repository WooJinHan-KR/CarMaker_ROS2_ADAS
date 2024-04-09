from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import ThisLaunchFileDir

delay_factor = "1.25"
start_rqt = "true"

vds_port_1 = "2210"
vds_config_1 = "0"
camera_name_1 = "color"
camera_name_rqt_1 = "/color/image_raw"
startup_delay_1 = "bash -c 'sleep " + str(float(delay_factor) * int(vds_config_1)) + "; $0 $@' "

vds_port_2 = "2211"
vds_config_2 = "1"
camera_name_2 = "grey"
camera_name_rqt_2 = "/grey/image_raw"
startup_delay_2 = "bash -c 'sleep " + str(float(delay_factor) * int(vds_config_2)) + "; $0 $@' "

vds_port_3 = "2212"
vds_config_3 = "2"
camera_name_3 = "depth"
camera_name_rqt_3 = "/depth/image_raw"
startup_delay_3 = "bash -c 'sleep " + str(float(delay_factor) * int(vds_config_3)) + "; $0 $@' "

def generate_launch_description():
    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([ThisLaunchFileDir(), '/carmaker_vds_client.launch.py']),
            launch_arguments={'camera_name': camera_name_1,
                              'vds_port': vds_port_1,
                              'vds_config': vds_config_1,
                              'delay_factor': delay_factor,
                              'startup_delay': startup_delay_1,
                              'param_trans_rot': '[2.5, 0., 2.5, 0., 0., 0.]',
                              'width': '640',
                              'height': '480',
                              'fov_deg': '20',
                              'start_movie': 'false',
                              'start_rqt_image_view': 'true',
                              'camera_name_rqt': camera_name_rqt_1,
                             }.items(),
            
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([ThisLaunchFileDir(), '/carmaker_vds_client.launch.py']),
            launch_arguments={'camera_name': camera_name_2,
                              'vds_port': vds_port_2,
                              'vds_config': vds_config_2,
                              'delay_factor': delay_factor,
                              'startup_delay': startup_delay_2,
                              'param_trans_rot': '[2.5, 0., 2.5, 0., 0., 0.]',
                              'width': '640',
                              'height': '480',
                              'fov_deg': '20',
                              'start_movie': 'false',
                              'start_rqt_image_view': 'true',
                              'camera_name_rqt': camera_name_rqt_2,
                             }.items(),
            
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([ThisLaunchFileDir(), '/carmaker_vds_client.launch.py']),
            launch_arguments={'camera_name': camera_name_3,
                              'vds_port': vds_port_3,
                              'vds_config': vds_config_3,
                              'delay_factor': delay_factor,
                              'startup_delay': startup_delay_3,
                              'param_trans_rot': '[2.5, 0., 2.5, 0., 0., 0.]',
                              'width': '640',
                              'height': '480',
                              'fov_deg': '20',
                              'start_movie': 'false',
                              'start_rqt_image_view': 'true',
                              'camera_name_rqt': camera_name_rqt_3,
                             }.items(),
            
        ),
        
    ])