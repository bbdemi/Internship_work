# ROS 2 Workspaces, Packages & Client Libraries

This document summarizes the concepts of ROS 2 workspaces, packages, client libraries, logging, bag files, and package development.

---

# Logging with rqt_console

ROS 2 nodes continuously generate log messages while running.

These logs help developers:

- Debug applications
- Monitor node behavior
- Detect warnings and errors

The **rqt_console** tool displays all log messages from running nodes.

It also categorizes messages based on severity.

---

## Log Severity Levels

ROS 2 supports multiple logging levels.

| Level | Purpose |
|--------|----------|
| DEBUG | Detailed debugging information |
| INFO | General information |
| WARN | Something unexpected but not fatal |
| ERROR | Serious problem |
| FATAL | Critical error causing node failure |

Example:

```
INFO  -> Robot Started
WARN  -> Low Battery
ERROR -> Failed to Connect
```

---

# Launching Multiple Nodes

Instead of opening multiple terminals and starting each node individually,

ROS 2 provides **Launch Files**.

Launch files allow multiple nodes to start together.

Example:

```
Launch File

│

├── Camera Node
├── LiDAR Node
├── Localization Node
├── Navigation Node
└── RViz
```

Advantages:

- Easier startup
- Reproducible configuration
- Better project organization

---

# Recording and Playing Back Data

ROS 2 can record all messages being published on topics.

The recorded data is stored in a **Bag File**.

Later, the data can be replayed exactly as it was recorded.

This is useful for:

- Debugging
- Algorithm testing
- Simulation
- Offline analysis

---

## Why Record Data?

Suppose a robot crashes while navigating.

Instead of reproducing the problem physically,

you can replay the recorded sensor data.

This allows debugging without rerunning the robot.

---

## Typical Workflow

```
Robot Running

↓

Record Topics

↓

Bag File

↓

Replay Later

↓

Analyze Behaviour
```

---

# ROS 2 Client Libraries

A **Client Library** allows developers to write ROS 2 nodes in different programming languages.

The two most common client libraries are:

## rclcpp

Used for:

- C++

Example:

```cpp
#include "rclcpp/rclcpp.hpp"
```

---

## rclpy

Used for:

- Python

Example:

```python
import rclpy
```

---

# ROS 2 Workspace

A **Workspace** is the directory where ROS 2 packages are developed and built.

Typical structure:

```
ros2_ws/

├── src/
│   ├── package_1
│   ├── package_2
│   └── package_3
│
├── build/
├── install/
└── log/
```

---

## src Folder

The **src** directory contains all source packages.

Example:

```
ros2_ws/

└── src/

    ├── my_robot
    ├── tutorial_interfaces
    └── learning_tf2_cpp
```

---

## Building a Workspace

Navigate to the workspace.

```bash
cd ~/ros2_ws
```

Build all packages.

```bash
colcon build
```

---

# Sourcing a Workspace

After building,

the workspace must be sourced.

```bash
source install/setup.bash
```

This tells ROS 2 about all newly built packages.

---

## Using Multiple Terminals

Suppose you build the workspace in one terminal.

You **do not need to rebuild** it in another terminal.

Simply source the workspace again.

Example:

```bash
source ~/ros2_ws/install/setup.bash
```

Now all packages are available in the new terminal.

---

# Overlay Workspaces

ROS 2 supports **overlay workspaces**.

An overlay workspace extends another workspace.

Example:

```
ROS Installation
        │
        ▼
Underlay Workspace
        │
        ▼
Overlay Workspace
```

Advantages:

- Develop new packages without modifying ROS installation.
- Override packages from the underlay.
- Keep projects isolated.

---

# Packages

A **Package** is the basic unit of software organization in ROS 2.

A package may contain:

- Nodes
- Libraries
- Launch files
- Configuration files
- URDF/Xacro files
- Message definitions

---

## Package Types

ROS 2 mainly supports:

### CMake Packages

Used primarily for C++.

Build system:

```
ament_cmake
```

---

### Python Packages

Used for Python nodes.

Build system:

```
ament_python
```

---

# Creating a Package

Example:

```bash
ros2 pkg create my_robot
```

For a C++ package:

```bash
ros2 pkg create my_robot --build-type ament_cmake
```

For a Python package:

```bash
ros2 pkg create my_robot_py --build-type ament_python
```

---

# Writing Publisher and Subscriber Nodes

For C++ packages,

after creating publisher or subscriber nodes,

remember to update:

- `CMakeLists.txt`
- `package.xml`

Specifically:

- Add dependencies.
- Add executable targets.
- Install executables.

---

Example dependencies:

```cmake
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
```

---

Example executable:

```cmake
add_executable(talker src/talker.cpp)

ament_target_dependencies(
    talker
    rclcpp
    std_msgs
)
```

---

# Python Packages

Python packages are simpler.

Usually only the executable entry point needs to be registered.

No compilation is required.

---

# Service and Client Packages

The same package can also contain:

- Service Server
- Service Client

Just like publishers and subscribers,

remember to register executables and dependencies.

---

# Summary

- **rqt_console** displays ROS 2 log messages.
- ROS 2 logs have five severity levels: DEBUG, INFO, WARN, ERROR, and FATAL.
- **Launch files** start multiple nodes together.
- **Bag files** record topic data for later playback.
- **rclcpp** is the C++ client library.
- **rclpy** is the Python client library.
- A **workspace** is where ROS 2 packages are developed.
- Source the workspace after building.
- Overlay workspaces extend existing ROS installations.
- Packages can be written using **ament_cmake** or **ament_python**.
- Publisher, subscriber, service, and client nodes require proper dependencies and executable registration.