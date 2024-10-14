#include "Logger.h"
/* #include "OTAPrograming.h"
#include "BrushlessMotor.h"
#include <WiFi.h>

BrushlessMotor M1(17);
BrushlessMotor M2(24);
BrushlessMotor M3(25);
BrushlessMotor M4(31);

const char *ssid = "SSID";
const char *password = "PASSWORD";

bool devMode = true;
bool Fight = false;
int Log = 0; // 0=NADA, 1=ERRORES, 2=TODO
OTA ota;


void disableWiFi() {
  WiFi.disconnect(true);   
  WiFi.mode(WIFI_OFF);     
  btStop();                
  esp_wifi_deinit();       
} */
Logger logger;

void setup() {
  Serial.begin(115200);
  logger.init(false, true, 1, "SSID", "PASSWORD");
  /*   ota.init(Fight, devMode, Log, ssid, password); 

  M1.init();
  M2.init();
  M3.init();
  M4.init(); */
}

void loop() {

    logger.logMessage(false, true, 1, 1, "Test");
    delay(500);
  /*   if(Fight || !devMode){
    disableWiFi();
  }
  ota.check();  */
  //M1.drive(50);
}

/*   /*
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