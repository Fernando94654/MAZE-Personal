#ifndef MOTORS_H
#define MOTORS_H
#include <Arduino.h>
#include "motor.h"
#include "PID.H"
#include "VLX.h"
#include "BNO.H"
#include <SPI.h>
class motors{
private:
    static constexpr uint8_t kNumberOfVlx = 5;
    float targetAngle=0;
    PID myPID;
    VLX vlx[kNumberOfVlx];
public:
    BNO bno;
    motor_ motor[4];//0-BACK_RIGHT//1-BACK_LEFT//2-FRONT_RIGHT//3-FRONT_LEFT
    motors();
    void setupMotors();
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
    void printAngle();
    void setupVlx(const VlxID);


};
#endif
