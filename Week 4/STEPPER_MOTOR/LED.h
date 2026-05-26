#pragma once
#include <Arduino.h>
class LED
{
    private:
    int pin;
    bool state;
    unsigned long previousTime;
    unsigned long currentTime;

    public:
    LED(int ipin);

    void begin();
    void on();
    void off();
    void blink(int s);
    void toggle();
    void blinkwithoutdelay(int s);
};