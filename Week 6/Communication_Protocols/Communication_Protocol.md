# Communication Protocols Notes

## 1. GPIO
**General Purpose Input/Output**

- GPIO pin can only be **HIGH** or **LOW**.
- Uses **one wire per signal**.
- Used for simple digital control.

---

## 2. UART
**Universal Asynchronous Receiver Transmitter**

- Sends data **one bit after another over a single wire**.
- Uses three main connections:
  - **TX** (Transmit)
  - **RX** (Receive)
  - **GND** (Ground)

---

## 3. I2C
**Inter-Integrated Circuit**

- Used to connect **many low-speed peripherals** using only **two wires**.
- Uses:
  - **SDA** (Data)
  - **SCL** (Clock)

### Master-Slave Concept
- **Master:** Controls communication (usually the ESP32).
- **Slave:** Responds when addressed.

### Advantage
You may have **10 sensors** but only use **two communication pins**.

---

## 4. SPI
**Serial Peripheral Interface**

- High-speed serial communication protocol.
- Unlike I2C, SPI uses more wires.

### Signals
- **MOSI** (Master Out Slave In)
- **MISO** (Master In Slave Out)
- **SCK** (Clock)
- **CS/SS** (Chip Select / Slave Select)

### How It Works
- The **Master generates the clock**.
- For every clock pulse:
  - One bit goes from **Master → Slave**.
  - One bit can simultaneously come from **Slave → Master**.

This makes **SPI full duplex**.

---

## 5. CAN Bus
**Controller Area Network**

- Designed for **automobiles** and **industrial systems**.
- Multiple devices share the same communication bus.
- Highly reliable and robust against electrical noise.

---

## 6. USB
**Universal Serial Bus**

- Much more complicated internally than UART.
- Used for communication between PCs and embedded devices.

**Note:**  
When you open the Arduino Serial Monitor, USB is carrying your UART data to the PC through a **USB-to-UART converter chip**.

---

## 7. Bluetooth Classic

- Think of it as a **wireless UART cable**.
- Gives out data as a **continuous serial stream**.
- Ideal for remote control applications.

---

## 8. BLE
**Bluetooth Low Energy**

- Designed for **battery-powered devices**.
- Organizes communication into:
  - **Services**
  - **Characteristics**
- Commonly used in IoT and wearable devices.

---

## 9. Wi-Fi

- Provides full **IP networking**.
- Allows a robot to join a local network and exchange data using protocols like:
  - TCP
  - UDP
  - DDS (used by ROS 2)
  - HTTP

---

# Big Picture

## Communication Protocols by Purpose

| Purpose | Common Protocols |
|----------|------------------|
| Simple digital control | GPIO, PWM, STEP/DIR |
| Microcontroller ↔ Sensor | I2C, SPI, 1-Wire |
| Microcontroller ↔ Another Device | UART, USB |
| Industrial communication | CAN Bus |
| Wireless local control | Bluetooth Classic |
| Low-power IoT | BLE |
| Network communication | Wi-Fi |