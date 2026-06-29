# Cameras, LiDAR, Odometry and SLAM

This document summarizes the concepts learned while integrating sensors and localization into a ROS 2 mobile robot.

---

# Camera in ROS 2

A camera is treated as a sensor that continuously publishes image data.

Typical data flow:

```
Camera Hardware

        │

        ▼

Camera Driver Node

        │

        ▼

sensor_msgs/Image

        │

        ▼

Computer Vision Algorithms
```

The driver node communicates with the physical camera and publishes images as ROS messages.

---

# Raw Images

The default image published by a camera is usually:

```
/image_raw
```

Characteristics:

- Unprocessed image
- Highest quality
- Largest bandwidth usage

These images are typically used by computer vision algorithms.

---

# Compressed Images

ROS can also publish compressed images.

```
/image_raw/compressed
```

Advantages:

- Smaller bandwidth
- Faster transmission
- Useful for remote visualization

Compression is handled using the **image_transport** package.

---

# Image Transport

`image_transport` is a ROS library that automatically chooses how images are transmitted.

Possible transports include:

- Raw
- Compressed
- Theora
- Compressed Depth

Applications can subscribe without worrying about the underlying transport.

---

# Standard Image Message

Camera images are published using

```text
sensor_msgs/msg/Image
```

Compressed images use

```text
sensor_msgs/msg/CompressedImage
```

---

# Camera Coordinate Frames

Every camera has two commonly used frames.

## camera_link

This follows the standard ROS coordinate convention.

```
      Z
      ↑
      |
      |
Y ←---●---→ X
```

Used for:

- Robot modeling
- TF tree

---

## camera_link_optical

Computer vision libraries expect a different coordinate convention.

```
        Z (forward)

        ↑

        |

        ●────→ X (right)

       /

      Y (down)
```

Used by:

- OpenCV
- Depth cameras
- Image processing algorithms

---

# Why Two Camera Frames?

The robot follows ROS coordinate conventions.

Vision algorithms follow optical conventions.

Having both frames avoids unnecessary coordinate conversions.

---

# LiDAR

LiDAR stands for

**Light Detection And Ranging**

It measures distance by sending laser pulses and measuring the time taken for them to return.

---

## LiDAR Data Flow

```
LiDAR

      │

      ▼

Driver Node

      │

      ▼

sensor_msgs/LaserScan

      │

      ▼

Navigation / SLAM
```

---

# LiDAR Applications

LiDAR is commonly used for

- Mapping
- Obstacle detection
- Localization
- Navigation
- Path planning

---

# ROS Message Type

LiDAR data is generally published as

```text
sensor_msgs/msg/LaserScan
```

---

# Odometry

Odometry estimates the robot's position using wheel motion.

It answers the question:

> "Where is the robot based on how far the wheels have turned?"

---

## How Odometry Works

The robot measures wheel rotation.

↓

Wheel velocity is calculated.

↓

Velocity is integrated over time.

↓

Estimated position is obtained.

This process is called **Dead Reckoning**.

---

# Dead Reckoning

Odometry estimates position by integrating velocity over time.

Since every measurement has a small error,

those errors accumulate.

Therefore,

odometry gradually drifts.

---

# Odometry Error

Small wheel slip

↓

Small velocity error

↓

Small position error

↓

Error grows over time

This is why odometry alone is insufficient for long-term localization.

---

# map, odom and base_link Frames

A mobile robot commonly uses three coordinate frames.

```
map

↓

odom

↓

base_link
```

---

## map Frame

The global frame.

Characteristics:

- Corrected using localization or SLAM
- Can change suddenly ("jump")
- Represents the robot's best estimate in the world

---

## odom Frame

Local frame generated from wheel odometry.

Characteristics:

- Smooth
- Continuous
- Never jumps
- Drifts slowly over time

---

## base_link Frame

Represents the robot body.

All sensors and actuators are defined relative to this frame.

---

# Relationship Between Frames

```
map

↓

odom

↓

base_link
```

The transform

```
odom → base_link
```

is smooth because it comes from wheel motion.

The transform

```
map → odom
```

may occasionally jump when localization corrects accumulated error.

---

# Why Does map Jump?

Localization algorithms compare sensor observations with the environment.

When a better estimate is found,

the robot's global position is corrected.

This causes

```
map

↓

odom
```

to change suddenly.

---

# SLAM

SLAM stands for

**Simultaneous Localization And Mapping**

It allows a robot to

- Build a map
- Estimate its own position

at the same time.

---

# Types of SLAM

## Feature-Based SLAM

Also called Landmark SLAM.

The robot stores important features.

Examples:

- Doors
- Corners
- Pillars
- Landmarks

Localization is performed relative to these features.

---

## Grid-Based SLAM

Instead of storing landmarks,

the environment is divided into small cells.

Each cell stores whether it is

- Occupied
- Free
- Unknown

Example:

```
■ = Occupied

□ = Free

? = Unknown
```

This produces an occupancy grid map.

---

# Why Use LiDAR with SLAM?

Wheel odometry drifts.

LiDAR provides measurements of the environment.

SLAM combines

- Odometry
- LiDAR observations

to continuously correct robot position.

---

# Typical Mobile Robot Pipeline

```
Wheel Encoders

        │

        ▼

Odometry

        │

        ▼

SLAM

        ▲

        │

LiDAR

        │

        ▼

Map
```

---

# Summary

- Cameras publish images through a driver node.
- `/image_raw` contains unprocessed images.
- `image_transport` provides compressed image transport.
- Cameras use both `camera_link` and `camera_link_optical` frames.
- LiDAR measures distance using laser pulses.
- LiDAR data is published as `sensor_msgs/msg/LaserScan`.
- Odometry estimates position from wheel motion.
- Dead reckoning accumulates error over time.
- `odom` provides smooth local motion estimates.
- `map` provides globally corrected positions.
- `base_link` represents the robot body.
- SLAM simultaneously estimates robot pose while building a map.
- Feature-based SLAM stores landmarks, whereas Grid-based SLAM stores occupancy information.