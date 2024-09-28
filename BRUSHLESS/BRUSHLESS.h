#ifndef BRUSHLESS_H
#define BRUSHLESS_H

#include <Arduino.h>
#include <ESP32Servo.h>  

class BRUSHLESS {
public:
    BRUSHLESS(); 
    void init(int pinM1, int pinM2, int pinM3, int pinM4); 
    void drive(ESP32PWM& motor, int speed);

private:
    ESP32PWM M1, M2, M3, M4;  
};

#endif