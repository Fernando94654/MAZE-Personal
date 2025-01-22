#include "BNO.h"
// #include "CustomSerial.h"
float z_rotation;//angulo de rotacion
float angle;
#define SDA_PIN 23
#define SCL_PIN 13
BNO::BNO() {
    this->event_ = {0};
    Wire.begin(SDA_PIN, SCL_PIN);
    Wire.setClock(50000); // Reduce a 50 kHz
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
    delay(1000);
    angle_initial=getOrientationX();
    Serial.println(angle_initial);
    
}

void BNO::updateBNO(sensors_event_t &event) {
    bno_.getEvent(&event);
}

double BNO::getOrientationX() {
    updateBNO(event_);
    angle=event_.orientation.x - phaseCorrection_;
    angle = angle - angle_initial;
    if (angle < 0) {
        angle+= 360;
    } else if (angle >= 360) {
        angle-= 360;
    }
    if(angle>180){
        z_rotation=angle-360.0;
    }else{
        z_rotation=angle;
    }
    return angle;
}

double BNO::getOrientationY() {
    updateBNO(event_);
    return event_.orientation.y;
}

void BNO::setPhaseCorrection(const double phaseCorrection) {
    phaseCorrection_ = phaseCorrection;
}

// Establecer corrección de fase para el eje Y
void BNO::setPhaseCorrectionY(const double phaseCorrectionY) {
    phaseCorrectionY_ = phaseCorrectionY;
}

// Reiniciar valores a 0
void BNO::resetOrientation() {
    updateBNO(event_);
    setPhaseCorrection(event_.orientation.x); // Reinicia el eje X
    setPhaseCorrectionY(event_.orientation.y); // Reinicia el eje Y
    Serial.println("Valores del BNO055 reiniciados a 0.");
}