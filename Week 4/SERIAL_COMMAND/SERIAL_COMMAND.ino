#include "STEPPER.h"
#include "SerialCommand.h"

STEPPER motor1(26, 27, 32);
SerialCommand serialCmd;

void setup() {
  motor1.begin();
  serialCmd.begin(115200);

  Serial.println("Stepper Serial Control Started");
  Serial.println("Commands:");
  Serial.println("f 3200 -> forward 3200 steps");
  Serial.println("r 3200 -> reverse 3200 steps");
}

void loop() {
  serialCmd.update();

  if (serialCmd.available()) {
    char command = serialCmd.getCommand();
    int steps = serialCmd.getValue();

    if (command == 'f') {
      Serial.print("Forward steps: ");
      Serial.println(steps);
      motor1.forward(steps);
    }

    else if (command == 'r') {
      Serial.print("Reverse steps: ");
      Serial.println(steps);
      motor1.reverse(steps);
    }

    else {
      Serial.println("Invalid command. Use f 3200 or r 3200");
    }
  }
}