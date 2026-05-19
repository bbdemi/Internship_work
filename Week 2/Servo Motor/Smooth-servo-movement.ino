const int servoPin = 19;
int angle=90;
int current=0;
void setup() {
Serial.begin(115200);
  pinMode(servoPin, OUTPUT);
  Serial.println("Enter angle");
}

void loop() {

  if(Serial.available()>0)
  {
     String input = Serial.readStringUntil('\n');
     input.trim();

  if(input.length()>0)
  angle=input.toInt();
if(current<angle){
  for(int i=current;i<angle;i++)
  {
    int time=500+(2000*i)/180;
    holdServoMicroseconds(time,40);
  }
}
else
{
  for(int i=current;i>=angle;i--)
  {
    int time=500+(2000*i)/180;
    holdServoMicroseconds(time,300);
  }
}
  current=angle;
  }
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