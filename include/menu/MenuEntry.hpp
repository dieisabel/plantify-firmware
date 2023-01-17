#ifndef MENU_ENTRY_HPP
#define MENU_ENTRY_HPP

#include <Arduino.h>

#include "sensors/Sensor.hpp"

class MenuEntry {
public:
    MenuEntry(String title, Sensor *sensor);
    void setNext(MenuEntry *entry);
    MenuEntry *getNext();
    void setPrevious(MenuEntry *entry);
    MenuEntry *getPrevious();
    String getFirstRow();
    String getSecondRow();

private:
    String title;
    Sensor *sensor = nullptr;
    MenuEntry *next = nullptr;
    MenuEntry *previous = nullptr;
};

#endif
