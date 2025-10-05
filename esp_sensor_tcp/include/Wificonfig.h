#ifndef WIFICONFIG_H
#define WIFICONFIG_H


#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <LittleFS.h>
#include <ArduinoJson.h>



class Wificonfig
{
    private:
        bool pin;        
    public:
        String ChipID();
        void softAP(const char* ssid, const char* password);
        static String scanNetwork();
};


#endif