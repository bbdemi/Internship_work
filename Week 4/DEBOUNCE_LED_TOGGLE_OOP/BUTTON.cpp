#include "Button.h"

Button::Button(int butPin) {
  pin = butPin;

  lastStableState = HIGH;
  lastReading = HIGH;
  lastDebounceTime = 0;
  debounceDelay = 50;
}

void Button::begin() {
  pinMode(pin, INPUT_PULLUP);

  lastStableState = digitalRead(pin);
  lastReading = lastStableState;
}

bool Button::isPressed() {
  return digitalRead(pin) == LOW;
}

bool Button::wasClicked() {
  bool currentReading = digitalRead(pin);

  if (currentReading != lastReading) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (currentReading != lastStableState) {
      lastStableState = currentReading;

      if (lastStableState == LOW) {
        lastReading = currentReading;
        return true;
      }
    }
  }

  lastReading = currentReading;
  return false;
}