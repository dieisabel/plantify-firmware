#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <Arduino.h>

#define SERIAL_BAUDRATE 115200
#define WAIT 250
#define I2C_SDA D2
#define I2C_SCL D1
#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2
#define DHT_PIN D4
#define BH1750_ADDRESS 0x23
#define BUTTON_LEFT D7
#define BUTTON_RIGHT D6
#define HYDROMETER_RELAY_PIN D5
#define HYDROMETER_PIN A0
#define HYDROMETER_INTERVAL 1000 * 60
#define SERVER_PORT 80

#include "secrets.hpp"

#endif
