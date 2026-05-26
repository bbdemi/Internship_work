#pragma once
#include <Arduino.h>
class STEPPER
{
    private:
    int pinen,pinstep,pindir;
    public:
    STEPPER(int en,int step,int dir);

    void begin();
    void moveStepper(int steps);
    void forward(int fs);
    void reverse(int bs);

};