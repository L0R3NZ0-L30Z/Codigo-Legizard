#include "WIFI.h"
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

WIFI::WIFI() : server(80) // Initialize server on port 80
{
}


int WIFI::init(const char *ssid, const char *password)
{
    WiFi.begin(ssid, password);
    for(int i=0; WiFi.status() != WL_CONNECTED || i > 10; i++)
    {
        delay(500);
        Serial.println(".");
    }
    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("Connected to WiFi");
        server.on("/", HTTP_GET, std::bind(&WIFI::handleLogPage, this, std::placeholders::_1));
        server.begin();
        return WiFi.localIP();
    }
    else
    {
        Serial.println("Failed to connect to WiFi");
        return 0; 
    }
}

void handleLogPage(AsyncWebServerRequest *request)
{
    String html =
        "<html>"
        "<head>"
        "<meta charset=\"UTF-8\">"
        "<meta name=\"viewport\" content=\"width=device-width,initial-scale=1\">"
        "<title>Basic Webpage with Fonts</title>"
        "<style>"
        "body {"
        "background-color: #0f0e08;"
        "color: #f7e4dc;"
        "font-family: Arial, sans-serif;"
        "margin: 0;"
        "padding: 20px"
        "}"
        "h1 {"
        "font-family: Calibri, serif;"
        "font-size: 36px;"
        "text-align: center"
        "}"
        "#toast {"
        "border-radius: 1rem;"
        "background-color: #f7e4dc;"
        "color: #0f0e08;"
        "padding: 1%;"
        "padding-left: 3%"
        "}"
        "li {"
        "color: #0f0e08;"
        "font-family: Calibri, serif"
        "}"
        "</style>"
        "</head>"
        "<body>"
        "<h1>ESP32 Log</h1>"
        "<div id=\"toast\"></div>"
        "<script>"
        "const items = " + Log + ";"
        "const itemList = document.getElementById('toast');"
        "items.forEach(item => {"
        "const li = document.createElement('li');"
        "li.textContent = item;"
        "itemList.appendChild(li);"
        "});"
        "</script>"
        "</body>"
        "</html>";

    request->send(200, "text/html", html);
}
