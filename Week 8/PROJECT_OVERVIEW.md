# Four Wheel Mobile Robot Project

## Overview

As part of learning ROS 2, I developed a four-wheel differential drive mobile robot in simulation.

The objective of this project was not only to build a moving robot but also to understand the complete ROS 2 robotics pipeline, including robot modeling, control, transforms, localization, and mapping.

The project was developed incrementally, with each ROS 2 concept being integrated one at a time.

---

# Project Goals

The primary goals were:

- Learn ROS 2 architecture.
- Build a complete mobile robot from scratch.
- Understand URDF and Xacro.
- Learn TF2 transforms.
- Simulate the robot in Gazebo.
- Control the robot using ros2_control.
- Visualize the robot in RViz.
- Integrate LiDAR.
- Perform SLAM using slam_toolbox.

---

# Repository Structure

The implementation of this robot is available in the repository:

```
four_wheel_mobile_robot/
```

The repository contains the complete ROS 2 workspace used throughout development.

Major packages include:

- Robot Description
- Gazebo Simulation
- ros2_control Configuration
- Controller Configuration
- Launch Files
- SLAM Configuration

---

# Technologies Used

- ROS 2 Humble
- Gazebo
- RViz2
- URDF
- Xacro
- ros2_control
- TF2
- robot_state_publisher
- joint_state_publisher
- slam_toolbox

---

# Development Process

The robot was developed in multiple stages.

## Stage 1 — Robot Modeling

Created the robot using:

- Links
- Joints
- Inertial properties
- Collision models
- Visual models

The robot description was written using **URDF** and later simplified using **Xacro**.

---

## Stage 2 — TF Tree

Configured:

- robot_state_publisher
- joint_state_publisher

to generate the TF tree.

This allowed RViz to correctly visualize all robot links.

---

## Stage 3 — Gazebo Simulation

Imported the robot into Gazebo.

Added:

- Physics
- Wheel joints
- Differential drive motion

---

## Stage 4 — ros2_control

Integrated:

- Controller Manager
- Diff Drive Controller
- Joint State Broadcaster

This enabled the robot to receive velocity commands.

---

## Stage 5 — Robot Control

The robot can be controlled by publishing velocity commands.

Example:

```bash
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist
```

Movement:

- Forward
- Reverse
- Left turn
- Right turn

---

## Stage 6 — LiDAR Integration

Added a simulated LiDAR sensor.

The sensor publishes

```
/scan
```

using

```
sensor_msgs/LaserScan
```

The laser data can be visualized in RViz.

---

## Stage 7 — SLAM

Integrated

```
slam_toolbox
```

to generate a map while the robot moves.

The objective was to create a 2D occupancy grid map of the environment.

---

# Robot Architecture

```
Keyboard

      │

      ▼

cmd_vel

      │

      ▼

Diff Drive Controller

      │

      ▼

Wheel Joints

      │

      ▼

Robot Motion

      │

      ▼

Odometry

      │

      ▼

TF
```

Sensor pipeline:

```
LiDAR

      │

      ▼

/scan

      │

      ▼

slam_toolbox

      │

      ▼

Map
```

---

# Challenges Faced

During development, several practical issues were encountered.

## Controllers Not Active

Initially, the robot did not move because the controllers were loaded but not activated.

This was resolved by activating the required controllers after launching the simulation.

---

## Incorrect Topic

At one point, `rqt` was publishing commands to the wrong topic.

After correcting the published topic, the robot responded correctly.

---

## TF Issues

Several TF issues occurred while building the robot.

Examples:

- Missing transforms
- Incorrect parent-child relationships
- Disconnected TF tree

These problems were fixed by carefully checking the URDF and Xacro files.

---

# Current SLAM Issue

The robot can currently:

- Spawn successfully in Gazebo.
- Move using the Differential Drive Controller.
- Publish LiDAR data.
- Publish Odometry.
- Publish TF.

However, **SLAM is still not working correctly**.

The current issue appears to be related to the SLAM configuration rather than the robot model itself.

Possible causes include:

- Incorrect frame configuration (`map`, `odom`, or `base_link`)
- Incorrect laser scan configuration
- TF timing or transform issues
- `slam_toolbox` parameter configuration
- Odometry or scan synchronization

Further debugging is required before reliable map generation is achieved.

---

# Learning Outcome

This project provided hands-on experience with:

- ROS 2 architecture
- URDF/Xacro
- TF2
- Gazebo simulation
- ros2_control
- Robot kinematics
- LiDAR integration
- Robot localization concepts
- SLAM fundamentals

The project serves as a strong foundation for future robotics projects such as autonomous navigation.