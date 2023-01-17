#include <Arduino.h>
#include <Wire.h>

#include "sensors/LightSensor.hpp"
#include "sensors/TemperatureSensor.hpp"
#include "menu/Menu.hpp"
#include "menu/MenuEntry.hpp"
#include "io/Button.hpp"
#include "config.hpp"

TemperatureSensor temperatureSensor = TemperatureSensor(DHT_PIN);
LightSensor lightSensor = LightSensor(BH1750_ADDRESS);
Menu menu = Menu(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);
MenuEntry temperatureEntry = MenuEntry("Temperature", &temperatureSensor);
MenuEntry lightEntry = MenuEntry("Light", &lightSensor);
Button leftButton = Button(BUTTON_LEFT);
Button rightButton = Button(BUTTON_RIGHT);

void setup() {
    Serial.begin(SERIAL_BAUDRATE);
    Serial.setDebugOutput(true);
    while (!Serial) {
        delay(WAIT);
    }
    Wire.begin(I2C_SDA, I2C_SCL);
    lightSensor.init();
    temperatureSensor.init();
    temperatureEntry.setNext(&lightEntry);
    lightEntry.setPrevious(&temperatureEntry);
    menu.setCurrent(&temperatureEntry);
    menu.init();
    leftButton.init();
    rightButton.init();
}

void loop() {
    if (leftButton.isPressed()) {
        menu.previous();
    } else if (rightButton.isPressed()) {
        menu.next();
    }
    menu.print();
    delay(100);
}
