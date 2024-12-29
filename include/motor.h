#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>

void interruption();

class motor{
private:
    int in1;
    int in2;
    int enable;
    double speed;
    
public:
    volatile int tics;
    void initialize(int,int,int,int);
    motor();
    void setSpeed(int);
    void ahead();
    void back();
    void stop();
    double getSpeed();
    void resetTics();
    int getTics();

};
#endif

