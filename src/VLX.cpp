#include "VLX.h"

VLX::VLX(){

}
VLX::VLX(const uint8_t posMux){
    mux_.setNewChannel(posMux);
}

void VLX::begin(){
    if (!VLX_.begin()) {
        Serial.println("¡Error al iniciar el sensor VL53L0X!");
        while (1);
    }
    Serial.println("VL53L0X iniciado correctamente.");    
}
// VLX::VLX(int SDA, int SCL){

// }
void VLX::setMux(const uint8_t posMux) {
    mux_.setNewChannel(posMux);
}
void VLX::updateDistance() {
    mux_.selectChannel();
    VLX_.rangingTest(&measure, false);
}
double VLX::getDistance(){
    updateDistance();
    distance=measure.RangeMilliMeter/10;
    return distance;
}
void VLX::printDistance(){
    updateDistance();
    if (measure.RangeStatus != 4) {
        Serial.print("Distance: ");
        Serial.print(measure.RangeMilliMeter);
        Serial.println(" mm");
    } else {
        Serial.println("Fuera de rango.");
    }
    delay(500); 
    }



