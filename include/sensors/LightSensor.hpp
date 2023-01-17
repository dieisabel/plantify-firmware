#ifndef LIGHT_SENSOR_HPP
#define LIGHT_SENSOR_HPP

#include <Arduino.h>
#include <BH1750.h>

#include "sensors/Sensor.hpp"

class LightSensor : public Sensor {
public:
    LightSensor(int address);
    void init() override;
    float readData() override;
    String toString() override;

private:
    int address;
    BH1750 sensor;
};

#endif
