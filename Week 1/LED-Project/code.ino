const int redPin = 5;
const int greenPin = 21;
const int bluePin = 22;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Start with LED OFF
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
}

void loop() {
  // Red
  setColor(LOW, HIGH, HIGH);
  delay(1000);

  // Green
  setColor(HIGH, LOW, HIGH);
  delay(1000);

  // Blue
  setColor(HIGH, HIGH, LOW);
  delay(1000);

  // Yellow = Red + Green
  setColor(LOW, LOW, HIGH);
  delay(1000);

  // Cyan = Green + Blue
  setColor(HIGH, LOW, LOW);
  delay(1000);

  // Purple = Red + Blue
  setColor(LOW, HIGH, LOW);
  delay(1000);

  // White = Red + Green + Blue
  setColor(LOW, LOW, LOW);
  delay(1000);

  // OFF
  setColor(HIGH, HIGH, HIGH);
  delay(1000);
}

void setColor(int redState, int greenState, int blueState) {
  digitalWrite(redPin, redState);
  digitalWrite(greenPin, greenState);
  digitalWrite(bluePin, blueState);
}