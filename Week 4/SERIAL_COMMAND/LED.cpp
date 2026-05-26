#include "LED.h"


    LED::LED(int ledPin){
        pin=ledPin;
        state=false;
        PreviousTime=0;
        CurrentTime=millis();
    }

    void LED::begin()
    {
        pinMode(pin,OUTPUT);
    }
    void LED::on()
    {
        digitalWrite(pin,HIGH);
        state=true;
    }
    void LED::off()
    {
        digitalWrite(pin,LOW);
        state=false;
    }
    void LED::blink(int s)
    {
        on();
        delay(s);
        off();
        delay(s);
    }
    void LED::toggle()
    {
    if (state==true) {
      off();
    } else {
      on();
    }
    }

    void LED::blinkwithoutdelay(int s)
    {
        CurrentTime=millis();
    if (CurrentTime-PreviousTime>=s) {
      if(state==true)
      {
        off();
      }
      else
      {
        on();
      }
      PreviousTime=CurrentTime;
    } 
    }