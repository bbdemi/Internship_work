const int servoPin = 19;
const int buttonPin=23;

int current=0;

void setup() {
Serial.begin(115200);
  pinMode(servoPin, OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);
}

void loop() {
 if(digitalRead(buttonPin)==LOW)
 {
  int target=current+30;
  if(target>180)
  {
    target=0;
    angle(0);
  }
  smoothmove(current,target);
  current=target;
  delay(300);
 }
}
void smoothmove(int curr,int tar)
{
  if(curr<tar)
  {
    for(int i=curr;i<tar;i++)
    {
      angle(i);
    }
  }
  else{
  for(int i=curr;i>=tar;i--)
  {
    angle(i);
  }
  }
}
void angle(int i)
{
  int pulse = 500 + (2000 * i) / 180;
  holdServoMicroseconds(pulse, 20);
}
void holdServoMicroseconds(int highTime,int delay) {
  int cycles=delay/20;
  for(int i=0;i<cycles;i++)
  {
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(highTime);

    digitalWrite(servoPin, LOW);
    delayMicroseconds(20000 - highTime);
  }
}