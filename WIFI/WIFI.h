#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

class  WIFI {
public:
    WIFI(); 
    int init(ssid, password); 
};

#endif