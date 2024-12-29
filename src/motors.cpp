#include "motors.h"
#include "MPU6050.h"
#include "Pins.h"

motors::motors(){
    motor1.initialize(IN1_MT1,IN2_MT1,ENA_MT1,1);
    motor2.initialize(IN1_MT2,IN2_MT2,ENA_MT2,2);
    motor3.initialize(IN1_MT3,IN2_MT3,ENA_MT3,3);
    motor4.initialize(IN1_MT4,IN2_MT4,ENA_MT4,4);
    targetAngle=0;
}
void motors::PID_speed(double setpoint,double angle, int reference_speed){
    //double input=setpoint+calculateAngularDistance();
    double output=myPID.calculate_PID(setpoint,angle);
    int right_speed=reference_speed-output;
    int left_speed=reference_speed+output;
    motor1.setSpeed(left_speed); motor2.setSpeed(right_speed); 
    motor3.setSpeed(left_speed); motor4.setSpeed(right_speed);
}
void motors::ahead(){
    int targetDistance=1800;
    resetTics();
    setahead();
    while(motor1.tics<targetDistance){
        getAngle();
        //float speed=changeSpeedMove(0.5,false,targetDistance);
        PID_speed(targetAngle,angle,90);
        showSpeeds();
    }
    stop();
    resetTics();
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
    getAngle();
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
        getAngle();
        currentAngle= hexadecimal ? angle:z_rotation;
        Serial.println(angle);
    }
    stop();
}
float motors::changeSpeedMove(float constant,bool rotate,int targetDistance){
    float speed;
    float minSpeed=40;
    if(rotate==true){
        speed=minSpeed+constant*(abs(targetAngle-angle));
        setSpeed(speed);
        return 0;
    }else{
        speed=minSpeed+constant*(abs(targetDistance-motor1.tics));
        return speed;
    }
}
void motors::setSpeed(int speed){
    motor1.setSpeed(speed);
    motor2.setSpeed(speed);
    motor3.setSpeed(speed);
    motor4.setSpeed(speed);
}
void motors::setahead(){
    motor1.ahead();
    motor2.ahead();
    motor3.ahead();
    motor4.ahead();
}
void motors::setback(){
    motor1.back();
    motor2.back();
    motor3.back();
    motor4.back();
}
void motors::setright(){
    motor1.ahead();
    motor2.back();
    motor3.ahead();
    motor4.back();

}
void motors::setleft(){
    motor1.back();
    motor2.ahead();
    motor3.back();
    motor4.ahead();
}
void motors::stop(){
    motor1.stop();
    motor2.stop();
    motor3.stop();
    motor4.stop();
    setSpeed(0);
}
void motors::showSpeeds(){
    double speedM1=motor1.getSpeed();
    double speedM2=motor2.getSpeed();
    double speedM3=motor3.getSpeed();
    double speedM4=motor4.getSpeed();
    Serial.println("Velocidades:");
    Serial.print("Motor1:"); Serial.print(speedM1);
    Serial.print("Motor2:"); Serial.print(speedM2);
    Serial.print("Motor3:"); Serial.print(speedM3);
    Serial.print("Motor4:"); Serial.println(speedM4);
}
void motors::resetTics(){
    motor1.resetTics();
    motor2.resetTics();
    motor3.resetTics();
    motor4.resetTics();
}
