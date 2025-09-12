import os
from ament_index_python.packages import get_package_share_directory


from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    


    pkg_dir = get_package_share_directory('bt2_basics')
    param_file = os.path.join(pkg_dir, 'config', 'params.yaml')

    param_read_cmd= Node(
        package='bt2_basics',
        executable="param_reader",
        parameters=[param_file],
        output='screen'
    )

    ld = LaunchDescription()

    ld.add_action(param_read_cmd)

    return ld