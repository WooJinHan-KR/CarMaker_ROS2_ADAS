#
# Message from CarMaker ROS Node to external ROS Node
#

std_msgs/Header header
string frame_id
sensor_msgs/PointCloud2 pointcloud2
float64[] velocity
float64[] distance

# ROS time when message was sent (optional)
builtin_interfaces/Time time

# Cycle number since simulation start (optional)
int64 cycleno

# Synthetic delay to check synchronization (optional)
float64 synthdelay

