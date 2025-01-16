#ifndef PINS_H
#define PINS_H
#include <Arduino.h>

constexpr int encoderPins[2]={
    19,//front left //
    18//front right
};
constexpr int vlsPins[2]={
    
};
namespace Pins{
   const int ultrasonico[2]={
    2,//trig
    3,//echo
    }; 
    constexpr uint8_t pwmPin[4] = {
        15, // BACK_RIGHT 15   15
        5, // BACK_LEFT 16   5
        26,  // FRONT_RIGHT 26
        32 // FRONT_LEFT 32 
    };

    constexpr uint8_t digitalOne[4] = {
        4, // BACK_RIGHT 4    2
        16, // BACK_LEFT 17   17
        14,  // FRONT_RIGHT 14
        33 // FRONT_LEFT 33   
    };  

    constexpr uint8_t digitalTwo[4] = {
        2, // BACK_RIGHT 2   4
        17, // BACK_LEFT 5  16
        27,  // FRONT_RIGHT 27
        25 // FRONT_LEFT 25 
    };
    constexpr uint8_t vlxPins[5] = {
        // Defined Pins on 20th of March
        3,  // FRONT_LEFT  fine 0  2
        4, // LEFT         fine 1  3    
        0, // BACK         fine 2  0
        2,  // RIGHT       fine 4  5
        5 // FRONT_RIGHT   fine 3  
    };
}
const int ENA_MT1 = 7;//atras derecha
const int ENA_MT2 = 5;//atras izq
const int ENA_MT3 = 6;//adelante deracha
const int ENA_MT4 = 10;//adelante izq
const int IN1_MT1 = 33;//atras der
const int IN2_MT1 = 32;
const int IN1_MT2 = 31;//atras izq
const int IN2_MT2 = 30;
const int IN1_MT3 = 29;//adelante deracha
const int IN2_MT3 = 28;
const int IN1_MT4 = 27;//adelante izq
const int IN2_MT4 = 26;


#endif