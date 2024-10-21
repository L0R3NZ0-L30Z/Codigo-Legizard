#include "MotorDriver.h"

MotorDriver::MotorDriver(uint8_t pin) {
  _pin = pin;
}

bool MotorDriver::init() {
  Serial.begin(115200);
  Serial.println("Start");

  ledcAttach(_pin, 50, 12);   
  
  delay(100);
  ledcWrite(_pin, 410); 
  delay(500);
  ledcWrite(_pin, 205);  
  delay(500);
  ledcWrite(_pin, 306);  
  delay(500);

  return true;
}

void MotorDriver::drive(int value) {
  value = constrain(value, -100, 100);
  int pwmValue = map(value, -100, 100, 205, 410);
  ledcWrite(_pin, pwmValue);  
}
