# Communication Protocols Comparison Table

| Protocol | Full Form | Type | Wires Required | Topology | Data Transfer Style | Duplex | Typical Speed | Main Use Case |
|-----------|-----------|------|---------------|-----------|---------------------|---------|---------------|---------------|
| GPIO | General Purpose Input/Output | Wired | 1 wire per signal | Point-to-point | Digital HIGH/LOW | N/A | Very High | LEDs, buttons, STEP/DIR |
| UART | Universal Asynchronous Receiver Transmitter | Wired | TX, RX, GND | Peer-to-peer | Serial stream | Full Duplex | 9.6 kbps - 5 Mbps | ESP32 ↔ PC, GPS, Bluetooth |
| I2C | Inter-Integrated Circuit | Wired | SDA, SCL | Master-Slave | Addressed serial communication | Half Duplex | 100 kbps - 3.4 Mbps | Sensors, OLEDs, IMUs |
| SPI | Serial Peripheral Interface | Wired | MOSI, MISO, SCK, CS | Master-Slave | Clocked serial communication | Full Duplex | 1 - 100+ Mbps | Displays, SD cards, high-speed sensors |
| CAN Bus | Controller Area Network | Wired | CAN_H, CAN_L | Multi-master Bus | Message broadcasting | Half Duplex | Up to 1 Mbps (CAN), 8 Mbps (CAN-FD) | Automotive, industrial robots |
| USB | Universal Serial Bus | Wired | D+, D- (+ power) | Host-Device | Packet-based | Full Duplex | 12 Mbps - 10+ Gbps | PC ↔ Microcontroller |
| Bluetooth Classic | - | Wireless | None | Point-to-point | Continuous serial stream | Full Duplex | ~2 Mbps | Phone ↔ Robot control |
| BLE | Bluetooth Low Energy | Wireless | None | Client-Server (GATT) | Services & Characteristics | Full Duplex | ~1 Mbps | IoT, wearables |
| Wi-Fi | Wireless Fidelity | Wireless | None | Network | IP-based packets | Full Duplex | 10 Mbps - 1 Gbps+ | ROS2 networking, video streaming |
| ESP-NOW | Espressif Peer-to-Peer | Wireless | None | Peer-to-peer | Packet-based | Full Duplex | ~1 Mbps | ESP32 ↔ ESP32 communication |
| Zigbee | - | Wireless | None | Mesh Network | Packet-based | Half Duplex | 250 kbps | Home automation, sensor networks |
| LoRa | Long Range | Wireless | None | Star Network | Packet-based | Half Duplex | 0.3 - 50 kbps | Long-range telemetry |

---

# Network / Software Protocols Comparison

| Protocol | Communication Model | Connection Required | Reliable | Feedback | Best For |
|-----------|--------------------|--------------------|-----------|-----------|-----------|
| TCP | Client ↔ Server | Yes | Yes | No | File transfer, web, reliable commands |
| UDP | Packet Transfer | No | No | No | Streaming, real-time robotics |
| HTTP | Request → Response | Yes | Yes | Single Response | Web APIs, dashboards |
| MQTT | Publish → Broker → Subscribe | Yes | Yes | Continuous Updates | IoT systems |
| WebSocket | Persistent Two-Way Connection | Yes | Yes | Continuous | Live dashboards, telemetry |
| DDS | Publish-Subscribe Middleware | Automatic Discovery | Configurable (QoS) | Continuous | ROS2 communication |
| ROS2 Topic | Publish → Subscribe | Automatic | Depends on DDS QoS | No | Sensor data, robot state |
| ROS2 Service | Client → Server → Response | Automatic | Yes | Single Response | Reset, start, stop commands |
| ROS2 Action | Goal → Feedback → Result | Automatic | Yes | Yes | Long-running robot tasks |

---

# Comparison of Communication Models

| Communication Model | Used By | Description | Example |
|---------------------|----------|-------------|----------|
| Point-to-Point | UART, Bluetooth Classic | One device communicates directly with another | ESP32 ↔ PC |
| Master-Slave | I2C, SPI | Master controls one or more slave devices | ESP32 ↔ IMU |
| Multi-Master Bus | CAN Bus | Multiple devices share the same bus | Automotive ECUs |
| Client-Server | HTTP, ROS2 Services | Client requests, server responds | Reset robot |
| Publish-Subscribe | MQTT, DDS, ROS2 Topics | Publisher sends data, subscribers receive | Camera images |
| Goal-Feedback-Result | ROS2 Actions | Long-running task with progress updates | Navigation |

---

# Which Protocol Should I Use?

| Requirement | Recommended Protocol |
|-------------|---------------------|
| Turn LED ON/OFF | GPIO |
| Read IMU/OLED | I2C |
| Connect SD Card or Display | SPI |
| Configure TMC2209 | UART |
| Control Stepper Motion | STEP/DIR (GPIO) |
| Communicate with PC | USB/UART |
| Phone → ESP32 Control | Bluetooth Classic |
| Battery-powered IoT Sensor | BLE |
| ESP32 ↔ ESP32 Wireless | ESP-NOW |
| Industrial Robot Network | CAN Bus |
| ROS2 Multi-Computer Setup | Wi-Fi + DDS |
| Stream Sensor Data | ROS2 Topics |
| Quick Robot Command | ROS2 Service |
| Long-Running Robot Task | ROS2 Action |

---

# One-Line Summary

| Category | Main Protocols |
|-----------|----------------|
| Simple Digital Signals | GPIO, PWM, STEP/DIR |
| Sensor Communication | I2C, SPI, 1-Wire |
| Device-to-Device Communication | UART, USB |
| Industrial Communication | CAN Bus |
| Wireless Local Communication | Bluetooth Classic, ESP-NOW |
| Low-Power Wireless | BLE, Zigbee |
| Long-Range Wireless | LoRa |
| Network Communication | Wi-Fi |
| Reliable Data Transfer | TCP |
| Fast Real-Time Data | UDP |
| Web Communication | HTTP, WebSocket |
| IoT Messaging | MQTT |
| Robot Middleware | DDS |
| ROS2 Communication | Topics, Services, Actions |