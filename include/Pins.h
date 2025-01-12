#ifndef PINS_H
#define PINS_H

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
}


#endif