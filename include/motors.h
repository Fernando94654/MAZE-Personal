#ifndef MOTORS_H
#define MOTORS_H
#include <Arduino.h>
#include "motor.h"
#include "PID.H"
#include "ultrasonico.h"
class motors{
private:
    float targetAngle=0;
    PID myPID;
    ultrasonico myUltra;
public:
    motor motor1;
    motor motor2;
    motor motor3;
    motor motor4;
    motors();
    void PID_speed(double, double, int);
    void setSpeed(int);
    void setahead();
    void setback();
    void setleft();
    void setright();
    void stop();
    void ahead();
    void ahead_ultra();//borrar
    int findNearest(int,int[],int);
    void back();
    void left();
    void right();
    void showSpeeds();
    float calculateAngularDistance();
    void rotate(float);
    float changeSpeedMove(float,bool,int);
    void resetTics();

};
#endif
