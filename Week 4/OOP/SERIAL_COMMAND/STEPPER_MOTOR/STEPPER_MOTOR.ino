#include "LED.h"
#include "Button.h"
#include "STEPPER"

STEPPER motor1(26,27,32);
LED led1(18);
Button button1(23);

bool ledState = false;

void setup() {
  Serial.begin(115200);
  motor1.begin();

  led1.begin();
  button1.begin();
}

void loop() {
  motor1.forward(500);
  motor1.reverse(500);
}