// #ifndef ENCODER_H
// #define ENCODER_H
// #include <Arduino.h>
// #include "motors.h"
// #include "Pins.h"
// extern motors myMotors;

// void frontLeftEncoder();
// void frontRightEncoder();


// #endif
#ifndef Encoder_h
#define Encoder_h

#include <Arduino.h>
#include "Motors.h"
#include "Pins.h"
extern motors robot;
namespace Encoder {
    void backRightEncoder();
    void backLeftEncoder();
    void frontRightEncoder();
    void frontLeftEncoder();
};

#endif