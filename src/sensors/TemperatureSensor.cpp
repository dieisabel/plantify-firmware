#include "sensors/TemperatureSensor.hpp"

#include <Arduino.h>
#include <DHT.h>

TemperatureSensor::TemperatureSensor(int pin)
    : pin(pin), sensor(pin, DHT11) {}

void TemperatureSensor::init() {
    sensor.begin();
}

int TemperatureSensor::readData() {
    return (int) sensor.readTemperature();
}

String TemperatureSensor::toString() {
    return String(readData()) + "*C";
}
