
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