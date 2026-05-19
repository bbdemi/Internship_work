# Servo Motor Projects

A collection of three Arduino-based servo motor projects, ranging from smooth automated motion to interactive button and LED control.
 
---

## Table of Contents

- [Project 1: Smooth Servo](#project-1-smooth-servo)
- [Project 2: Button Servo](#project-2-button-servo)
- [Project 3: LED + Servo + Button](#project-3-led--servo--button)
- [Hardware Requirements](#hardware-requirements)
- [Getting Started](#getting-started)
- [Troubleshooting](#troubleshooting)
---

## Project 1: Smooth Servo

### Overview
Moves a servo motor smoothly from 0° to 180° and back in a continuous loop using incremental angle steps, avoiding the jerky motion of direct position jumps.

### Features
- Gradual sweep motion using small degree increments
- Adjustable speed via delay between steps
- Continuous back-and-forth loop
### Components
- Arduino Uno (or compatible)
- 1× Servo motor (SG90 or MG996R)
- Jumper wires
- External 5V power supply (recommended for MG996R)
### Wiring

| Servo Wire | Arduino Pin |
|------------|-------------|
| Signal (Orange/Yellow) | Pin 9 |
| VCC (Red) | 5V |
| GND (Brown/Black) | GND |

### How It Works
Two loops increment and decrement the servo angle one degree at a time with a short delay between each step. Decreasing the delay speeds up the motion; increasing it slows things down. The servo sweeps forward then backward in a continuous cycle.
 
---

## Project 2: Button Servo

### Overview
Controls servo position using a push button. Each press toggles the servo between 0° and 180°, making it ideal for simple open/close or lock/unlock mechanisms.

### Features
- Button-triggered servo toggle
- Debounce logic to prevent false triggers
- Two-position control (fully open / fully closed)
### Components
- Arduino Uno (or compatible)
- 1× Servo motor
- 1× Push button
- 1× 10kΩ resistor (pull-down)
- Jumper wires
### Wiring

| Component | Arduino Pin |
|-----------|-------------|
| Servo Signal | Pin 9 |
| Servo VCC | 5V |
| Servo GND | GND |
| Button (one leg) | Pin 2 |
| Button (other leg) | 5V |
| 10kΩ Resistor | Between Pin 2 and GND |

### How It Works
The sketch reads the button every loop. When a LOW→HIGH transition is detected, a 50ms debounce delay filters out noise, then the servo toggles position. A variable tracking the last button state ensures the servo only moves once per press.
 
---

## Project 3: LED + Servo + Button

### Overview
Combines a button, servo motor, and LED into one interactive system. Pressing the button moves the servo to the target position and lights the LED; pressing again returns the servo and turns the LED off.

### Features
- Visual feedback via LED (ON when servo is at target position)
- Button-controlled servo toggle
- Real-time status indicator for servo position
- Debounced button input
### Components
- Arduino Uno (or compatible)
- 1× Servo motor
- 1× Push button
- 1× LED (any color)
- 1× 220Ω resistor (for LED)
- 1× 10kΩ resistor (pull-down for button)
- Jumper wires
### Wiring

| Component | Arduino Pin |
|-----------|-------------|
| Servo Signal | Pin 9 |
| Servo VCC | 5V |
| Servo GND | GND |
| Button (one leg) | Pin 2 |
| Button (other leg) | 5V |
| 10kΩ Resistor | Between Pin 2 and GND |
| LED Anode (+) | Pin 7 (via 220Ω resistor) |
| LED Cathode (−) | GND |

### How It Works
A boolean variable tracks whether the servo is in the open or closed position. On each valid button press, the state flips — the servo moves to 180° and the LED turns ON, or the servo returns to 0° and the LED turns OFF. This makes the LED a live indicator of the servo's current position.
 
---

## Hardware Requirements

| Item | Quantity | Notes |
|------|----------|-------|
| Arduino Uno | 1 | Any compatible board works |
| Servo Motor (SG90) | 1 | Use MG996R for heavier loads |
| Push Button | 1 | Projects 2 & 3 |
| LED | 1 | Project 3 only |
| 220Ω Resistor | 1 | LED current limiting |
| 10kΩ Resistor | 1 | Button pull-down |
| Jumper Wires | Several | Male-to-male recommended |
| Breadboard | 1 | Optional but helpful |
 
---

## Getting Started

1. Install the Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software)
2. Connect your Arduino via USB
3. Wire up the components using the wiring tables above
4. Open the sketch for the project you want to run
5. Select your board and port under Tools > Board and Tools > Port
6. Upload the sketch using the Upload button
7. Open Serial Monitor at 9600 baud for optional debugging
---

## Troubleshooting

**Servo jitters or doesn't move** — Check the signal wire is on Pin 9. Use an external 5V supply for the servo if drawing too much current from the Arduino.

**Button triggers multiple times per press** — Increase the debounce delay from 50ms to 100ms.

**LED doesn't light up** — Verify the 220Ω resistor is in series with the LED anode and confirm polarity (longer leg = anode).

**Servo moves to the wrong position** — Swap the 0° and 180° values in the code to reverse direction.
 
---
