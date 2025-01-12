#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_TCS34725.h>
// const int SDA_PIN=18;
// const int SCL_PIN=19;
#define SDA_PIN 18
#define SCL_PIN 19
Adafruit_TCS34725 tcs=Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS,TCS34725_GAIN_1X);
void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN,SCL_PIN);
  tcs.begin();
}

void loop() {
}