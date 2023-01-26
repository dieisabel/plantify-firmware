#ifndef WEB_SERVER_HPP
#define WEB_SERVER_HPP

#include <Arduino.h>
#include <ESP8266WebServer.h>

class WebServer {
public:
    WebServer(int port);
    void init();
    void handleClient();
    void on(Uri uri, void (*callback)());
    void send(int code, String contentType, String content);

private:
    int port;
    ESP8266WebServer server;
};

#endif
