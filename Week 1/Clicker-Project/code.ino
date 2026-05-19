const int buttonPin = 23;

void setup() {
  Serial.begin(115200);

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.println("Clicker ready");
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    Serial.println("Button Clicked!");

    delay(300); // debounce delay
  }
}