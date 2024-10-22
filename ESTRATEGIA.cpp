#include "QTR.h"  // Custom sensor library
#include "MotorDriver.h"  // Replace with your actual motor library

// Motor declarations
MotorDriver M1(9);
MotorDriver M2(47);
MotorDriver M3(45);
MotorDriver M4(39);

// Sensor declarations
QTR sensor;

// Sensor pin definitions
const int topLeftPin = A0;
const int topRightPin = A1;
const int bottomLeftPin = A2;
const int bottomRightPin = A3;

// Movement state
enum MovementState { FORWARD, BACKWARD };
MovementState currentMovement = FORWARD;

// Function to initialize motors and sensors
void initializeComponents() {
    // Initialize motors
    M1.init();
    M2.init();
    M3.init();
    M4.init();

    // Initialize sensors
    sensor.init(topLeftPin, topRightPin, bottomLeftPin, bottomRightPin);
}

// Function to control motors based on sensor readings
void controlMotorsBasedOnSensors() {
    // Get sensor readings
    bool topLeftDetected = sensor.medir(topLeftPin);
    bool topRightDetected = sensor.medir(topRightPin);
    bool bottomLeftDetected = sensor.medir(bottomLeftPin);
    bool bottomRightDetected = sensor.medir(bottomRightPin);

    // Update movement state based on any sensor detection
    if (currentMovement == FORWARD && (topLeftDetected || topRightDetected)) {
        currentMovement = BACKWARD;  // Switch to backward if any top sensor detects something
    } else if (currentMovement == BACKWARD && (bottomLeftDetected || bottomRightDetected)) {
        currentMovement = FORWARD;   // Switch to forward if any bottom sensor detects something
    }

    // Set motor speed based on current movement state
    int motorValue = (currentMovement == FORWARD) ? 50 : -50;
    M1.setMotorSpeed(motorValue);
    M2.setMotorSpeed(motorValue);
    M3.setMotorSpeed(motorValue);
    M4.setMotorSpeed(motorValue);
}

void setup() {
    Serial.begin(115200);
    initializeComponents();  // Initialize all components
}

void loop() {
    controlMotorsBasedOnSensors();  // Monitor sensors and control motors
    delay(50);  // Adjust delay as needed
}
