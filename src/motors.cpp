#include "motors.h"
#include "Pins.h"
#include "Encoder.h"
motors::motors(){
    
}
void motors::setupMotors(){
    for(int i=0;i<4;i++){
        motor[i].initialize(Pins::digitalOne[i],Pins::digitalTwo[i],Pins::pwmPin[i],i);
    }
    delay(500);
    attachInterrupt(digitalPinToInterrupt(Pins::encoder[0]),Encoder::backRightEncoder,RISING);
    attachInterrupt(digitalPinToInterrupt(Pins::encoder[1]),Encoder::backLeftEncoder,RISING);
    attachInterrupt(digitalPinToInterrupt(Pins::encoder[2]),Encoder::frontRightEncoder,RISING);
    attachInterrupt(digitalPinToInterrupt(Pins::encoder[3]),Encoder::frontLeftEncoder,RISING);
    // bno.setupBNO();
    targetAngle=0;
}
void motors::printAngle(){
    double angulo=bno.getOrientationX();
    Serial.println(angulo);
}
void motors::PID_speed(double setpoint,double angle, int reference_speed){
    //double input=setpoint+calculateAngularDistance();
    double output=myPID.calculate_PID(setpoint,angle);
    int right_speed=reference_speed-output;
    int left_speed=reference_speed+output;
    right_speed=constrain(right_speed,30,255);
    left_speed=constrain(left_speed,30,255);
    for(int i=0;i<4;i++){
        motor[i].setSpeed((i%2==0) ? left_speed:right_speed);
    }
    delay(20);
}
// void motors::ahead(){
//     int targetDistance=240;
//     resetTics();
//     setahead();
//     while(motor[0].tics<targetDistance){
//         getAngle();
//         float speed=changeSpeedMove(0.5,false,targetDistance);
//         PID_speed(targetAngle,z_rotation,speed);
//         showSpeeds();
//     }
//     stop();
//     resetTics();
// }
void motors::ahead(){
    // int targetDistance=240;
    // resetTics();
    setahead();
    // while(millis()<10000){//motor[0].tics<targetDistance
        angle=bno.getOrientationX();
        Serial.println(z_rotation);
        float speed=70;
        // float speed=changeSpeedMove(0.5,false,targetDistance);
        PID_speed(targetAngle,z_rotation,speed);
        // showSpeeds();
    // }
    // stop();
    // resetTics();
}
// void motors::ahead_ultra(){
//     double distance=vlx_FL.getDistance();
//     int targetDistances[]={10,40,70,100};
//     int targetDistance=findNearest(distance,targetDistances,4);
//     setahead();
//     while(distance>targetDistance){
//         distance=vlx_FL.getDistance();
//         float speed=changeSpeedMove(2,false,targetDistance);
//         PID_speed(targetAngle,z_rotation,speed);
//         showSpeeds();
//     }
//     stop();
// }
int motors::findNearest(int number,int numbers[],int size){
    int nearest=numbers[0];
    float minDifference=abs(number-numbers[0]);
    for(int i=1;i<size;i++){
        float currentDifference=abs(number-numbers[i]);
        if(currentDifference<minDifference){
            nearest=numbers[i];
            minDifference=currentDifference;
        }
    }
    nearest=nearest-30;
    nearest=constrain(nearest,5,95);
    return nearest;
}
void motors::back(){
    setback();
}
void motors::right(){
    if(targetAngle==360){
        targetAngle=0;
    }
    targetAngle=targetAngle+90;
    rotate(targetAngle);
}
void motors::left(){
    if(targetAngle==0){
        targetAngle=360;
    }
    targetAngle=targetAngle-90;
    rotate(targetAngle);
}
float motors::calculateAngularDistance(){
    float rightAngularDistance, leftAngularDistance;
    if(targetAngle>=angle){
        rightAngularDistance=targetAngle-angle;
        leftAngularDistance=angle+(360-targetAngle);
    }else{
        rightAngularDistance=(360-angle)+targetAngle;
        leftAngularDistance=angle-targetAngle;
    }
    return (rightAngularDistance<=leftAngularDistance) ? rightAngularDistance:-leftAngularDistance;
}
void motors::rotate(float deltaAngle){
    targetAngle=deltaAngle;
    bno.getOrientationX();
    float currentAngle,rightAngularDistance, leftAngularDistance,minInterval,maxInterval,tolerance=1;
    bool hexadecimal;
    //calculate angular distance in both directions
    if(targetAngle>=angle){
        rightAngularDistance=targetAngle-angle;
        leftAngularDistance=angle+(360-targetAngle);
    }else{
        rightAngularDistance=(360-angle)+targetAngle;
        leftAngularDistance=angle-targetAngle;
    }
    //define target interval and use angle or z_rotation
    if(targetAngle!=360 && targetAngle!=0){ 
        minInterval=(targetAngle-tolerance),maxInterval=(targetAngle+tolerance);
        hexadecimal=true;
    }else{
        minInterval=-tolerance,maxInterval=tolerance;
        hexadecimal=false;
    }
    //decide shortest route and rotate("?" es un operador ternario para remplazar if-else)
    (rightAngularDistance<=leftAngularDistance) ? setright():setleft();
    currentAngle=hexadecimal ? angle:z_rotation;
    while (currentAngle<minInterval||currentAngle>maxInterval){
        changeSpeedMove(0.5,true,0);
        bno.getOrientationX();
        currentAngle= hexadecimal ? angle:z_rotation;
        Serial.println(angle);
    }
    stop();
}
float motors::changeSpeedMove(float constant,bool rotate,int targetDistance){
    float speed;
    float minSpeed=20;
    if(rotate==true){
        speed=minSpeed+constant*(abs(targetAngle-angle));
        setSpeed(speed);
        return 0;
    }else{
        speed=minSpeed+constant*(abs(targetDistance-vlx[0].getDistance()));//motor1.tics
        speed=constrain(speed,20,100);
        return speed;
    }
}
void motors::setSpeed(int speed){
    for(int i=0;i<4;i++){ 
        motor[i].setSpeed(speed);}
}
void motors::setahead(){
    for(int i=0;i<4;i++){ 
        motor[i].ahead();}
}
void motors::setback(){
    for(int i=0;i<4;i++){ 
        motor[i].back();}
}
void motors::setright(){
    motor[0].ahead();
    motor[1].back();
    motor[2].ahead();
    motor[3].back();

}
void motors::setleft(){
    motor[0].back();
    motor[1].ahead();
    motor[2].back();
    motor[3].ahead();
}
void motors::stop(){
    for(int i=0;i<4;i++){ 
        motor[i].stop();}
        setSpeed(0);
}
void motors::showSpeeds(){
    double speedM1=motor[0].getSpeed();
    double speedM2=motor[1].getSpeed();
    double speedM3=motor[2].getSpeed();
    double speedM4=motor[3].getSpeed();
    Serial.println("Velocidades:");
    Serial.print("Motor1:"); Serial.print(speedM1);
    Serial.print("Motor2:"); Serial.print(speedM2);
    Serial.print("Motor3:"); Serial.print(speedM3);
    Serial.print("Motor4:"); Serial.println(speedM4);
}
void motors::resetTics(){
    for(int i=0;i<4;i++){ 
        motor[i].resetTics();}
}
void motors::setupVlx(const VlxID vlxId) {
    const uint8_t index = static_cast<uint8_t>(vlxId);
    vlx[index].setMux(Pins::vlxPins[index]);
    vlx[index].begin();
}
