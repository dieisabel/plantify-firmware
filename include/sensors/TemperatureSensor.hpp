#ifndef TEMPERATURE_SENSOR_HPP
#define TEMPERATURE_SENSOR_HPP

#include <Arduino.h>
#include <DHT.h>

#include "menu/Printable.hpp"

class TemperatureSensor : public _Printable {
public:
    TemperatureSensor(int pin);
    void init();
    float readData();
    String toString() override;

private:
    int pin;
    DHT sensor;
};

#endif
