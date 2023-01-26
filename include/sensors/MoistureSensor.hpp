#ifndef MOISTURE_SENSOR_HPP
#define MOISTURE_SENSOR_HPP

#include <Arduino.h>

#include "menu/Printable.hpp"

class MoistureSensor : public _Printable {
public:
    MoistureSensor(int relayPin, int hydrometerPin, int interval);
    void init();
    int readData();
    String toString() override;

private:
    int relayPin;
    int hydrometerPin;
    int data;
    unsigned long lastTime = 0;
    unsigned long interval;
};

#endif
