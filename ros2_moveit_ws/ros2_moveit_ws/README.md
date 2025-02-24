# MoveIt2 大作业使用指南

## 环境要求
- Ubuntu 22.04
- Docker 20.04+
- Docker Compose 2.10+

## 快速开始
```bash
# 克隆仓库
git clone https://your-repository-url.git
cd ros2_moveit_ws

# 构建并运行容器
xhost +local:docker
docker-compose build
docker-compose up

# (新终端) 查看机械臂状态
ros2 topic list
