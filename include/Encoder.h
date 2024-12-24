#ifndef ENCODER_H
#define ENCODER_H
#include <Arduino.h>

void interruption();
volatile int ticks;
class Encoder{
private:
    
public:
    Encoder(int);
    
};
#endif