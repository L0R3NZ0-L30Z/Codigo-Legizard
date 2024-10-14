#ifndef Logger_H
#define Logger_H

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

class Logger {
public:
    Logger(); 
    void init(bool fightMode, bool devMode, int logLevel, const char* ssid, const char* password); 
    void logMessage(bool fightMode, bool devMode, int logLevel, int state, String message);

private:
    AsyncWebServer server;
    AsyncEventSource events;
};

#endif
