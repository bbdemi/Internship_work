#include "LED.h"
#include "Button.h"

LED led1(18);
Button button1(23);

bool ledState = false;

void setup() {
  Serial.begin(115200);

  led1.begin();
  button1.begin();
}

void loop() {
  led1.blinkwithoutdelay(1000);
  if (button1.wasClicked()) {
      led1.toggle();
  }
}