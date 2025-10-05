#ifndef SERVICES_H
#define SERVICES_H

#include <LittleFS.h>
// #include <ESP8266WiFi.h>
// #include <ESPAsyncTCP.h>

#if defined(ESP32) || defined(LIBRETINY)
#include <AsyncTCP.h>
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>

class Services {
    private:        
        String processor(const String& path);        
        void setScanNetwork(String& ssid);
        String listSsid = "";
    public:
        void begin();
        void start();

};

#endif
