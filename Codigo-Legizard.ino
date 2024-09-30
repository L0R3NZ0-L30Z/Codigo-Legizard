#include "OTAPrograming.h"
#include "BrushlessMotor.h"

BrushlessMotor M1(17);
BrushlessMotor M2(24);
BrushlessMotor M3(25);
BrushlessMotor M4(31);

const char *ssid = "SSID";
const char *password = "PASSWORD";

bool devMode = true;

OTA ota;

void setup() {
  Serial.begin(115200);
  ota.init(ssid, password); 

  M1.init();
  M2.init();
  M3.init();
  M4.init();

}

void loop() {
  ota.check(); 
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