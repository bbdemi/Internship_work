#include "BUTTON.h"

    BUTTON::BUTTON(int butpin)
    {
        pin=butpin;
    }
    void BUTTON::begin()
    {
        pinMode(pin,INPUT_PULLUP);
    }
    bool BUTTON::isPressed(){
        return digitalRead(pin) == LOW;
    }
