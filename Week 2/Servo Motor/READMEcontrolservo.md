# Servo Motor Control using ESP32

This project demonstrates how to control a servo motor using an ESP32.  
The servo motor is controlled by generating PWM-like pulses manually using Arduino code.

## Components Required

- ESP32 development board
- Servo motor
- External 5V power supply or battery
- Jumper wires
- Breadboard
- Common ground connection

## Working Principle

A servo motor is controlled by sending repeated pulses.

Usually:

| Pulse Width | Servo Angle |
|------------|-------------|
| 500 µs | 0° |
| 1500 µs | 90° |
| 2500 µs | 180° |

Each pulse is repeated approximately every 20 milliseconds.

The ESP32 sends a HIGH signal for a fixed number of microseconds, then keeps the signal LOW for the remaining time.

There is a linear relationship between angle and pulse width so whatever angle user inputs we can calculate pulse width required and accordingly instruct motor.
