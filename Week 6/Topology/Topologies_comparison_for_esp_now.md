# Topology Comparison Table

| Topology | Structure | Central Controller Required | Number of Devices | Fault Tolerance | Scalability | Typical Communication Style | Main Advantages | Main Disadvantages | Typical Protocols / Examples | Best Use Cases |
|------------|-----------|---------------------------|------------------|----------------|-------------|-----------------------------|-----------------|-------------------|-----------------------------|----------------|
| **Point-to-Point** | Two devices communicate directly. | No | 2 | Low | Poor | Direct communication | Simple, low latency, easy to implement. | Only supports two devices. | UART, Bluetooth Classic, ESP-NOW (2 nodes) | ESP32 ↔ ESP32, ESP32 ↔ PC, wireless remote control. |
| **Master-Slave** | One master controls one or more slave devices. | Yes (Master) | Many | Medium | Good | Master initiates all communication. | Easy to manage, simple protocol design. | Slaves cannot communicate directly with each other. | I2C, SPI | Connecting multiple sensors and peripherals to a microcontroller. |
| **Bus** | All devices share one common communication line. | Usually No (depends on protocol) | Many | Medium | Good | Shared bus with arbitration. | Less wiring, easy to add devices. | Bus failure affects everyone; collisions must be handled. | CAN Bus, I2C (physical bus) | Automotive systems, industrial robots, factory automation. |
| **Star** | All devices connect to a central hub/router. | Yes (Hub/Router) | Many | Medium | Excellent | Devices communicate through central node. | Easy expansion and management. | Failure of hub/router brings down entire network. | Wi-Fi, Ethernet LAN | Home networks, ROS2 over Wi-Fi, IoT gateways. |
| **Mesh** | Devices connect to multiple neighboring devices. | No | Many | **High** | Excellent | Messages can hop through intermediate nodes. | Self-healing, highly reliable, no single point of failure. | More complex routing and higher overhead. | Zigbee, Thread | Large IoT networks, distributed sensor networks, robot swarms. |

---

# Topology Selection Guide

| If your application is... | Recommended Topology | Why? |
|---------------------------|----------------------|------|
| Two ESP32s communicating directly | Point-to-Point | Simplest and lowest latency. |
| One ESP32 controlling many sensors | Master-Slave | Master can poll all peripherals efficiently. |
| Many embedded controllers sharing a common cable | Bus | Reduces wiring complexity. |
| Devices communicating through a router or access point | Star | Centralized management and easy scaling. |
| Large distributed sensor network with node failures expected | Mesh | Alternate paths allow self-healing. |
| Robot swarm with many nearby nodes | Mesh | Nodes can relay messages to distant robots. |
| Industrial automation / automotive electronics | Bus (CAN) | Robust, reliable, and supports many devices. |
| Phone controlling a single robot | Point-to-Point (Bluetooth) | Direct communication is sufficient. |
| Laptop controlling multiple robots over Wi-Fi | Star | Router acts as central communication hub. |

---

# Which Topology for My ESP-NOW Projects?

| Project | Recommended Topology | Example |
|-----------|----------------------|----------|
| One ESP32 sending LED commands to another | Point-to-Point | ESP32 A → ESP32 B |
| Servo ESP sending commands to Stepper ESP | Point-to-Point | Current ball-hitting project |
| One master ESP controlling multiple actuator ESPs | Star-like (Master + Multiple Peers) | Master → Servo Node, Stepper Node, Sensor Node |
| Multiple ESP32s forwarding messages to each other | Mesh | Robot swarm or distributed sensors |
| Multiple ESP32s sharing one common wired bus | Bus | CAN-based robot architecture |
