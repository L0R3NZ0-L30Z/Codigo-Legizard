/* #include "Logger.h"

Logger::Logger()
  : server(80), events("/events") {}

void Logger::init(bool fightMode, bool devMode, int logLevel, const char *ssid, const char *password) {
  if (!fightMode && devMode) {
    Serial.begin(115200);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
    Serial.println(WiFi.localIP());

    events.onConnect([](AsyncEventSourceClient *client) {
      if (client->lastId()) {
        Serial.printf("Client reconnected! Last message ID it got: %u\n", client->lastId());
      }
      Serial.println("Client connected to /events");
      client->send("Welcome to the event stream!", "message", millis());
    });

    server.addHandler(&events);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
      String htmlResponse = "<html><head><title>Server Side Events</title>"
                            "<style>body {font-family: Calibri; background-color: #21201d; color: #ebe5d3; text-align: center;}"
                            "h1 {font-weight: 1000;}</style></head>"
                            "<body><h1>ESP server</h1>"
                            "<h3>To access the Events go to /events</h3>"
                            "<h3>Para acceder a los eventos ir a /events</h3></body></html>";
      request->send(200, "text/html", htmlResponse);
    });

    server.on("/", HTTP_OPTIONS, [](AsyncWebServerRequest *request) {
      AsyncWebServerResponse *response = request->beginResponse(204);
      response->addHeader("Access-Control-Allow-Origin", "*");
      response->addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
      response->addHeader("Access-Control-Allow-Headers", "Content-Type, Authorization, sec-ch-ua, sec-ch-ua-mobile, sec-ch-ua-platform");
      request->send(response);
    });

    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");

    server.onNotFound([](AsyncWebServerRequest *request) {
      request->send(404, "text/plain", "Not found");
    });

    server.begin();
  }
}



void Logger::logMessage(bool fightMode, bool devMode, int logLevel, int state, String message) {
  if (!fightMode && devMode && logLevel == state) {
    events.send(message.c_str(), "message", millis() / 1000);
  }
}
 */