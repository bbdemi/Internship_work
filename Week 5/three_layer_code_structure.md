# Three-Layer Code Structure

This project uses a three-layer structure to keep hardware code, driver logic, and application logic separate.

## 1. Interface Layer

Example:

```cpp
class IUart {
public:
    virtual int available() = 0;
    virtual int read() = 0;
    virtual void write(uint8_t byte) = 0;
};
```

Purpose:

- Defines what functions are required.
- Does not depend on real hardware.
- Makes code testable using mocks.

Example implementations:

```text
IUart
├── Esp32Uart
└── MockUart
```

---

## 2. Hardware Abstraction Layer

Example:

```cpp
class Esp32Uart : public IUart {
private:
    HardwareSerial& _serial;

public:
    int available() override;
    int read() override;
    void write(uint8_t byte) override;
};
```

Purpose:

- Wraps real ESP32 hardware like `Serial`, `Serial1`, or `Serial2`.
- Converts hardware-specific functions into our common interface.
- Keeps ESP32-specific code in one place.

Example:

```text
Esp32Uart wraps Serial2
```

---

## 3. Application / Driver Layer

Example:

```cpp
class CommandParser {
private:
    IUart& _stream;
    StepperDriver& _stepper;
    ServoDriver& _servo;
};
```

Purpose:

- Uses interfaces and drivers to perform actual robot behavior.
- Does not directly depend on ESP32 hardware.
- Can work with real hardware or mock objects.

Example:

```text
CommandParser reads UART commands
s100 -> stepper.move(100)
v90  -> servo.setAngle(90)
x    -> stepper.stop()
```

---

## Full Structure

```text
IUart
  └── Esp32Uart
        └── CommandParser
              ├── StepperDriver
              └── ServoDriver
```

Another way to see it:

```text
Interface Layer
    IUart

Hardware Layer
    Esp32Uart

Application Layer
    CommandParser
    StepperDriver
    ServoDriver
```

---

## Why This Structure Is Useful

- Keeps code modular.
- Avoids mixing hardware code with logic.
- Makes unit testing easier.
- Allows mock objects for tests.
- Makes it easier to replace hardware later.

Example:

```cpp
MockUart mock;
CommandParser parser(mock, stepper, servo);
```

The same `CommandParser` can be tested without connecting an ESP32.

---

## Key Idea

```text
High-level code should depend on interfaces, not directly on hardware.
```

This makes embedded code cleaner, testable, and easier to maintain.
