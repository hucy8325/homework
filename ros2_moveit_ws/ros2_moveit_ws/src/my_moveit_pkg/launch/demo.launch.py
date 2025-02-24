from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='my_moveit_pkg',
            executable='moveit_demo',
            output='screen',
            parameters=[{
                "planning_group": "panda_arm",  # 对应Panda机械臂的规划组
                "target_position": [0.5, 0.0, 0.5]
            }]
        )
    ])
