#include "LED.h"
#include "BUTTON.h"
LED led1(18);
BUTTON button(23);

void setup(){
    led1.begin();
    button.begin();
}

void loop(){
    if(button.isPressed())
    {
        led1.on();
    }
    else{
        led1.off();
    }
}