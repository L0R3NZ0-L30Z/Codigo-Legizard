#ifndef OTA_PROGRAMING_H
#define OTA_PROGRAMING_H

#include <WiFi.h>
#include <ArduinoOTA.h>

class OTA {
public:
    OTA();
    int init(bool Fight, bool devMode, int Log, const char *ssid, const char *password);
    void check(bool Fight, bool devMode, int Log);
};

#endif 

