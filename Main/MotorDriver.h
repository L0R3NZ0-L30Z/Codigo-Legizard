#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <Arduino.h>

class MotorDriver {
  public:
    MotorDriver(uint8_t pin);
    bool init();
    void drive(int value);
  private:
    uint8_t _pin;
};

#endif
