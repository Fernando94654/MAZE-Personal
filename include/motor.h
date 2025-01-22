#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>

// void interruption();
enum class MotorID {
    kBackLeft = 0,
    kFrontLeft = 1,
    kBackRight = 2,
    kFrontRight = 3,
    kNone
};
class motor_{
private:
    int in1;
    int in2;
    uint8_t enable;
    uint32_t speed;
    
public:
    volatile int tics;
    void initialize(int,int,int,int);
    motor_();
    void setSpeed(int);
    void ahead();
    void back();
    void stop();
    double getSpeed();
    void resetTics();
    int getTics();

};
#endif

