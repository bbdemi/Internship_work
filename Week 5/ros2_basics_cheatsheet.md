# ROS2 Basics Cheat Sheet

## What is ROS2?

ROS2 (Robot Operating System 2) is a middleware that helps different parts of a robot communicate with each other.

---

## Node

A **node** is a single running program that performs one task.

Examples:
- Camera node
- Motor controller node
- Navigation node
- Sensor node

```text
Robot
├── Camera Node
├── Motor Node
├── Mapping Node
└── Navigation Node
```

---

## Topic

A **topic** is a communication channel used for continuous data streaming.

- Publisher → sends data
- Subscriber → receives data

```text
Camera Node ---> /image_raw ---> Vision Node
```

Use topics for:
- Camera images
- Sensor readings
- Robot position
- Battery status

---

## Publisher & Subscriber

```text
Publisher ---> Topic ---> Subscriber
```

Example:

```text
IMU Node ---> /imu_data ---> Localization Node
```

---

## Service & Client

A **service** is request-response communication.

```text
Client ----request----> Service
Client <---response---- Service
```

Example:
- Reset robot
- Move arm to home
- Add two integers

Use services when an immediate reply is needed.

---

## Action

An **action** is used for long-running tasks with feedback.

```text
Client ---> Goal ---> Action Server
         <--- Feedback ---
         <--- Result -----
```

Examples:
- Navigate to a location
- Paint an entire wall
- Move robotic arm through a trajectory

---

## Parameters

Parameters are configuration values for a node.

Examples:
- max_speed = 0.5
- camera_exposure = 50
- paint_flow_rate = 20

They allow behavior to be changed without recompiling the code.

Useful commands:

```bash
ros2 param list
ros2 param get /node_name parameter_name
ros2 param set /node_name parameter_name value
```

---

## Custom Interfaces

### Custom Message (.msg)
Used to define your own topic data type.

Example:

```text
float32 x
float32 y
bool spraying
```

### Custom Service (.srv)
Used to define request and response data.

```text
int64 a
int64 b
---
int64 sum
```

### Custom Action (.action)
Used for long-running tasks.

```text
# Goal
float32 target

---
# Result
bool success

---
# Feedback
float32 progress
```

---

## Package

A package is a folder containing ROS2 code.

Typical structure:

```text
my_package/
├── src/
├── include/
├── launch/
├── msg/
├── srv/
├── action/
├── CMakeLists.txt
└── package.xml
```

---

## Workspace

A workspace is a collection of ROS2 packages.

```text
ros2_ws/
├── src/
├── build/
├── install/
└── log/
```

Build with:

```bash
colcon build
source install/setup.bash
```

---

## Useful ROS2 Commands

```bash
ros2 node list
ros2 topic list
ros2 topic echo /topic_name
ros2 service list
ros2 action list
ros2 param list
ros2 interface show <interface>
```

---

## Mental Model

```text
Node        -> Running program
Topic       -> Data stream
Publisher   -> Sends topic data
Subscriber  -> Receives topic data
Service     -> Request + Response
Client      -> Calls a service
Action      -> Long-running task with feedback
Parameter   -> Node configuration
.msg        -> Custom topic data type
.srv        -> Custom service definition
.action     -> Custom action definition
Package     -> ROS2 project
Workspace   -> Collection of packages
```

---

## Communication Summary

```text
Topics     -> Continuous data stream
Services   -> Short request-response
Actions    -> Long-running tasks with feedback
Parameters -> Node configuration/settings
```
