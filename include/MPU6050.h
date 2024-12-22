//uso de MPU6050
#ifndef MPU6050_H
#define MPU6050_H
#include <Arduino.h>
#include "Simple_MPU6050.h"
#define MPU6050_ADDRESS_AD0_LOW     0x68 
#define MPU6050_ADDRESS_AD0_HIGH    0x69 
#define MPU6050_DEFAULT_ADDRESS     MPU6050_ADDRESS_AD0_LOW
#define Three_Axis_Quaternions 3
#define Six_Axis_Quaternions 6  
#define spamtimer(t) for (static uint32_t SpamTimer; (uint32_t)(millis() - SpamTimer) >= (t); SpamTimer = millis()) 
#define printfloatx(Name,Variable,Spaces,Precision,EndTxt) print(Name); {char S[(Spaces + Precision + 3)];Serial.print(F(" ")); Serial.print(dtostrf((float)Variable,Spaces,Precision ,S));}Serial.print(EndTxt);
//objeto y variables globales
extern Simple_MPU6050 mpu;
extern float z_rotation;//angulo de rotacion
extern float angle;
extern float ypr[3];
extern float xyz[3];
//funciones de mpu
void print_z_rotation();
void loop_mpu();
float getAngle();
void PrintValues(int32_t*, uint16_t);
void ChartValues(int32_t*, uint16_t);
void PrintAllValues(int16_t*, int16_t*, int32_t*, uint16_t);
void ChartAllValues(int16_t*, int16_t*, int32_t*, uint16_t);
void PrintQuaternion(int32_t*, uint16_t);
void PrintEuler(int32_t*, uint16_t);
void PrintRealAccel(int16_t*, int32_t*, uint16_t);
void PrintWorldAccel(int16_t*, int32_t*, uint16_t);
void print_Values (int16_t *, int16_t *, int32_t *);
void initializeMPU6050();
#endif

