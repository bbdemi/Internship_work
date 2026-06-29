# Launch Files and TF2

Launch files simplify the process of starting multiple ROS 2 nodes simultaneously. TF2 (Transform Library) allows different parts of a robot to understand the position and orientation of each coordinate frame relative to one another.

---

# Launch Files

A launch file is used to start multiple nodes with a single command.

Instead of opening several terminals and running each node manually, a launch file starts everything automatically.

Example:

```
Launch File

├── Robot State Publisher
├── Joint State Publisher
├── RViz
├── Controller Manager
├── SLAM Toolbox
└── Navigation Stack
```

---

# Advantages of Launch Files

- Start multiple nodes together.
- Pass parameters to nodes.
- Load YAML configuration files.
- Set namespaces and remappings.
- Easier project management.

---

# Launch File Location

A Python launch file is usually placed inside the package's `launch` directory.

```
my_robot/

├── launch/
│   └── robot.launch.py
│
├── src/
├── config/
└── package.xml
```

---

# Running a Launch File

```bash
ros2 launch <package_name> <launch_file>.launch.py
```

Example:

```bash
ros2 launch my_robot robot.launch.py
```

---

# Coordinate Frames

Every object in a robot has its own coordinate frame.

Examples:

```
World Frame

↓

Robot Base

↓

LiDAR

↓

Camera

↓

Manipulator
```

Each frame has:

- Position
- Orientation

---

# Why Coordinate Frames?

Suppose the camera detects an obstacle.

The obstacle position is measured relative to the camera.

However, the navigation system needs the obstacle position relative to the robot.

TF2 performs these coordinate transformations automatically.

---

# Common Robot Frames

Typical mobile robot frames are:

```
map

↓

odom

↓

base_link

↓

laser
```

Where:

- **map** → Global reference frame.
- **odom** → Odometry frame.
- **base_link** → Robot body frame.
- **laser** → LiDAR frame.

---

# What is TF2?

TF2 is the ROS 2 library responsible for maintaining relationships between coordinate frames.

It continuously calculates transforms between frames.

Example:

```
map

↓

odom

↓

base_link

↓

camera
```

---

# Static Transforms

Static transforms never change.

Examples:

- Camera mounted rigidly on the robot.
- LiDAR mounted on top of the chassis.

Example:

```
base_link

↓

camera
```

This relationship always remains constant.

---

# Dynamic Transforms

Dynamic transforms change continuously.

Examples:

- Robot moving.
- Rotating wheels.
- Moving robotic arm.

Example:

```
odom

↓

base_link
```

As the robot moves, this transform changes continuously.

---

# TF Broadcaster

A broadcaster publishes transforms.

Example:

```
Robot

↓

Computes Position

↓

Broadcast TF
```

Broadcasters continuously update frame positions.

---

# TF Listener

A listener receives transform information.

Example:

```
Navigation Node

↓

Requests Transform

↓

TF Listener

↓

Returns Required Transform
```

---

# Transform Chain

TF2 automatically computes transforms through intermediate frames.

Example:

```
map

↓

odom

↓

base_link

↓

camera
```

If we ask:

```
camera → map
```

TF2 combines all intermediate transforms automatically.

---

# Why Use TF2?

Without TF2, every node would need to manually calculate transformations.

TF2:

- Reduces complexity.
- Avoids duplicated calculations.
- Keeps all nodes synchronized.

---

# Viewing the TF Tree

To display all coordinate frames:

```bash
ros2 run tf2_tools view_frames
```

This generates a PDF showing the frame tree.

---

# Echoing a Transform

To continuously display a transform:

```bash
ros2 run tf2_ros tf2_echo frame1 frame2
```

Example:

```bash
ros2 run tf2_ros tf2_echo base_link laser
```

---

# Static Transform Publisher

Publish a fixed transform.

Example:

```bash
ros2 run tf2_ros static_transform_publisher \
1 0 0 0 0 0 \
base_link laser
```

This creates a static transform between:

```
base_link

↓

laser
```

---

# Dynamic Transform Broadcaster

A dynamic broadcaster continuously updates frame positions.

Typical applications:

- Robot localization
- Robot arm joints
- Mobile robot navigation

---

# Robot State Publisher

The Robot State Publisher reads the robot's URDF model and automatically publishes transforms for all links.

Example:

```
URDF

↓

Robot State Publisher

↓

TF Tree
```

---

# Joint State Publisher

The Joint State Publisher publishes the current joint positions.

Robot State Publisher combines these joint values with the URDF to generate the complete TF tree.

---

# Example TF Tree

```
map

↓

odom

↓

base_link

├── laser

├── camera

└── imu_link
```

---

# Static vs Dynamic Transforms

| Static Transform | Dynamic Transform |
|-----------------|-------------------|
| Never changes | Changes continuously |
| Published once | Published continuously |
| Camera mounting | Robot movement |
| LiDAR mounting | Arm joints |

---

# Broadcaster vs Listener

| Broadcaster | Listener |
|-------------|-----------|
| Publishes transforms | Reads transforms |
| Source of frame data | Consumer of frame data |
| Updates TF tree | Uses TF tree |

---

# Summary

- Launch files start multiple nodes together.
- Coordinate frames describe the position and orientation of robot components.
- TF2 manages relationships between coordinate frames.
- Static transforms never change.
- Dynamic transforms update continuously.
- Broadcasters publish transforms.
- Listeners read transforms.
- Robot State Publisher publishes transforms from the URDF.
- Joint State Publisher publishes joint values used to compute the robot's TF tree.
- TF2 automatically computes transformations through intermediate frames.