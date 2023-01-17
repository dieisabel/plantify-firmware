#include "io/LCD.hpp"

#include <LiquidCrystal_I2C.h>

LCD::LCD(int address, int columns, int rows)
    : address(address), columns(columns), rows(rows), lcd(address, columns, rows) {}

LCD::~LCD() {}

void LCD::init() {
    lcd.init();
    lcd.backlight();
}

void LCD::setCursor(int row, int column) {
    lcd.setCursor(row, column);
}

void LCD::print(String string) {
    lcd.print(string);
}

void LCD::clear() {
    lcd.clear();
}
