#ifndef BRUSHLESSMOTOR_H
#define BRUSHLESSMOTOR_H

#include <ESP32Servo.h>

class BrushlessMotor {
  public:

    BrushlessMotor(int pin);
    
    void init();

    void drive(int speed);

  private:
    int _pin;
    Servo _motor;
    const int _minPulseWidth = 1000; 
    const int _maxPulseWidth = 2000; 
    const int _neutralPulseWidth = 1500; 
};

#endif
