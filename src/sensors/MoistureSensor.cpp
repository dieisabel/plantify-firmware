#include "sensors/MoistureSensor.hpp"

#include <Arduino.h>

MoistureSensor::MoistureSensor(int relayPin, int hydrometerPin, int interval)
    : relayPin(relayPin), hydrometerPin(hydrometerPin), interval(interval) {}

void MoistureSensor::init() {
    pinMode(relayPin, OUTPUT);
    pinMode(hydrometerPin, INPUT);
}

int MoistureSensor::readData() {
    unsigned long currentTime = millis();
    if (currentTime - lastTime >= interval) {
        digitalWrite(relayPin, HIGH);
        delay(100);
        data = analogRead(hydrometerPin);
        digitalWrite(relayPin, LOW);
        delay(100);
        lastTime = currentTime;
    }
    return data;
}

String MoistureSensor::toString() {
    return String(readData());
}
