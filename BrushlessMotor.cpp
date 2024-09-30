#include "BrushlessMotor.h"

// Constructor
BrushlessMotor::BrushlessMotor(int pin) {
  _pin = pin;
}

// Initialize the motor
void BrushlessMotor::init() {
  _motor.attach(_pin); // Attach the servo to the specified pin
}

// Drive the motor with a speed value (-100 to 100)
void BrushlessMotor::drive(int speed) {
  // Map the speed (-100 to 100) to the pulse width (1000 to 2000)
  int pulseWidth;
  if (speed > 0) {
    pulseWidth = map(speed, 0, 100, _neutralPulseWidth, _maxPulseWidth);
  } else if (speed < 0) {
    pulseWidth = map(speed, -100, 0, _minPulseWidth, _neutralPulseWidth);
  } else {
    pulseWidth = _neutralPulseWidth; // Stop motor
  }

  // Send the pulse width to the ESC
  _motor.writeMicroseconds(pulseWidth);
}
