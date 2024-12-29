#include "Encoder.h"
#include "motors.h"
motors myMotors;

void frontLeftEncoder(){
    myMotors.motor1.tics+=1;
}
void frontRightEncoder(){
    myMotors.motor2.tics+=1;
}