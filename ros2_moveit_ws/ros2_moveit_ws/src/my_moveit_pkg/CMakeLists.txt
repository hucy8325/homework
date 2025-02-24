cmake_minimum_required(VERSION 3.8)
project(my_moveit_pkg)

# 查找依赖（带组件声明）
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(moveit_core REQUIRED
  COMPONENTS
    kinematics_plugin_loader
    utils
)
find_package(moveit_ros_planning_interface REQUIRED
  COMPONENTS
    move_group_interface
    planning_scene_monitor
)

# 可执行文件
add_executable(moveit_demo
  src/moveit_demo.cpp
)

# 依赖传递
ament_target_dependencies(moveit_demo
  rclcpp
  moveit_core
  moveit_ros_planning_interface
)

# 显式链接库
target_link_libraries(moveit_demo
  ${moveit_core_LIBRARIES}
  ${moveit_ros_planning_interface_LIBRARIES}
  rclcpp::rclcpp
)

install(TARGETS moveit_demo
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
