#pragma once
#include <Arduino.h>
class LED
{
    private:
    int pin;
    public:
    LED(int ipin);

    void begin();
    void on();
    void off();
    void blink(int s);
};