#include <Arduino.h>
#include <Wire.h>

#include "sensors/LightSensor.hpp"
#include "sensors/TemperatureSensor.hpp"
#include "sensors/MoistureSensor.hpp"
#include "menu/Menu.hpp"
#include "menu/MenuEntry.hpp"
#include "io/Button.hpp"
#include "web/WiFi.hpp"
#include "web/WebServer.hpp"
#include "web/controllers.hpp"
#include "config.hpp"

void connectMenuEntries();

_WiFi wifi = _WiFi(WIFI_SSID, WIFI_PASSWORD);
WebServer server = WebServer(SERVER_PORT);
TemperatureSensor temperatureSensor = TemperatureSensor(DHT_PIN);
LightSensor lightSensor = LightSensor(BH1750_ADDRESS);
MoistureSensor moistureSensor = MoistureSensor(HYDROMETER_RELAY_PIN, HYDROMETER_PIN, HYDROMETER_INTERVAL);
Menu menu = Menu(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);
MenuEntry temperatureEntry = MenuEntry("Temperature", &temperatureSensor);
MenuEntry lightEntry = MenuEntry("Light", &lightSensor);
MenuEntry moistureEntry = MenuEntry("Soil Moisture", &moistureSensor);
MenuEntry wifiEntry = MenuEntry("WiFi IP", &wifi);
Button leftButton = Button(BUTTON_LEFT);
Button rightButton = Button(BUTTON_RIGHT);

void setup() {
    Serial.begin(SERIAL_BAUDRATE);
    Serial.setDebugOutput(true);
    while (!Serial) {
        delay(WAIT);
    }
    Wire.begin(I2C_SDA, I2C_SCL);
    wifi.init();
    lightSensor.init();
    temperatureSensor.init();
    moistureSensor.init();
    connectMenuEntries();
    menu.setCurrent(&temperatureEntry);
    menu.init();
    leftButton.init();
    rightButton.init();
    server.on("/sensors", sendSensorsData);
    server.init();
}

void connectMenuEntries() {
    temperatureEntry.setNext(&lightEntry);
    lightEntry.setPrevious(&temperatureEntry);
    lightEntry.setNext(&moistureEntry);
    moistureEntry.setPrevious(&lightEntry);
    moistureEntry.setNext(&wifiEntry);
    wifiEntry.setPrevious(&moistureEntry);
}

void loop() {
    if (leftButton.isPressed()) {
        menu.previous();
    } else if (rightButton.isPressed()) {
        menu.next();
    }
    menu.print();
    server.handleClient();
    delay(100);
}
