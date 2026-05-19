const int servoPin = 19;
const int buttonPin = 23;

const int redPin = 5;
const int greenPin = 21;
const int bluePin = 22;

int angle = 0;
int state = 0;

int lastButtonState = HIGH;

void setup() {
  Serial.begin(115200);

  pinMode(servoPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  turnOffLED();
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    state++;

    if (state > 3) {
      state = 0;
    }

    if (state == 0) {
      angle = 0;
      setColorRed();
    }
    else if (state == 1) {
      angle = 60;
      setColorGreen();
    }
    else if (state == 2) {
      angle = 120;
      setColorBlue();
    }
    else if (state == 3) {
      angle = 180;
      setColorYellow();
    }

    Serial.print("State: ");
    Serial.print(state);
    Serial.print(" | Servo angle: ");
    Serial.println(angle);

    holdServo(angle, 500);

    delay(250);
  }

  lastButtonState = buttonState;

  holdServo(angle, 20);
}

void holdServo(int angle, int durationMs) {
  int pulseWidth = 500 + (2000 * angle) / 180;
  int cycles = durationMs / 20;

  for (int i = 0; i < cycles; i++) {
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulseWidth);

    digitalWrite(servoPin, LOW);
    delayMicroseconds(20000 - pulseWidth);
  }
}

// Common anode RGB LED functions

void turnOffLED() {
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
}

void setColorRed() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
}

void setColorGreen() {
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, HIGH);
}

void setColorBlue() {
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, LOW);
}

void setColorYellow() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, HIGH);
}