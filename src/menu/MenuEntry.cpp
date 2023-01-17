#include "menu/MenuEntry.hpp"

#include <Arduino.h>

#include "sensors/Sensor.hpp"

MenuEntry::MenuEntry(String title, Sensor *sensor)
    : title(title), sensor(sensor) {}

void MenuEntry::setNext(MenuEntry *entry) {
    next = entry;
}

MenuEntry *MenuEntry::getNext() {
    return next;
}

void MenuEntry::setPrevious(MenuEntry *entry) {
    previous = entry;
}

MenuEntry *MenuEntry::getPrevious() {
    return previous;
}

String MenuEntry::getFirstRow() {
    return title;
}

String MenuEntry::getSecondRow() {
    return sensor->toString();
}
