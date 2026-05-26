#pragma once
#include <Arduino.h>
class BUTTON{
    private:
    int pin;
    public:
    BUTTON(int butpin);

    void begin();
    bool isPressed();
};