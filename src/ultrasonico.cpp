#include "ultrasonico.h"  

ultrasonico::ultrasonico(){
    trig=Pins::ultrasonico[0];
    echo=Pins::ultrasonico[1];
    pinMode(trig, OUTPUT);  
    pinMode(echo, INPUT); 
};
double ultrasonico::getDistance(){
    digitalWrite(trig,0);
    delayMicroseconds(2);
    digitalWrite(trig,1);
    delayMicroseconds(10);
    digitalWrite(trig,0);
    long pulse = pulseIn(echo,1);
    // Calculamos la distancia (en cm)
    double distance = (pulse * 0.034) / 2; 
    //Serial.println(distance);
    delay(100);
    return distance;
};