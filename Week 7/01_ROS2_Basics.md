# ROS 2 Basics

This document summarizes the core concepts of ROS 2, including Nodes, Topics, Services, Parameters, and Actions.

---

# What is ROS 2?

ROS 2 (Robot Operating System 2) is a middleware framework that helps different parts of a robot communicate with each other.

Instead of writing one huge program, a robot is divided into multiple small programs called **nodes**.

---

# Nodes

A **Node** is the smallest executable unit in ROS 2.

Each node should have a **single, modular purpose**.

Examples:

- Camera Node
- LiDAR Node
- Motor Controller Node
- Navigation Node
- Localization Node

Keeping nodes modular makes the system easier to maintain and reuse.

---

# Communication in ROS 2

ROS 2 provides three primary communication mechanisms:

- Topics
- Services
- Actions

Each serves a different purpose depending on the application.

---

# Topics

Topics are used for **continuous data exchange** between nodes.

Communication follows the **Publisher–Subscriber** model.

```
Publisher Node
      |
      | publishes messages
      v
   ---------
   | Topic |
   ---------
      ^
      |
Subscriber Node
```

A topic acts like a communication bus.

Publishers send data to a topic.

Subscribers receive data from the topic.

---

## Many-to-Many Communication

ROS 2 allows multiple publishers and multiple subscribers on the same topic.

```
Publisher A  ----\
                  \
Publisher B -------> Topic ------> Subscriber A
                  /
Publisher C -----/              --> Subscriber B
                                 --> Subscriber C
```

This makes ROS 2 highly modular.

---

# Topic Message Types

Every topic carries a specific message type.

Example:

```
geometry_msgs/msg/Twist
```

Breaking it down:

```
geometry_msgs
│
├── Package

msg
│
├── Message folder

Twist
│
└── Message type
```

`Twist` is commonly used to send robot velocity commands.

It contains:

- Linear velocity
- Angular velocity

---

# Useful Topic Commands

List all active topics:

```bash
ros2 topic list
```

Display the type of a topic:

```bash
ros2 topic type <topic_name>
```

Example:

```bash
ros2 topic type /cmd_vel
```

Output:

```
geometry_msgs/msg/Twist
```

---

# Services

Services provide **request-response communication**.

Unlike topics, services do not continuously publish data.

They only respond when requested.

```
Client Node

      Request
         |
         v

     Service Server

         ^
         |
      Response
```

---

## Characteristics of Services

- Client sends one request.
- Server processes it.
- Server sends one response.
- Communication then ends.

---

## Service Communication Model

```
Client
   |
Request
   |
   v
Service Server
   |
Response
   |
   v
Client
```

Many clients can communicate with the same service server.

However,

one service request produces one response.

---

# Topics vs Services

| Topics | Services |
|---------|----------|
| Continuous communication | Request-response communication |
| Publisher-Subscriber model | Client-Server model |
| Used for streaming data | Used for one-time operations |
| Asynchronous | Synchronous |
| Many publishers/subscribers | Multiple clients, single server |

Examples:

### Topics

- Camera images
- Laser scans
- Robot velocity
- IMU data

### Services

- Reset robot
- Save map
- Clear costmap
- Spawn object

---

# Service Types

Every service has a request and a response.

Example:

```
Request
--------
float64 x
float64 y

Response
---------
bool success
string message
```

---

## Empty Service

ROS 2 provides an empty service type.

```
std_srvs/srv/Empty
```

It sends:

- No request data

Returns:

- No response data

Useful when only triggering an action.

Example:

```
Reset Robot

↓

Call Empty Service

↓

Robot Resets
```

---

# Parameters

Parameters are configuration values stored inside a node.

Instead of hardcoding values, nodes can read parameters during runtime.

Examples:

- Robot speed
- Camera resolution
- Wheel radius
- PID gains

---

## Supported Parameter Types

A node can store parameters as:

- Integer
- Float
- Boolean
- String
- Lists (Arrays)

---

# Actions

Actions are used for **long-running tasks**.

Unlike services, actions provide:

- Goal
- Continuous Feedback
- Final Result

```
Client

   Goal
    |
    v

Action Server

Feedback
    |
    v

Client

Final Result
```

---

## Action Components

### Goal

The task to be performed.

Example:

```
Move to (5, 3)
```

---

### Feedback

Periodic updates while executing.

Example:

```
10% Complete

40% Complete

75% Complete
```

---

### Result

Returned after the task finishes.

Example:

```
Goal Reached
```

---

# Action Client

The Action Client:

- Sends goals
- Can cancel goals
- Receives feedback
- Receives final result

---

# Action Server

The Action Server:

- Accepts goals
- Executes the requested task
- Sends continuous feedback
- Returns the final result

---

# Actions vs Services

| Services | Actions |
|----------|----------|
| Immediate response | Long-running tasks |
| Single request-response | Goal + Feedback + Result |
| Cannot provide progress | Continuous progress updates |
| Cannot be cancelled | Can be cancelled |

Examples:

### Services

- Reset robot
- Clear map
- Save file

### Actions

- Navigate to a waypoint
- Pick an object
- Paint a wall
- Dock to charging station

---

# Summary

- **Node** → A modular executable performing one task.
- **Topic** → Continuous communication using the Publisher–Subscriber model.
- **Service** → Request–Response communication between a client and server.
- **Parameter** → Runtime configuration values stored inside nodes.
- **Action** → Used for long-running tasks with Goal, Feedback, and Result.

Understanding these five concepts is the foundation of ROS 2 development.