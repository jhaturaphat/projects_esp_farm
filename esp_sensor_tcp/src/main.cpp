#include <Arduino.h>
#include "Wificonfig.h"
#include "Services.h"
#include <LittleFS.h>

#define PIN_SETUP 3

Wificonfig wlan;
Services services;

void setup() {
  // put your setup code here, to run once:
  wlan.softAP("esp8266","");
}

void loop() {
  // put your main code here, to run repeatedly:  
}
