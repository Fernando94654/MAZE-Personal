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
  // pinMode(15,OUTPUT);
  // delay(1000);
  // bno.setupBNO();
  // pinMode(2,OUTPUT);
  // vlx.begin();
  robot.setupMotors();
}
void loop() {
  // robot.setback();
  // robot.setSpeed(250);

  robot.ahead();
  delay(700);
  robot.ahead();
  delay(700);
  robot.right();
  delay(700);
  // analogWrite(15,250);
  
}
