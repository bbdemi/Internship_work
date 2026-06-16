# Topologies

A **topology** is simply the **way devices are connected and communicate with each other in a network**.

In other words, it describes the **layout or structure of the communication network**.

---

## 1. Point-to-Point Topology

Two devices communicate directly.

```text
ESP32 A  <-------->  ESP32 B
```

### Characteristics
- Simple and easy to implement.
- Only two devices are involved.
- Used in UART, Bluetooth Classic, and ESP-NOW (between two devices).

---

## 2. Master-Slave Topology

One device controls communication (**Master**), and one or more devices respond (**Slaves**).

```text
           Master (ESP32)
             /    |    \
            /     |     \
      Sensor1  OLED   IMU
       Slave   Slave  Slave
```

### Characteristics
- Master initiates all communication.
- Slaves only respond when requested.
- Used in protocols like **I2C** and **SPI**.

---

## 3. Bus Topology

A **bus topology** means all devices are connected to one common communication line (the **bus**).

Think of it like a **single road that everyone shares**.

```text
========================================
|        |         |         |         |
ESP1    ESP2     ESP3      ESP4      ESP5
========================================
          Shared Communication Bus
```

### Characteristics
- All devices share the same communication medium.
- Every device can see the messages on the bus.
- Requires a mechanism to avoid collisions.
- Used in **CAN Bus** and physically in **I2C**.

---

## 4. Star Topology

All devices connect to a central node (hub, router, or access point).

```text
            Wi-Fi Router
           /     |      \
          /      |       \
     Laptop   ESP32    Phone
```

### Characteristics
- Easy to manage and expand.
- The central node controls communication.
- If the central node fails, the whole network goes down.
- Used in **Wi-Fi** and most modern LANs.

---

## 5. Mesh Topology

A **mesh topology** means devices are connected to multiple neighboring devices, and messages can travel through intermediate devices to reach their destination.

```text
        Node A
       /      \
      /        \
   Node B ---- Node C
      \        /
       \      /
        Node D
```

### How it Works

Suppose **Node A** wants to communicate with **Node D**.

Normally, it may use the path:

```text
A ----> B ----> D
```

If **Node B fails**, the network automatically finds another route:

```text
A ----> C ----> D
```

This ability to automatically use an alternate path is called **self-healing**.

### Characteristics
- Multiple paths exist between devices.
- Very reliable and fault tolerant.
- Commonly used in **Zigbee** and other IoT sensor networks.

---