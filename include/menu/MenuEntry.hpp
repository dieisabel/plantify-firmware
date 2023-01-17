#ifndef MENU_ENTRY_HPP
#define MENU_ENTRY_HPP

#include <Arduino.h>

#include "menu/Printable.hpp"

class MenuEntry {
public:
    MenuEntry(String title, _Printable *object);
    void setNext(MenuEntry *entry);
    MenuEntry *getNext();
    void setPrevious(MenuEntry *entry);
    MenuEntry *getPrevious();
    String getFirstRow();
    String getSecondRow();

private:
    String title;
    _Printable *object = nullptr;
    MenuEntry *next = nullptr;
    MenuEntry *previous = nullptr;
};

#endif
