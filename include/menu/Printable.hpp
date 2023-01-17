#ifndef PRINTABLE_HPP
#define PRINTABLE_HPP

#include <Arduino.h>

// Arduino already have defined Printable interface, so to avoid redefinition added
// _ to class name
class _Printable {
public:
    virtual String toString() = 0;
};

#endif
