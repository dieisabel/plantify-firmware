#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <Arduino.h>

class Sensor {
public:
    virtual void init() = 0;
    virtual float readData() = 0;
    virtual String toString() = 0;
};

#endif
