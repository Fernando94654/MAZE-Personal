#include <Arduino.h>
#include "Encoder.h"
// #include "motors.h"

// #include "Encoder.h"
// #include "VLX.h"
// #include <Adafruit_VL53L0X.h>
// #include "BNO.H"
// BNO bno;
// motors myMotors;
// VLX vlx;
// ultrasonico ultra;
// ultrasonico myUltra;
// float targetAngle=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // delay(1000);
  // bno.setupBNO();
  pinMode(2,OUTPUT);
  robot.setupMotors();
}
void loop() {
  // double ang=bno.getOrientationX();
  // Serial.println(ang);
  Serial.println(robot.motor[0].tics);
  // myMotors.setback();
  // myMotors.setSpeed(255);
  digitalWrite(2,1);
  // delay(2000);
  // myMotors.printAngle();
  // double angulo=myMotors.printAngle();
  // double angulo=bno.getOrientationX();
  // Serial.println(angulo);
  // Serial.println(z_rotation);
}