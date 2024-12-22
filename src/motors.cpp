#include "motors.h"
#include "MPU6050.h"
motors::motors(int m1P1,int m1P2,int m2P1,int m2P2,int m3P1,int m3P2,int m4P1,int m4P2,int en1,int en2,int en3,int en4){
    motor1.initialize(m1P1,m1P2,en1);
    motor2.initialize(m2P1,m2P2,en2);
    motor3.initialize(m3P1,m3P2,en3);
    motor4.initialize(m4P1,m4P2,en4);
}
void motors::PID_speed(double setpoint,double angle, int reference_speed){
    double output=myPID.calculate_PID(setpoint,angle);
    double right_speed=reference_speed-output;
    double left_speed=reference_speed+output;
    motor1.setSpeed(left_speed); motor2.setSpeed(right_speed); 
    motor3.setSpeed(left_speed); motor4.setSpeed(right_speed);
}
void motors::ahead(){
    setahead();
}
void motors::back(){
    setback();
}
void motors::right(float targetAngle){
    setright();
    // while()
}
void motors::left(float targetAngle){
    setleft();
}
void motors::rotate(float targetAngle){
    setSpeed(90);
    getAngle();
    float rightAngularDistance, leftAngularDistance,minInterval,maxInterval,tolerance=2;
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
    //decide shortest route and rotate
    if(rightAngularDistance<=leftAngularDistance){
        setright();
        if(hexadecimal==true){
            while(angle<minInterval||angle>maxInterval){
                Serial.println(angle);
                getAngle();}
        }else{
            while(z_rotation<minInterval||z_rotation>maxInterval){
                Serial.println(angle);
                getAngle();}
        }
    }else{
        setleft();
        if(hexadecimal==true){
            while(angle<minInterval||angle>maxInterval){
                Serial.println(angle);
                getAngle();}
        }else{
            while(z_rotation<minInterval||z_rotation>maxInterval){
                Serial.println(angle);
                getAngle();}
        }
    }
    stop();
}
void motors::setSpeed(uint8_t speed){
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

