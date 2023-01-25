#ifndef WIFI_HPP
#define WIFI_HPP

#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "menu/Printable.hpp"

// ESP8266WiFi created an object called WiFi, to avoid collision added _ to classname
class _WiFi : public _Printable {
public:
    _WiFi(String ssid, String password);
    void init();
    String toString() override;

private:
    String ssid;
    String password;
    ESP8266WiFiClass wifi;
};

#endif
