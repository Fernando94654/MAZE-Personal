
#include "Encoder.h"
#include "Pins.h"
motors robot;

void Encoder::backRightEncoder() {
    robot.motor[0].tics+=1;
}
void Encoder::backLeftEncoder() {
    robot.motor[1].tics+=1;
}
void Encoder::frontRightEncoder() {
    robot.motor[2].tics+=1;
}
void Encoder::frontLeftEncoder() {
    robot.motor[3].tics+=1;
}

