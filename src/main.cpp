#include <Arduino.h>
#include "motors.h"
// #include "Encoder.h"
// #include "VLX.h"
// #include <Adafruit_VL53L0X.h>
// #include "BNO.H"
// BNO bno;
motors myMotors;
// VLX vlx;
// ultrasonico ultra;
// ultrasonico myUltra;
// float targetAngle=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myMotors.setupMotors();
}
void loop() {
  double ang=myMotors.bno.getOrientationX();
  Serial.println(ang);
  // myMotors.printAngle();
  // double angulo=myMotors.printAngle();
  // double angulo=bno.getOrientationX();
  // Serial.println(angulo);
  // Serial.println(z_rotation);
}