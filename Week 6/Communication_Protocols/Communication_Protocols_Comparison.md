# Communication Protocols Comparison Table

| Protocol | Type | Wires Required | Topology | Data Transfer Style | Duplex | Typical Speed | Power Usage | Main Use Case |
|-----------|------|---------------|-----------|---------------------|---------|---------------|-------------|---------------|
| GPIO | Wired | 1 wire per signal | Point-to-point | Digital HIGH/LOW | N/A | Very High | Very Low | LEDs, buttons, STEP/DIR |
| UART | Wired | TX, RX, GND | Peer-to-peer | Serial stream | Full Duplex | 9.6 kbps - 5 Mbps | Low | ESP32 ↔ PC, GPS, TMC2209 |
| I2C | Wired | SDA, SCL | Master-Slave | Addressed serial communication | Half Duplex | 100 kbps - 3.4 Mbps | Very Low | Sensors, OLEDs, IMUs |
| SPI | Wired | MOSI, MISO, SCK, CS | Master-Slave | Clocked serial communication | Full Duplex | 1 - 100+ Mbps | Low | Displays, SD cards, ADCs |
| CAN Bus | Wired | CAN_H, CAN_L | Multi-master Bus | Message broadcasting | Half Duplex | Up to 1 Mbps (8 Mbps CAN-FD) | Low-Medium | Automotive, industrial robots |
| USB | Wired | D+, D- (+ Power) | Host-Device | Packet-based | Full Duplex | 12 Mbps - 10+ Gbps | Medium-High | PC ↔ Microcontroller |
| Bluetooth Classic | Wireless | None | Point-to-point | Continuous serial stream | Full Duplex | ~2 Mbps | Medium | Phone ↔ Robot control |
| BLE | Wireless | None | Client-Server (GATT) | Services & Characteristics | Full Duplex | ~1 Mbps | **Very Low** | IoT, wearables, battery-powered devices |
| Wi-Fi | Wireless | None | Network | IP packets | Full Duplex | 10 Mbps - 1 Gbps+ | **High** | ROS2 networking, video streaming |
| ESP-NOW | Wireless | None | Peer-to-peer | Packet-based | Full Duplex | ~1 Mbps | Low | ESP32 ↔ ESP32 communication |
| Zigbee | Wireless | None | Mesh Network | Packet-based | Half Duplex | 250 kbps | Very Low | Home automation, sensor networks |
| LoRa | Wireless | None | Star Network | Packet-based | Half Duplex | 0.3 - 50 kbps | Extremely Low | Long-range telemetry |

---

# Network / Software Protocols Comparison

| Protocol | Communication Model | Connection Required | Reliable | Feedback | Power Usage* | Best For |
|-----------|--------------------|--------------------|-----------|-----------|--------------|-----------|
| TCP | Client ↔ Server | Yes | Yes | No | Depends on underlying network | File transfer, reliable commands |
| UDP | Packet Transfer | No | No | No | Depends on underlying network | Streaming, real-time robotics |
| HTTP | Request → Response | Yes | Yes | Single Response | Depends on TCP/Wi-Fi | Web APIs, dashboards |
| MQTT | Publish → Broker → Subscribe | Yes | Yes | Continuous Updates | Low | IoT systems |
| WebSocket | Persistent Two-Way Connection | Yes | Yes | Continuous | Medium | Live dashboards, telemetry |
| DDS | Publish-Subscribe Middleware | Automatic Discovery | Configurable (QoS) | Continuous | Medium | ROS2 communication |
| ROS2 Topic | Publish → Subscribe | Automatic | Depends on DDS QoS | No | Depends on DDS | Sensor data, robot state |
| ROS2 Service | Client → Server → Response | Automatic | Yes | Single Response | Depends on DDS | Reset, start, stop commands |
| ROS2 Action | Goal → Feedback → Result | Automatic | Yes | Yes | Depends on DDS | Long-running robot tasks |

> **Note:** Network/software protocols do not directly determine power consumption. Their effective power usage depends largely on the underlying physical communication medium (Wi-Fi, Ethernet, BLE, etc.).

---

# Wireless Protocol Power Comparison

| Protocol | Relative Power Consumption | Typical Applications |
|-----------|--------------------------|----------------------|
| BLE | ⭐ Very Low | Fitness bands, IoT sensors |
| Zigbee | ⭐ Very Low | Home automation |
| LoRa | ⭐ Extremely Low | Remote telemetry |
| ESP-NOW | ⭐⭐ Low | ESP32 device communication |
| Bluetooth Classic | ⭐⭐⭐ Medium | Robot remote control |
| Wi-Fi | ⭐⭐⭐⭐⭐ High | ROS2 networking, video streaming |