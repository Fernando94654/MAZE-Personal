#include <Arduino.h>
#include "motors.h"
#include "MPU6050.h"
#include "Encoder.h"
#include "VLX.h"
#include "ultrasonico.h"
#include <Adafruit_VL53L0X.h>
// VLX vlx;
ultrasonico myUltra;
float targetAngle=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // Serial.println("Iniciando...");
  // vlx.begin();
  initializeMPU6050();
}
void loop() {
  //vlx.printDistance();
  // uint16_t distance=vlx.getDistance();
  // Serial.println(distance);
  // myUltra.getDistance();
  myMotors.ahead_ultra();
  delay(3000);
  // delay(5000);
    // Serial.println("hola");
  // getAngle();
  // myMotors.setahead();
  // myMotors.PID_speed(0.0,z_rotation,80);
  // myMotors.showSpeeds();
  // myMotors.setright();
  // myMotors.setSpeed(90);
   // uint8_t vel=150;
  // myMotors.setSpeed(vel);
  // while(true){ 
  //   myMotors.ahead();
  // }
  
}



