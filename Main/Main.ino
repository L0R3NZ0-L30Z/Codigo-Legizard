#include "Logger.h"
//#include "OTAPrograming.h"
#include "MotorDriver.h"

MotorDriver M1(9);
MotorDriver M2(47);
MotorDriver M3(45);
MotorDriver M4(39);

Logger logger;
//OTA ota;

bool devMode = true;
bool Fight = false;
int Log = 0;  // 0=NADA, 1=ERRORES, 2=TODO

void disableWiFi() {
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  btStop();
}


void setup() {
  Serial.begin(115200);
  logger.init(Fight, devMode, true, "SSID", "PASSWORD");
  //ota.init(Fight, devMode, Log, ssid, password);

  M1.init();
  M2.init();
  M3.init();
  M4.init();
}

void loop() {
  logger.logMessage(Fight, devMode, 1, 1, "Test");
  delay(500);
  /* if (Fight || !devMode) {
    disableWiFi();
  } */
  M1.drive(50);
  //ota.check();
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