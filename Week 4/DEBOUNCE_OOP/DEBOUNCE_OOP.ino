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
  if (button1.wasClicked()) {
    ledState = !ledState;

    if (ledState) {
      led1.on();
      Serial.println("LED ON");
    } else {
      led1.off();
      Serial.println("LED OFF");
    }
  }
}