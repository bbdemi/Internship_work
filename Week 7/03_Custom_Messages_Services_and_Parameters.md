# Custom Messages, Services & Parameters

ROS 2 allows developers to define their own message and service types instead of only using the built-in interfaces.

This makes it possible to exchange application-specific data between nodes.

---

# Why Custom Messages?

The standard message types are useful for common applications, but many robots require additional information.

Example:

A delivery robot may need to publish:

- Package ID
- Destination
- Weight
- Delivery Status

Instead of sending these separately, they can be grouped into a single custom message.

---

# Message (.msg) Files

A custom message is defined inside the **msg** directory.

Example workspace:

```
my_robot_interfaces/

├── msg/
│   └── RobotStatus.msg
│
├── srv/
├── CMakeLists.txt
└── package.xml
```

---

## Example Message

```text
string robot_name
float64 battery
bool emergency_stop
int32 current_goal
```

Every line contains:

```
<data_type> <variable_name>
```

---

## Common Message Data Types

| Type | Description |
|------|-------------|
| bool | True / False |
| int8-int64 | Signed integers |
| uint8-uint64 | Unsigned integers |
| float32 | Floating point |
| float64 | Double precision |
| string | Text |
| time | ROS Time |
| duration | Time interval |

---

# Building Custom Messages

Whenever a new message is added:

1. Create the `.msg` file.
2. Update `CMakeLists.txt`.
3. Update `package.xml`.
4. Rebuild the workspace.

```bash
colcon build
```

Then source it again.

```bash
source install/setup.bash
```

---

# Viewing a Message

```bash
ros2 interface show my_robot_interfaces/msg/RobotStatus
```

Example output:

```text
string robot_name
float64 battery
bool emergency_stop
int32 current_goal
```

---

# Custom Services

Services are defined using **.srv** files.

A service consists of:

```
Request
----------
Response
```

The two sections are separated by:

```text
---
```

---

## Example Service

```
int32 a
int32 b
---
int32 sum
```

Here,

Request:

```
a
b
```

Response:

```
sum
```

---

# Service Workflow

```
Client

↓

Request

↓

Server

↓

Process Request

↓

Response

↓

Client
```

---

# Another Example

```
Request

string name

---

Response

bool success
string message
```

---

# Generating Interfaces

After creating a message or service:

Update `CMakeLists.txt`.

Example:

```cmake
rosidl_generate_interfaces(${PROJECT_NAME}

  "msg/RobotStatus.msg"

  "srv/AddNumbers.srv"

)
```

---

Update `package.xml` with interface dependencies.

Rebuild.

```bash
colcon build
```

Source again.

```bash
source install/setup.bash
```

---

# Parameters

Parameters are variables stored inside a node.

Instead of changing source code,

the user can change parameter values while the node is running.

---

## Advantages

Instead of

```cpp
speed = 0.5;
```

you can use

```
speed_parameter
```

which can be changed during runtime.

---

# Declaring Parameters

In C++:

```cpp
declare_parameter("speed", 1.0);
```

Reading:

```cpp
get_parameter("speed", speed);
```

---

# Listing Parameters

```bash
ros2 param list
```

Example output:

```
/camera_node
/robot_node
```

---

# Getting Parameter Value

```bash
ros2 param get /robot_node speed
```

Output:

```
1.0
```

---

# Setting Parameters

```bash
ros2 param set /robot_node speed 2.5
```

No recompilation is required.

---

# Parameter Types

ROS 2 supports:

- Integer
- Float
- Double
- Boolean
- String
- Arrays

---

# Parameter File

Instead of typing parameters manually,

they can be stored inside a YAML file.

Example:

```yaml
robot_node:

  ros__parameters:

    speed: 2.0

    wheel_radius: 0.15

    use_sim_time: true
```

Launch files can automatically load these parameters.

---

# Benefits of Parameters

- No recompilation
- Easy tuning
- Reusable nodes
- Better configuration management

Examples:

- PID gains
- Maximum velocity
- Robot dimensions
- Camera exposure
- Topic names

---

# Message vs Service

| Message | Service |
|----------|----------|
| Used with Topics | Used with Services |
| Continuous communication | Request-Response |
| One-way communication | Two-way communication |

---

# Summary

- `.msg` files define custom message types.
- `.srv` files define custom services.
- Services separate Request and Response using `---`.
- Interfaces are generated during compilation.
- Parameters allow runtime configuration.
- Parameters can be stored inside YAML files.
- Messages are used with Topics, while Services are used with Client-Server communication.