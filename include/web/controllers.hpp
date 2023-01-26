#ifndef CONTROLLERS_HPP
#define CONTROLLERS_HPP

#include "web/WebServer.hpp"
#include "sensors/TemperatureSensor.hpp"
#include "sensors/LightSensor.hpp"
#include "sensors/MoistureSensor.hpp"

extern WebServer server;
extern TemperatureSensor temperatureSensor;
extern LightSensor lightSensor;
extern MoistureSensor moistureSensor;

void sendSensorsData();

#endif
