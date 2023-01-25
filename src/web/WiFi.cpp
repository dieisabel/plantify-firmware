#include "web/WiFi.hpp"

#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "config.hpp"

_WiFi::_WiFi(String ssid, String password)
        : ssid(ssid), password(password) {}

void _WiFi::init() {
    wifi.begin(ssid, password);
    while (wifi.status() != WL_CONNECTED) {
        delay(WAIT);
    }
}

String _WiFi::toString() {
    String ip = String();
    IPAddress address = wifi.localIP();
    // Form a IP string by accessing separate octets and add . between them
    ip += address[0];
    ip += ".";
    ip += address[1];
    ip += ".";
    ip += address[2];
    ip += ".";
    ip += address[3];
    return ip;
}
