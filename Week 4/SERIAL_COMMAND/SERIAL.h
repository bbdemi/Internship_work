#pragma once
#include <Arduino.h>

class SerialCommand {
private:
  char command;
  int value;
  bool newCommand;

public:
  SerialCommand();

  void begin(int baudRate);
  void update();

  bool available();
  char getCommand();
  int getValue();
};