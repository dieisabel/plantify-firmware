#ifndef BUTTON_HPP
#define BUTTON_HPP

class Button {
public:
    Button(int pin);
    void init();
    bool isPressed();

private:
    int pin;
};

#endif
