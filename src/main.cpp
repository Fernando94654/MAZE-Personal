#include <Arduino.h>
#include "motors.h"
#include "MPU6050.h"
#include "Encoder.h"
float targetAngle=0;
void setup() {
  // put your setup code here, to run once:
  initializeMPU6050();
}
void loop() {
  // targetAngle=targetAngle+90;
  // myMotors.rotate(targetAngle);
  // delay(5000);
  // for(int i=0;i<2;i++){
  //   myMotors.right();
  //   delay(3000);
  // }
  // for(int i=0;i<2;i++){
  //   myMotors.left();
  //   delay(3000);
  // }
  // for(int i=0;i<2;i++){
  //   myMotors.ahead();
  //   delay(3000);
  // }

  //myMotors.ahead();
    // Serial.println("hola");
  getAngle();
  myMotors.setahead();
  myMotors.PID_speed(0.0,z_rotation,80);
  myMotors.showSpeeds();
  // myMotors.setright();
  // myMotors.setSpeed(90);
   // uint8_t vel=150;
  // myMotors.setSpeed(vel);
  // while(true){ 
  //   myMotors.ahead();
  // }
  
}



