#include "ESTRATEGIA.h"

ESTRATEGIA::ESTRATEGIA() {

}


int ESTRATEGIA::inicio(int direccion) {
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
    */
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
    break;
   }
   

} 