#ifndef LCD_HPP
#define LCD_HPP

#include <LiquidCrystal_I2C.h>

class LCD {
public:
    LCD(int address, int columns, int rows);
    ~LCD();
    void init();
    void setCursor(int row, int column);
    void print(String string);
    void clear();

private:
    int address;
    int columns;
    int rows;
    LiquidCrystal_I2C lcd;
};

#endif
