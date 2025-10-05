#include "Services.h"
#include "Wificonfig.h"



AsyncWebServer server(80);


void Services::begin(){
    if(!LittleFS.begin()) return;

    server.begin();
    delay(10);

}

void Services::start(){
    server.on("/", HTTP_GET, [this](AsyncWebServerRequest *request){
        request->send(LittleFS, "/index.html", "text/html");
    });
    server.on("/scannetwork", HTTP_GET, [this](AsyncWebServerRequest *request){
        String json = this->listSsid;
        request->send(200, "applicaation/json", json);
    });
}

String processor(const String& path){
    File file = LittleFS.open(path, "r");
    if(!file) return "<h1>ERROR</h1>";
    String html = file.readString();  // อ่านทั้งไฟล์ทีเดียว
    file.close();
    return html;
}

void Services::setScanNetwork(String &ssid){
    listSsid = ssid;
  }


