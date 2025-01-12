#include "VLX.h"

VLX::VLX(){

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
uint16_t VLX::getDistance(){
    VLX_.rangingTest(&measure,false);
    uint16_t distance=measure.RangeMilliMeter;
    return distance;
}
void VLX::printDistance(){
  VLX_.rangingTest(&measure, false);
  if (measure.RangeStatus != 4) {
    Serial.print("Distance: ");
    Serial.print(measure.RangeMilliMeter);
    Serial.println(" mm");
  } else {
    Serial.println("Fuera de rango.");
  }
  delay(500); 
}



