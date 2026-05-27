#include<LED.h>


    LED::LED(int ledPin){
        pin=ledPin;
    }

    void LED::begin()
    {
        pinMode(pin,OUTPUT);
    }
    void LED::on()
    {
        digitalWrite(pin,HIGH);
    }
    void LED::off()
    {
        digitalWrite(pin,LOW);
    }
    void LED::blink(int s)
    {
        on();
        delay(s);
        off();
        delay(s);
    }