#include "BANNER/BANNER.h"
#include "BRUSHLESS/BRUSHLESS.h"
#include "ESTRATEGIA/ESTRATEGIA.h"
#include "LEDS/LEDS.h"
#include "MEDICIONES/MEDICIONES.h"
#include "PANTALLA/PANTALLA.h"
#include "QTR/QTR.h"
#include "USB/USB.h"
#include "VL/VL.h"
#include "WIFI/WIFI.h"
#include "OTAPrograming/OTAPrograming.h"


char Log[] = 0 
const char* ssid = "SSID";
const char* password = "PASSWORD";

void setup(){
    Serial.begin(115200);

    ota.init(ssid, password)
    
    motors.init(17, 24, 25, 31);
    // motors.drive(motors.M1, 50); 
    
}

void loop(){
    ota.check();

}

