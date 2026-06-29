# URDF, Xacro, TF and ROS 2 Control

This document summarizes the concepts learned while building robot models in ROS 2.

---

# What is URDF?

URDF (Unified Robot Description Format) is an XML format used to describe a robot.

A URDF defines:

- Links
- Joints
- Physical properties
- Collision properties
- Visual properties

It represents the complete kinematic structure of a robot.

---

# Physical and Collision Properties

Besides describing the appearance of the robot, URDF also stores:

## Visual

How the robot looks in RViz or Gazebo.

```xml
<visual>
```

---

## Collision

Simplified geometry used for collision checking.

```xml
<collision>
```

Collision models are usually much simpler than visual meshes for faster computation.

---

## Inertial

Defines the physical properties required by simulation.

```xml
<inertial>
```

Contains:

- Mass
- Center of mass
- Inertia matrix

---

# Xacro

Writing a large URDF quickly becomes repetitive.

Xacro solves this problem.

Instead of repeatedly writing the same XML, variables and macros can be used.

Advantages:

- Cleaner code
- Less duplication
- Easier maintenance
- Reusable robot components

---

# Properties in Xacro

Properties store values that are used multiple times.

Example

```xml
<xacro:property name="wheel_radius" value="0.05"/>
```

Now every wheel can reuse the same radius.

---

# Macros

A macro in Xacro is similar to a function.

Instead of rewriting the same XML several times,

define it once and reuse it.

Example:

```xml
<xacro:macro name="wheel" params="prefix">
```

Benefits:

- Reusable
- Easier to modify
- Cleaner robot description

---

# URDF Origin

Every joint contains an origin.

Example

```xml
<origin
    xyz="0 0 0"
    rpy="1.57075 0 0"/>
```

---

## xyz

Translation.

```
x
y
z
```

Example

```
xyz="0 0 0"
```

Means:

No translation.

The child frame starts exactly at the parent frame.

---

## rpy

Rotation.

```
Roll
Pitch
Yaw
```

Corresponding axes:

```
Roll  -> X-axis

Pitch -> Y-axis

Yaw   -> Z-axis
```

Example

```
rpy="1.57075 0 0"
```

means

Rotate approximately **90° about the X-axis**.

---

# URDF Must Form a Tree

A robot description cannot contain disconnected links.

Every link must be connected using joints.

```
Base Link

↓

Wheel Joint

↓

Wheel Link
```

If links are disconnected,

`robot_state_publisher`

cannot construct a TF tree.

As a result,

RViz does not know where to place robot parts.

---

# Joint Types

## Fixed Joint

```
type="fixed"
```

Characteristics

- Cannot move
- Constant transform

Examples

- Camera mount
- LiDAR mount

---

## Continuous Joint

```
type="continuous"
```

Characteristics

- Unlimited rotation
- No angle limits

Examples

- Robot wheels

---

## Revolute Joint

```
type="revolute"
```

Characteristics

- Rotates
- Has upper and lower limits

Example

```xml
<limit
    lower="-1.57"
    upper="1.57"/>
```

---

# Joint Axis

Every movable joint must know the axis around which it rotates.

Example

```xml
<axis xyz="0 1 0"/>
```

Without specifying the axis,

ROS does not know how the joint should move.

---

# Transform Tree

Transforms create relationships between coordinate frames.

Each frame is defined with respect to **only one parent frame**.

This forms a tree.

```
World

↓

Base

├── Camera

├── LiDAR

└── Arm
```

---

# TF Tree vs URDF Tree

TF

```
Tree of Frames

Connected by

Transforms
```

URDF

```
Tree of Links

Connected by

Joints
```

---

# Robot State Publisher

The Robot State Publisher reads the URDF and publishes transforms.

Inputs

- Robot Description
- Joint States

Outputs

- /tf
- /tf_static

---

## Fixed Joints

Published once on

```
/tf_static
```

---

## Moving Joints

Published continuously on

```
/tf
```

---

# Joint States

Normally,

joint states come from actuator feedback.

Possible sources

- Joint State Publisher GUI (early development)
- Simulator
- Real hardware

During development,

Joint State Publisher GUI can automatically discover movable joints in the URDF.

---

# Common Problems Encountered

While controlling the robot,

the following issues were encountered:

- Controllers were not active.
- rqt was publishing commands to the wrong topic.

These are common issues while setting up `ros2_control`.

---

# ROS 2 Control

ROS 2 Control provides a standard interface between

- Control algorithms
- Hardware drivers

Architecture

```
Control Algorithm

↓

ROS 2 Controllers

↓

Controller Manager

↓

Hardware Interface

↓

Motors
```

Configuration is generally provided using

- URDF
- YAML

The Controller Manager loads and manages controllers.

---

# Controller Manager

Responsibilities

- Load controllers
- Configure controllers
- Activate controllers
- Deactivate controllers

Without activating controllers,

robot motion commands will not reach the hardware.

---

# Hardware Interfaces

The Hardware Interface connects ROS 2 with actual robot hardware.

Examples

- Motors
- Encoders
- Servos
- Sensors

---

# Summary

- URDF describes the robot.
- Xacro reduces duplicated XML.
- Properties store reusable values.
- Macros work like functions.
- Every URDF must form a connected tree.
- Fixed joints never move.
- Continuous joints rotate without limits.
- Revolute joints rotate within limits.
- Robot State Publisher converts the URDF into a TF tree.
- Joint states come from GUI, simulation, or real hardware.
- ros2_control connects controllers to physical hardware.
- Controllers must be active for robot motion.