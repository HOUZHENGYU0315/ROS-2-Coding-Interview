# ROS-2-Coding-Interview
ROS 2 Coding Interview//DC229262

Prerequisites
git clone https://github.com/HOUZHENGYU0315/ROS-2-Coding-Interview
sudo apt install ros-humble-rqt-plot

Setup & Run
cd catkin_ws/src
cd ~/catkin_ws
colcon build
source install/setup.bash

run driver node
ros2 run driver driver_node

run process node
ros2 run process process_node

Open rqt_plot and add topics:
/command/target/x, /command/target/y, /command/target/z

PID Gains
self.Kp = 1.0
self.Ki = 0.1
self.Kd = 0.01
