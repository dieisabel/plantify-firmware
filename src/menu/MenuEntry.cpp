#include "menu/MenuEntry.hpp"

#include <Arduino.h>

#include "menu/Printable.hpp"

MenuEntry::MenuEntry(String title, _Printable *object)
    : title(title), object(object) {}

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
    return object->toString();
}
