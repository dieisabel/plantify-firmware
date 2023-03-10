#include "sensors/LightSensor.hpp"

#include <Arduino.h>
#include <BH1750.h>

LightSensor::LightSensor(int address)
    : address(address) {}

void LightSensor::init() {
    sensor.begin(BH1750::Mode::CONTINUOUS_HIGH_RES_MODE, address);
}

int LightSensor::readData() {
    return (int) sensor.readLightLevel();
}

String LightSensor::toString() {
    return String(readData()) + String("Lux");
}
