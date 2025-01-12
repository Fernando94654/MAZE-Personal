#ifndef VLX_H
#define VLX_H
#include "Pins.h"
#include <Adafruit_VL53L0X.h>
#include <Wire.h>
#include <Arduino.h>
class VLX{
private:
    
public:
    Adafruit_VL53L0X VLX_ = Adafruit_VL53L0X();
    VL53L0X_RangingMeasurementData_t measure;
    VLX();
    void begin();
    VLX(int,int);
    uint16_t getDistance();
    void printDistance();

};
#endif

