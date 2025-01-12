#ifndef ULTRASONICO_H
#define ULTRASONICO_H
#include "Pins.h"
#include "Arduino.h"
class ultrasonico
{
private:
    int trig;
    int echo;
public:
    ultrasonico();
    double getDistance();
};
#endif