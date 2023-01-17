#include "io/Button.hpp"

#include <Arduino.h>

Button::Button(int pin)
    : pin(pin) {}

void Button::init() {
    pinMode(pin, INPUT_PULLUP);
}

bool Button::isPressed() {
    return !digitalRead(pin);
}
