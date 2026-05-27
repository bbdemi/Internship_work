#pragma once
#include <Arduino.h>

class Button {
private:
  int pin;

  bool lastStableState;
  bool lastReading;
  unsigned long lastDebounceTime;
  unsigned long debounceDelay;

public:
  Button(int butPin);

  void begin();
  bool isPressed();
  bool wasClicked();
};