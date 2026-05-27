#include "SerialCommand.h"

SerialCommand::SerialCommand() {
  command = '\0';
  value = 0;
  newCommand = false;
}

void SerialCommand::begin(int baudRate) {
  Serial.begin(baudRate);
}

void SerialCommand::update() {
  if (Serial.available() > 0) {
    command = Serial.read();      // reads f or r
    value = Serial.parseInt();    // reads number after command

    newCommand = true;
  }
}

bool SerialCommand::available() {
  if (newCommand == true) {
    newCommand = false;
    return true;
  }

  return false;
}

char SerialCommand::getCommand() {
  return command;
}

int SerialCommand::getValue() {
  return value;
}