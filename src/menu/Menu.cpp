#include "menu/Menu.hpp"

#include "menu/MenuEntry.hpp"

Menu::Menu(int address, int columns, int rows)
    : address(address), columns(columns), rows(rows), lcd(address, columns, rows) {}

void Menu::setCurrent(MenuEntry *entry) {
    current = entry;
}

void Menu::init() {
    lcd.init();
}

void Menu::next() {
    if (current->getNext() != nullptr) {
        current = current->getNext();
    }
}

void Menu::previous() {
    if (current->getPrevious() != nullptr) {
        current = current->getPrevious();
    }
}

void Menu::print() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(current->getFirstRow());
    lcd.setCursor(0, 1);
    lcd.print(current->getSecondRow());
}
