#ifndef MOTORS_H
#define MOTORS_H
#include <Arduino.h>
#include "motor.h"
#include "PID.H"
class motors{
private:
    float targetAngle=0;
    PID myPID;
public:
    motor motor1;
    motor motor2;
    motor motor3;
    motor motor4;
    motors(int,int,int,int,int,int,int,int,int,int,int,int);
    void PID_speed(double, double, int);
    void setSpeed(uint8_t);
    void setahead();
    void setback();
    void setleft();
    void setright();
    void stop();
    void ahead();
    void back();
    void left();
    void right();
    void showSpeeds();
    void rotate(float);
    void changeSpeedMove(float,bool);

};
#endif
