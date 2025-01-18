#include "BNO.h"
// #include "CustomSerial.h"
float z_rotation;//angulo de rotacion
float angle;
BNO::BNO() {
    this->event_ = {0};
    this->bno_ = Adafruit_BNO055(55, 0x28, &Wire);
}
void BNO::setupBNO() {
    adafruit_bno055_opmode_t mode = OPERATION_MODE_IMUPLUS;

    // customPrintln("Orientation Sensor Test");
    // Initialise the sensor
    if (!bno_.begin()){
        // There was a problem detecting the BNO055 ... check your connections
        // customPrint("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
        while(1);
    }
    // customPrintln("BNO055 detected");
    delay(1000);
    bno_.setExtCrystalUse(true);
}

void BNO::updateBNO(sensors_event_t &event) {
    bno_.getEvent(&event);
}

double BNO::getOrientationX() {
    updateBNO(event_);
    angle=event_.orientation.x - phaseCorrection_;
    if(angle>180){
        z_rotation=angle-=360.0;
    }else{
        z_rotation=angle;
    }
    return event_.orientation.x - phaseCorrection_;
}

double BNO::getOrientationY() {
    updateBNO(event_);
    return event_.orientation.y;
}

void BNO::setPhaseCorrection(const double phaseCorrection) {
    phaseCorrection_ = phaseCorrection;
}