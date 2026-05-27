#include"STEPPER.h"

 STEPPER::STEPPER(int en,int step,int dir)
 {
    pinen=en;
    pinstep=step;
    pindir=dir;
 }

 void STEPPER:: begin()
 {
    pinMode(pinen, OUTPUT);
    pinMode(pinstep, OUTPUT);
    pinMode(pindir, OUTPUT);

    digitalWrite(pinen, LOW);
 }

 void STEPPER:: moveStepper(int steps)
 {
      for (int i = 0; i < steps; i++) {
    digitalWrite(pinstep, HIGH);
    delayMicroseconds(800);

    digitalWrite(pinstep, LOW);
    delayMicroseconds(800);
  }
 }
    void STEPPER::forward(int fs)
    {
        digitalWrite(pindir,HIGH);
        moveStepper(fs);

    }
    void STEPPER::reverse(int bs)
    {
        digitalWrite(pindir,LOW);
        moveStepper(bs);
    }