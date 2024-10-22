#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <Arduino.h>

class  ESTRATEGIA {
public:
    ESTRATEGIA();  
    int inicio(int direccion);//dentro de los parentesis van los van los valores a pasa a la funcion
};

#endif
---------------------------------
NO TE  CAIGAS 
// Define motor and sensor variables
int motorFrontLeft = 1;      // Motor states: 1 means running, 0 means stopped
int motorFrontRight = 1;
int motorBackLeft = 1;
int motorBackRight = 1;

int sensorFrontLeft = 0;     // Sensor values: 0 means no obstacle, 1 means obstacle
int sensorFrontRight = 0;
int sensorBackLeft = 0;
int sensorBackRight = 0;

int initializer = 0;         // Initializer (1 to start the robot)

// Timing variables
unsigned long motorTimeout = 2000; // 2 seconds in milliseconds
unsigned long motorStartTime = 0;  // Variable to track motor activation time
bool isTurningOnRightMotor = false; // Flag to indicate if right motor is activated

// Function prototypes
void runMotorFrontLeft();    // Function to run front left motor
void stopMotorFrontLeft();   // Function to stop front left motor
void runMotorFrontRight();   // Function to run front right motor
void stopMotorFrontRight();  // Function to stop front right motor
void runMotorBackLeft();     // Function to run back left motor
void stopMotorBackLeft();    // Function to stop back left motor
void runMotorBackRight();    // Function to run back right motor
void stopMotorBackRight();   // Function to stop back right motor

void readAllSensors();       // Existing function to read sensor values

void setup() {
  // Setup code
}

void loop() {
  if (initializer == 1) {    // Only start if the initializer is set to 1
    readAllSensors();        // Call existing function to read sensor values

    // Check if either front sensor detects an obstacle
    if (sensorFrontLeft == 1 || sensorFrontRight == 1) {
      // Stop all motors
      motorFrontLeft = 0;
      motorFrontRight = 0;
      motorBackLeft = 0;
      motorBackRight = 0;
      stopMotorFrontLeft();
      stopMotorFrontRight();
      stopMotorBackLeft();
      stopMotorBackRight();

      // Activate the right motor for 2 seconds
      if (!isTurningOnRightMotor) {
        isTurningOnRightMotor = true;
        motorStartTime = millis();  // Record the time when the right motor is activated
        runMotorFrontRight();        // Start the right motor
      }
    }

    // Check if the right motor has been on for 2 seconds
    if (isTurningOnRightMotor && (millis() - motorStartTime >= motorTimeout)) {
      motorFrontRight = 0;       // Turn off the right motor
      stopMotorFrontRight();
      isTurningOnRightMotor = false; // Reset the flag
    }

    // Control other motors if no obstacles are detected
    if (sensorFrontLeft == 0 && sensorFrontRight == 0) {
      motorFrontLeft = 1;
      motorFrontRight = 1;
      motorBackLeft = 1;
      motorBackRight = 1;
      runMotorFrontLeft();
      runMotorBackLeft();
      runMotorBackRight();
    }
  }
}
