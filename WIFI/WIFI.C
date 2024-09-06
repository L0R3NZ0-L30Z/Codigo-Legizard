#include "WIFI.h"
#include <WiFi.h>

WIFI::WIFI()
{
}

int WIFI::init()
{
    WiFiServer server(80);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    server.begin();
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    return 0;
}

void WIFI::doSomething()
{
    //Codigo del manejo de wifi
}