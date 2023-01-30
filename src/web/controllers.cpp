#include "web/controllers.hpp"

#include <Arduino.h>
#include <ArduinoJson.h>

void sendSensorsData() {
    int temperature = temperatureSensor.readData();
    int light = lightSensor.readData();
    int moisture = moistureSensor.readData();
    StaticJsonDocument<96> document;
    document["temperature"] = temperature;
    document["light"] = light;
    document["moisture"] = moisture;
    String response;
    serializeJson(document, response);
    server.send(200, "application/json", response);
}
