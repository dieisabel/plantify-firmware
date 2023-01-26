#include "web/WebServer.hpp"

#include <Arduino.h>
#include <ESP8266WebServer.h>

WebServer::WebServer(int port)
    : port(port) {}

void WebServer::init() {
    server.begin(port);
}

void WebServer::handleClient() {
    server.handleClient();
}

void WebServer::on(Uri uri, void (*callback)()) {
    server.on(uri, callback);
}

void WebServer::send(int code, String contentType, String content) {
    server.send(code, contentType, content);
}
