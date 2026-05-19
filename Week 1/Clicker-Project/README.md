# ESP32 Clicker / Switch Project

## Objective

The objective of this project was to understand how to take digital input from a push button or clicker switch using ESP32.

This project helped me learn how microcontrollers read external input signals.

---

## Work Done

- Connected a push button / clicker switch to the ESP32.
- Configured the ESP32 pin as an input pin.
- Used `INPUT_PULLUP` to read button press events.
- Wrote code to detect when the button was clicked.
- Printed button click messages on the Serial Monitor.
- Tested the button response multiple times.

---

## Components Used

- ESP32 development board
- Push button / clicker switch
- Breadboard
- Jumper wires
- USB cable
- Laptop with Arduino IDE

---


When `INPUT_PULLUP` is used:

- Button not pressed = `HIGH`
- Button pressed = `LOW`

---

## Code Logic

1. Define the button pin.
2. Set the button pin as `INPUT_PULLUP`.
3. Read the button state using `digitalRead()`.
4. If the button value is `LOW`, the button is pressed.
5. Print a message on the Serial Monitor when the button is clicked.
6. Use a small delay to avoid multiple unwanted readings.

---

## Key Learnings

- Learned how to use ESP32 GPIO pins as digital inputs.
- Understood the concept of `INPUT_PULLUP`.
- Learned why a pressed button gives `LOW` when internal pull-up is used.
- Practiced reading button input using `digitalRead()`.
- Learned how to use the Serial Monitor for debugging.
- Understood basic debounce delay for button clicks.

---

## Problems Faced

- Initially, button behavior was confusing because pressed state became `LOW`.
- Loose connections caused inconsistent button readings.
- Without delay/debounce, one button press could be detected multiple times.

---

## Status

Completed.

---

## Notes

This project helped me understand how ESP32 reads external input. It also helped me learn the difference between digital input and digital output in embedded systems.