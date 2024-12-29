#include "motor.h"
#include <Arduino.h>
#include "Pins.h"
#include "Encoder.h"
void motor::initialize(int in_1,int in_2,int en,int numMotor){
    in1=in_1;
    in2=in_2;
    enable=en;
    attachInterrupt(digitalPinToInterrupt(encoderPins[numMotor]),frontLeftEncoder,RISING);
    pinMode(in1,INPUT);
    pinMode(in2,INPUT);
    pinMode(enable,OUTPUT);
    
}

motor::motor(){
    //default constructor
}
void motor::resetTics(){
    tics=0;
}
int motor::getTics(){
    return tics;
}
void motor::setSpeed(int velocity){
    speed=velocity;
    speed=constrain(speed,0,255);
    analogWrite(enable,speed);
}
void motor::ahead(){
    digitalWrite(in1,1);
    digitalWrite(in2,0);
}
void motor::back(){ 
    digitalWrite(in1,0);
    digitalWrite(in2,1);
}
void motor::stop(){
    digitalWrite(in1,0);
    digitalWrite(in2,0);
}
double motor::getSpeed(){
    return speed;
}
