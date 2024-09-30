#ifndef OTA_H
#define OTA_H

#include "OTAPrograming.h"
#include <WiFi.h>
#include <ArduinoOTA.h>

class OTA {
public:
    OTA();  
    int init(const char* ssid, const char* password);  
    void check();  
};

#endif