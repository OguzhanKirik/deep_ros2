# tb4_sim.launch.py
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    rviz = LaunchConfiguration('rviz')
    slam = LaunchConfiguration('slam')
    nav2 = LaunchConfiguration('nav2')

    tb4_pkg = get_package_share_directory('turtlebot4_ignition_bringup')
    tb4_launch = os.path.join(tb4_pkg, 'launch', 'turtlebot4_ignition.launch.py')

    return LaunchDescription([
        DeclareLaunchArgument('rviz', default_value='true'),
        DeclareLaunchArgument('slam', default_value='true'),   # or 'off'
        DeclareLaunchArgument('nav2', default_value='true'),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(tb4_launch),
            launch_arguments={
                'rviz': rviz,
                'slam': slam,
                'nav2': nav2,
            }.items()
        ),
    ])
