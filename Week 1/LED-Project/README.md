# ESP32 LED Project

## Objective

The objective of this project was to understand how to control an LED using an ESP32 GPIO pin.

This project helped me learn the basics of digital output control in embedded systems.

---

## Work Done

- Connected an LED to the ESP32 using a breadboard and jumper wires.
- Used a resistor to limit current through the LED.
- Wrote Arduino code to turn the LED ON and OFF.
- Tested different GPIO pins for LED control.
- Observed how changing the code changes the LED output.
- Practiced uploading code to ESP32 using Arduino IDE.

---

## Components Used

- ESP32 development board
- LED
- Resistor
- Breadboard
- Jumper wires
- USB cable
- Laptop with Arduino IDE

---


## Code Logic

1. Define the LED pin.
2. Set the LED pin as `OUTPUT` using `pinMode()`.
3. Turn the LED ON using `digitalWrite(pin, HIGH)`.
4. Turn the LED OFF using `digitalWrite(pin, LOW)`.
5. Use `delay()` to control blinking time.

---

## Key Learnings

- Learned how to use ESP32 GPIO pins as digital outputs.
- Understood how an LED circuit is connected.
- Learned why a resistor is needed with an LED.
- Practiced uploading code from Arduino IDE to ESP32.
- Understood the use of `pinMode()`, `digitalWrite()`, and `delay()`.

---

## Problems Faced

- LED did not glow when the wiring was incorrect.
- Wrong GPIO pin selection caused no output.
- Loose breadboard connections caused inconsistent behavior.

---

## Status

Completed.

---


## Notes

This was one of the first basic embedded projects completed during the internship. It helped me understand GPIO output control, circuit wiring, and basic hardware debugging.