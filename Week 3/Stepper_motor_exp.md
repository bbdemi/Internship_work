# Stepper Motor Notes

---

# Stepper Motor Basics

A **stepper motor** rotates in discrete steps instead of rotating continuously like a DC motor.

Each pulse sent to the motor driver moves the motor by **one step**.

## STEP and DIR Pins

Stepper drivers are generally controlled using two pins:

- **STEP** → A pulse on this pin moves the motor one step.
- **DIR** → Controls the rotation direction.

Example:

```
DIR = HIGH  -> Clockwise (CW)
DIR = LOW   -> Anti-Clockwise (ACW)
```

> *(Direction depends on wiring and driver configuration. It can be reversed if needed.)*

---

# Step Angle

Most NEMA-17 stepper motors have:

```
1 Full Step = 1.8°
```

Therefore,

```
360° / 1.8° = 200 steps
```

So,

- 200 steps = 1 revolution

---

# Why Stepper Motors Skip Steps

A stepper motor can lose synchronization if it cannot keep up with the commanded motion.

Common reasons:

- Speed is too high
- Acceleration is too sudden
- Mechanical load is too high
- Motor current is too low
- Incorrect wiring
- Weak or unstable power supply

Because of this, it is important to use:

- Smooth acceleration
- Smooth deceleration

instead of instantly running at maximum speed.

---

# Microstepping

A stepper driver can divide one full step into smaller steps.

Benefits:

- Smoother motion
- Better positioning
- Less vibration
- Reduced noise

Example:

| Mode | Steps per Revolution |
|------|----------------------|
| Full Step | 200 |
| 1/2 Step | 400 |
| 1/4 Step | 800 |
| 1/8 Step | 1600 |
| 1/16 Step | 3200 |

Example:

```
1/16 Microstepping

200 × 16 = 3200 steps/revolution
```

---

# Position Control

A stepper motor is controlled by **counting pulses**.

Example:

```
Current Position = 0

Move 500 steps
↓

Current Position = 500

Move back 200 steps
↓

Current Position = 300
```

The controller always keeps track of the current position by counting the number of steps sent.

---

# Homing

When the ESP32 starts, it **does not know the actual position** of the motor.

To establish a reference point, a **homing sequence** is performed.

Typical procedure:

1. Move slowly toward the limit switch.
2. When the limit switch is pressed:
   - Stop the motor.
   - Set the current position to **0**.
3. Future movements are measured relative to this position.

```
Limit Switch Hit
↓

Current Position = 0
```

---

# ENABLE Pin

Most stepper drivers have an **ENABLE** pin.

Purpose:

- Turns the driver ON or OFF.

Typical behavior:

```
ENABLE LOW  -> Driver Enabled
ENABLE HIGH -> Driver Disabled
```

*(Depends on the driver being used.)*

---

# Practical Experiment (22-05-2026)

## Direction Pin

Observed:

```
DIR HIGH -> ACW
DIR LOW  -> CW
```

*(May vary depending on motor wiring.)*

---

## 1/16 Microstepping

With 1/16 microstepping enabled:

```
3200 steps
↓

360°
```

---

# Stepper Acceleration

Instead of immediately running the motor at full speed,

```
Start Slow
↓

Accelerate

↓

Run at Maximum Speed

↓

Decelerate

↓

Stop
```

This prevents skipped steps.

---

# Delay-Based Speed Control

Motor speed is controlled by changing the delay between STEP pulses.

Example:

```
1500 µs
↓

1200 µs

↓

1000 µs

↓

800 µs
```

Smaller delay:

- Faster motor

Larger delay:

- Slower motor

---

# Simple Acceleration Algorithm

Suppose the motor has to move:

```
Total Steps = N
```

Divide the motion into three parts.

```
First 1/3
↓

Acceleration

Middle 1/3
↓

Constant Speed

Last 1/3
↓

Deceleration
```

Pseudo-code:

```cpp
if (i < steps / 3)
{
    // Accelerate
}
else if (i < 2 * steps / 3)
{
    // Constant speed
}
else
{
    // Decelerate
}
```

---

# Key Takeaways

- Stepper motors move in fixed angular increments.
- One STEP pulse equals one motor step.
- DIR controls rotation direction.
- A standard stepper has 200 full steps per revolution.
- Microstepping increases resolution and smoothness.
- High speed or sudden acceleration can cause skipped steps.
- Use acceleration and deceleration profiles for reliable motion.
- Position is determined by counting pulses.
- Homing establishes a known reference position using a limit switch.
- ENABLE pin turns the driver on or off.
- Speed is controlled by adjusting the delay between STEP pulses.