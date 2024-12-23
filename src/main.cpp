#include <Arduino.h>
#include "motors.h"
#include "MPU6050.h"
const int ENA_MT1 = 7;//atras derecha
const int ENA_MT2 = 6;//atras izq
const int ENA_MT3 = 5;//adelante deracha
const int ENA_MT4 = 10;//adelante izq
const int IN1_MT1 = 33;//atras der
const int IN2_MT1 = 32;
const int IN1_MT2 = 31;//atras izq
const int IN2_MT2 = 30;
const int IN1_MT3 = 29;//adelante deracha
const int IN2_MT3 = 28;
const int IN1_MT4 = 27;//adelante izq
const int IN2_MT4 = 26;
motors myMotors(IN1_MT1,IN2_MT1,IN1_MT2,IN2_MT2,IN1_MT3,IN2_MT3,IN1_MT4,IN2_MT4,ENA_MT1,ENA_MT2,ENA_MT3,ENA_MT4);
float targetAngle=0;
void setup() {
  // put your setup code here, to run once:
  initializeMPU6050();
}
void loop() {
  // targetAngle=targetAngle+90;
  // myMotors.rotate(targetAngle);
  // delay(5000);
  for(int i=0;i<2;i++){
    myMotors.right();
    delay(3000);
  }
  for(int i=0;i<2;i++){
    myMotors.left();
    delay(3000);
  }
  


    // Serial.println("hola");
  // myMotors.ahead();
  // myMotors.PID_speed(0.0,z_rotation,90);
  // myMotors.showSpeeds();
 
   // uint8_t vel=150;
  // myMotors.setSpeed(vel);
  // while(true){ 
  //   myMotors.ahead();
  // }
  
}



