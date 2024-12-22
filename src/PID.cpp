#include "PID.H"
#include <Arduino.h>

PID::PID(double kp_,double ki_,double kd_){
    kp=kp_;
    ki=ki_;
    kd=kd_;
}
PID::PID(){
    kp=2.0;
    ki=0.1;
    kd=1.0;
}
double PID::calculate_PID(double setpoint, double input){
    double current_time=millis();
    double delta_time=current_time-last_time;
    if(delta_time>=calculate_time){
        double error=setpoint-input;
        double total_error=error+last_error;

        double proportional=kp*error;
        double integral=ki*total_error;
        double derivative=kd*(error-last_error)/(delta_time);
        double output=proportional+integral+derivative;
        last_error=error;
        last_time=current_time;
        return output;
    }

}