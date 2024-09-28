#include "BRUSHLESS.h"
#include <ESP32Servo.h>

BRUSHLESS::BRUSHLESS()
{
}

void BRUSHLESS::init(int pinM1, int pinM2, int pinM3, int pinM4)
{
    ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);

    M1.setPeriodHertz(50);
    M2.setPeriodHertz(50);
    M3.setPeriodHertz(50);
    M4.setPeriodHertz(50);

    M1.attach(pinM1, 1000, 2000);
    M2.attach(pinM2, 1000, 2000);
    M3.attach(pinM3, 1000, 2000);
    M4.attach(pinM4, 1000, 2000);
}

void BRUSHLESS::drive(ESP32PWM& motor, int speed)
{
    int pwmValue;
    
    if (speed == 0) {
        pwmValue = 1500; 
    } else if (speed > 0) {
        pwmValue = map(speed, 0, 100, 1500, 2000); 
    } else {
        pwmValue = map(speed, -100, 0, 1000, 1500);
    }

    motor.writeMicroseconds(pwmValue);
}