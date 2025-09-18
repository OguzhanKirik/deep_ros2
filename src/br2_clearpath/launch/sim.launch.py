from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # Get the clearpath_simulator package path
    sim_pkg = get_package_share_directory('clearpath_gz')
    sim_launch = os.path.join(sim_pkg, 'launch', 'simulation.launch.py')

    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(sim_launch),
            launch_arguments={
                'robot': 'husky',   # change to husky, warthog, dingo if you prefer
                'world': 'pipeline',    # lightweight empty world
                'rviz': 'false',
                'nav2': 'false',
                'slam': 'false',
            }.items()
        ),
    ])
