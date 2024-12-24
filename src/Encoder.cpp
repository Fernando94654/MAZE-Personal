#include "Encoder.h"

void interruption(){
    ticks+=1;
}
Encoder::Encoder(int encoderPin){
    attachInterrupt(digitalPinToInterrupt(encoderPin),interruption,RISING);
}
