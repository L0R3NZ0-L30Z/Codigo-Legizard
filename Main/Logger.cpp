#include "Logger.h"

// Constructor initializes the server and event source
Logger::Logger() : server(80), events("/events") {}

// Initialize Wi-Fi, server, and events if in development mode and not in fight mode
void Logger::init(bool fightMode, bool devMode, int logLevel, const char *ssid, const char *password)
{
    if (!fightMode && devMode)
    {
        Serial.begin(115200);

        WiFi.begin(ssid, password);
        while (WiFi.status() != WL_CONNECTED)
        {
            delay(1000);
            Serial.println("Connecting to WiFi...");
        }
        Serial.println("Connected to WiFi");
        Serial.println(WiFi.localIP());

        events.onConnect([](AsyncEventSourceClient *client)
                         {
if (client->lastId()) {
Serial.printf("Client reconnected! Last message ID it got: %u\n", client->lastId());
}
Serial.println("Client connected to /events");
client->send("Welcome to the event stream!", "message", millis()); });

        server.addHandler(&events);

        server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
                  { request->send(200, "text/html", "<html><body><h1>ESP32 Server</h1></body></html>"); });

        server.on("/", HTTP_OPTIONS, [](AsyncWebServerRequest *request)
                  {
AsyncWebServerResponse *response = request->beginResponse(204);
response->addHeader("Access-Control-Allow-Origin", "*");
response->addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
response->addHeader("Access-Control-Allow-Headers", "Content-Type, Authorization, sec-ch-ua, sec-ch-ua-mobile, sec-ch-ua-platform");
request->send(response); });

        DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
        DefaultHeaders::Instance().addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        DefaultHeaders::Instance().addHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");

        server.onNotFound([](AsyncWebServerRequest *request)
                          { request->send(404, "text/plain", "Not found"); });

        server.begin();
    }
}

void Logger::logMessage(bool fightMode, bool devMode, int logLevel, int state, String message)
{
    if (!fightMode && devMode && logLevel == state)
    {
        events.send(message.c_str(), "message", millis() / 1000);
        
    }
}
