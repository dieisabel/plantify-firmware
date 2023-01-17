#ifndef TEMPERATURE_SENSOR_HPP
#define TEMPERATURE_SENSOR_HPP

#include <Arduino.h>
#include <DHT.h>

#include "sensors/Sensor.hpp"

class TemperatureSensor : public Sensor {
public:
    TemperatureSensor(int pin);
    void init() override;
    float readData() override;
    String toString() override;

private:
    int pin;
    DHT sensor;
};

#endif
