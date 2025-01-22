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
    float targetAngle=0;
    PID myPID[4];
    VLX vlx[5];
    double maxVlxDistance=120;
    int edgeTileDistance=10;
    const double wheelDiameter=8;
    const double distancePerRev=wheelDiameter*3.1416;
    const double kTicsPerRev=496.0;
    const double kTicsPerTile=30*kTicsPerRev/distancePerRev;
    const uint8_t kMinSpeedRotate=70;
    const uint8_t kMaxSpeedRotate=160;
    float minDisToWall=3;
    float maxChangeAngle=10;
    const uint8_t kMinSpeedFormard=70;
    const uint8_t kMaxSpeedFormard=180;
public:
    BNO bno;
    motor_ motor[4];//0-BACK_RIGHT//1-BACK_LEFT//2-FRONT_RIGHT//3-FRONT_LEFT
    motors();
    void setupMotors();
    void PID_speed(double, double, int);
    void PID_encoders();
    void setSpeed(int);
    void setahead();
    void setback();
    void setleft();
    void setright();
    void stop();
    void ahead();
    void ahead_ultra();//borrar
    float nearWall();//ver
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
