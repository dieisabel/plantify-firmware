#ifndef LIGHT_SENSOR_HPP
#define LIGHT_SENSOR_HPP

#include <Arduino.h>
#include <BH1750.h>

#include "menu/Printable.hpp"

class LightSensor : public _Printable {
public:
    LightSensor(int address);
    void init();
    float readData();
    String toString() override;

private:
    int address;
    BH1750 sensor;
};

#endif
