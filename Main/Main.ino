#include "Logger.h"
#include "OTAPrograming.h"
#include "MotorDriver.h"
#include "QTR.h"

// Motor declarations
MotorDriver M1(9);
MotorDriver M2(47);
MotorDriver M3(45);
MotorDriver M4(39);

// Logger declaration
Logger logger;

// OTA declaration
OTA ota;

// Sensor declaration
QTR sensor;

// Global variables for modes
bool devMode = true;
bool Fight = false;
int Log = 0; // 0 = NADA, 1 = ERRORES, 2 = TODO

// Sensor pin definitions
const int topLeftPin = A0;
const int topRightPin = A1;
const int bottomLeftPin = A2;
const int bottomRightPin = A3;

// Movement state
enum MovementState { FORWARD, BACKWARD };
MovementState currentMovement = FORWARD;

// Function to disable WiFi when not in use
void disableWiFi() {
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    btStop();
}

// Function to initialize motors, sensors, logger, and OTA
void initializeComponents() {
    // Initialize motors
    M1.init();
    M2.init();
    M3.init();
    M4.init();

    // Initialize sensors
    sensor.init(topLeftPin, topRightPin, bottomLeftPin, bottomRightPin);

    // Initialize logger
    logger.init(Fight, devMode, true, "SSID", "PASSWORD");

    // Initialize OTA
    const char* ssid = "SSID";
    const char* password = "PASSWORD";
    if (ota.init(Fight, devMode, Log, ssid, password) == 0) {
        Serial.println("OTA Initialized");
    } else {
        Serial.println("OTA Initialization Failed");
    }
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
        logger.logMessage(Fight, devMode, Log, 1, "Switching to BACKWARD");
    } else if (currentMovement == BACKWARD && (bottomLeftDetected || bottomRightDetected)) {
        currentMovement = FORWARD;   // Switch to forward if any bottom sensor detects something
        logger.logMessage(Fight, devMode, Log, 1, "Switching to FORWARD");
    }

    // Set motor speed based on current movement state
    int motorValue = (currentMovement == FORWARD) ? 50 : -50;
    M1.drive(motorValue);
    M2.drive(motorValue);
    M3.drive(motorValue);
    M4.drive(motorValue);
}

void setup() {
    Serial.begin(115200);
    initializeComponents();  // Initialize all components
}

void loop() {
    controlMotorsBasedOnSensors();  // Monitor sensors and control motors
    ota.check();                    // Handle OTA updates
    delay(50);                      // Adjust delay as needed
    if (Fight || !devMode) {
        disableWiFi();              // Disable WiFi if in Fight mode or not in devMode
    }
}

/*   
    Direccion:
    numero que llega | posicion horaria
            1        =      12
            2        =      1.5
            3        =      3
            4        =      4.5
            5        =      6
            6        =      7.5
            7        =      9
            8        =      10.5
    
   delay(5000);
   switch (direccion)
   {
   case 1:
    motors.drive(motors.M1, 50);
    motors.drive(motors.M2, 50);
    motors.drive(motors.M3, 50);
    motors.drive(motors.M4, 50);
    break;

    case 2: // Falta hacer
    motors.drive(motors.M1, 50);
    motors.drive(motors.M2, 50);
    motors.drive(motors.M3, 50);
    motors.drive(motors.M4, 50);
    break;

    case 3: // Falta hacer
    motors.drive(motors.M1, 50);
    motors.drive(motors.M2, 50);
    motors.drive(motors.M3, 50);
    motors.drive(motors.M4, 50);
    break;

    case 4: // Falta hacer
    motors.drive(motors.M1, 50);
    motors.drive(motors.M2, 50);
    motors.drive(motors.M3, 50);
    motors.drive(motors.M4, 50);
    break;

    case 5: 
    motors.drive(motors.M1, -50);
    motors.drive(motors.M2, -50);
    motors.drive(motors.M3, -50);
    motors.drive(motors.M4, -50);
    break;

    case 6:// Falta hacer
    motors.drive(motors.M1, 50);
    motors.drive(motors.M2, 50);
    motors.drive(motors.M3, 50);
    motors.drive(motors.M4, 50);
    break;

    case 7: // Falta hacer
    motors.drive(motors.M1, 50);
    motors.drive(motors.M2, 50);
    motors.drive(motors.M3, 50);
    motors.drive(motors.M4, 50);
    break;

    case 8: // Falta hacer
    motors.drive(motors.M1, 50);
    motors.drive(motors.M2, 50);
    motors.drive(motors.M3, 50);
    motors.drive(motors.M4, 50);
    break;
   
   default:
   return 0;
    break; */