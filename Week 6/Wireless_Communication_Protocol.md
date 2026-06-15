# Wireless Communication Protocols

## 1. Bluetooth Classic

### What is it?
- A wireless protocol designed to replace serial cables.
- Think of it as a **wireless UART cable**.

### How it Works
```text
Phone  <====== Bluetooth ======>  ESP32
                "s100\n"
```

The ESP32 reads and writes data just like UART:

```cpp
SerialBT.read();
SerialBT.write();
```

### Best For
- Robot remote control.
- Wireless serial communication.
- Sending commands from a phone to an ESP32.

---

## 2. BLE (Bluetooth Low Energy)

### What is it?
- A low-power version of Bluetooth designed for battery-operated devices.
- Instead of a serial stream, BLE organizes data into:
  - **Services**
  - **Characteristics**

### Service
A collection of related data.

Example:

```text
Battery Service
├── Battery Level Characteristic
└── Charging Status Characteristic
```

### Characteristic
An individual data item that can be:
- Read.
- Written.
- Notified (automatically updated).

Example:

```text
Servo Control Service
└── Servo Angle Characteristic = 90°
```

### Best For
- Fitness bands.
- Smart watches.
- IoT sensors.
- Battery-powered robots.

---

## 3. Wi-Fi

### What is it?
- A wireless networking technology that allows devices to join an IP network.

```text
Laptop
    │
Wi-Fi Router
    │
ESP32 / Raspberry Pi
```

Once connected, devices can communicate using:
- TCP
- UDP
- HTTP
- DDS
- MQTT

### Best For
- ROS2 multi-machine systems.
- Video streaming.
- Remote robot control.

---

## 4. ESP-NOW

### What is it?
- A proprietary wireless protocol developed by Espressif.
- Allows ESP32 devices to communicate directly without a Wi-Fi router.

```text
ESP32 #1  <------->  ESP32 #2
```

### Features
- Low latency.
- Low power consumption.
- No router required.

### Best For
- Robot swarms.
- Sensor nodes.
- ESP32-to-ESP32 communication.

---

## 5. Zigbee

### What is it?
- A low-power wireless mesh networking protocol.

### Mesh Network

```text
Sensor A ---- Sensor B ---- Sensor C
     \\                        /
      -------- Gateway -------
```

Data can hop through intermediate devices.

### Best For
- Home automation.
- Large sensor networks.
- Industrial monitoring.

---

## 6. LoRa

### What is it?
- A long-range, low-data-rate wireless protocol.

### Tradeoff

```text
Long Range  ⇔  Low Data Rate
```

### Best For
- Agricultural sensors.
- Remote telemetry.
- Smart city applications.

---

# Network / Software Protocols

These protocols sit on top of Wi-Fi or Ethernet and define how applications exchange data.

## 1. TCP (Transmission Control Protocol)

### What is it?
- A reliable, connection-oriented communication protocol.

### How it Works

```text
Laptop ----------- ESP32
       Connection Established
```

TCP guarantees:
- Reliable delivery.
- Correct packet order.
- Retransmission of lost packets.

### Best For
- File transfer.
- Web browsing.
- Reliable robot commands.

---

## 2. UDP (User Datagram Protocol)

### What is it?
- A connectionless communication protocol.

### How it Works

```text
Sender ----> Packet
Sender ----> Packet
Sender ----> Packet
```

Packets may be lost, but communication is very fast.

### Why Use UDP?
- Low latency.
- Less overhead.
- Faster than TCP.

### Best For
- Video streaming.
- Real-time sensor data.
- Robotics telemetry.
- Multiplayer games.

---

## TCP vs UDP

| Feature | TCP | UDP |
|----------|-----|-----|
| Reliable | Yes | No |
| Connection Required | Yes | No |
| Packet Order Guaranteed | Yes | No |
| Speed | Slower | Faster |
| Best For | Files, Commands | Streaming, Real-time Data |

---

## 3. HTTP (HyperText Transfer Protocol)

### What is it?
- The protocol used by web browsers.
- Follows a **request-response** model.

```text
Browser ---- Request ----> Server
Browser <--- Response ---- Server
```

Example:

```text
GET /robot_status
```

Response:

```json
{
  "battery": 85,
  "speed": 0.5
}
```

### Best For
- Web dashboards.
- Robot web interfaces.
- REST APIs.

---

## 4. MQTT (Message Queuing Telemetry Transport)

### What is it?
- A lightweight **Publish-Subscribe** protocol commonly used in IoT.

### Publish-Subscribe Model

```text
Sensor ---> MQTT Broker ---> Dashboard
Robot  ---> MQTT Broker ---> Mobile App
```

Publisher:

```text
Topic = robot/status
Data = Battery = 90%
```

Subscriber:

```text
Subscribe: robot/status
```

### Best For
- IoT systems.
- Cloud-connected robots.
- Smart homes.

---

## 5. WebSocket

### What is it?
- A protocol that creates a persistent two-way connection between a browser and a server.

```text
Browser <=================> Robot Server
         Continuous Connection
```

Unlike HTTP, the connection remains open.

### Best For
- Live dashboards.
- Robot telemetry.
- Real-time web control.

---

## 6. DDS (Data Distribution Service)

### What is it?
- The middleware used internally by ROS2.
- Implements a distributed **Publish-Subscribe** system.

```text
ROS2 Node A ---- DDS ---- ROS2 Node B
```

DDS automatically:
- Discovers publishers and subscribers.
- Delivers messages.
- Manages reliability and Quality of Service (QoS).

### Why ROS2 Uses DDS
- No central server required.
- Automatic node discovery.
- Reliable communication.
- Scalable for large robotic systems.

---

## 7. ROS2 Topics

Built on top of DDS.

### Communication Model

```text
Publisher ---> Topic ---> Subscriber
```

### Best For
- Camera images.
- Sensor readings.
- Robot position.
- Battery status.

---

## 8. ROS2 Services

Built on top of DDS.

### Communication Model

```text
Client ---- Request ----> Service
Client <--- Response ---- Service
```

### Best For
- Reset robot.
- Home robotic arm.
- Start pump.

---

## 9. ROS2 Actions

Built on top of DDS.

### Communication Model

```text
Client ---- Goal ----> Action Server
       <--- Feedback ---
       <---- Result ----
```

### Best For
- Navigation.
- Painting a wall.
- Long-running robotic tasks.

---

# Relationship Between Them

```text
Application Layer
---------------------------------
ROS2 Topics / Services / Actions
HTTP
MQTT
WebSocket

Transport Layer
---------------------------------
TCP
UDP

Network Layer
---------------------------------
IP (Internet Protocol)

Physical / Wireless Layer
---------------------------------
Wi-Fi
Ethernet
Bluetooth
BLE
```

---

# Mental Model

| Technology | Think of it as... |
|------------|-------------------|
| Bluetooth Classic | Wireless UART cable |
| BLE | Smart database of services and characteristics |
| Wi-Fi | Wireless network connection |
| ESP-NOW | Direct ESP32-to-ESP32 wireless link |
| TCP | Reliable phone call |
| UDP | Sending postcards (fast but some may get lost) |
| HTTP | Asking a web server for information |
| MQTT | Publish-subscribe messaging hub |
| WebSocket | Permanent two-way conversation |
| DDS | Robot communication middleware |
| ROS2 Topic | Continuous data stream |
| ROS2 Service | Quick request-response |
| ROS2 Action | Long-running task with feedback |