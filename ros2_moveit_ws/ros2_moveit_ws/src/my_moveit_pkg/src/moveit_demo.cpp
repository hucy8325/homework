#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("moveit_demo");
  
  // 参数读取
  std::string planning_group = node->declare_parameter("planning_group", "panda_arm");
  std::vector<double> target_position = node->declare_parameter("target_position", std::vector<double>{0.5, 0.0, 0.5});

  // 初始化MoveGroup
  auto move_group = std::make_shared<moveit::planning_interface::MoveGroupInterface>(
      node, planning_group);
  
  // 设置目标位姿
  geometry_msgs::msg::Pose target_pose;
  target_pose.position.x = target_position[0];
  target_pose.position.y = target_position[1];
  target_pose.position.z = target_position[2];
  target_pose.orientation.w = 1.0;

  // 运动规划
  try {
    move_group->setPoseTarget(target_pose);
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    auto const success = static_cast<bool>(move_group->plan(plan));

    if (success) {
      move_group->execute(plan);
      RCLCPP_INFO(node->get_logger(), "Motion executed successfully");
    } else {
      RCLCPP_ERROR(node->get_logger(), "Planning failed");
    }
  } catch (const std::exception& e) {
    RCLCPP_ERROR_STREAM(node->get_logger(), "Error: " << e.what());
  }

  rclcpp::shutdown();
  return 0;
}
