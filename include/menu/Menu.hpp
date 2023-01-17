#ifndef MENU_HPP
#define MENU_HPP

#include "io/LCD.hpp"
#include "menu/MenuEntry.hpp"

class Menu {
public:
    Menu(int address, int columns, int rows);
    void init();
    void setCurrent(MenuEntry *entry);
    void next();
    void previous();
    void print();

private:
    int address;
    int columns;
    int rows;
    LCD lcd;
    MenuEntry *current = nullptr;
};

#endif
