#include "sensors/TemperatureSensor.hpp"

#include <Arduino.h>
#include <DHT.h>

TemperatureSensor::TemperatureSensor(int pin)
    : pin(pin), sensor(pin, DHT11) {}

void TemperatureSensor::init() {
    sensor.begin();
}

float TemperatureSensor::readData() {
    return sensor.readTemperature();
}

String TemperatureSensor::toString() {
    return String(readData()) + "*C";
}
