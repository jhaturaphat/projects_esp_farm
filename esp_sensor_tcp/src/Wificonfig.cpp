#include "Wificonfig.h"

void Wificonfig::softAP(const char* ssid, const char* password){
    // เริ่ม Access point 
    WiFi.softAP(ssid, password);
    delay(100); //หน่วงเวลา 100 ms เพื่อให้ AP เริ่มทำงาน

    // เริ่ม mDNS ด้วยชื่อ jaturapat
    if(!MDNS.begin("jaturapat")){
        return;
    }

    // เพิ่มบริการ http ให้ mDNS
    MDNS.addService("http", "tcp", 80);    

}



String Wificonfig::scanNetwork() { 
    int n = WiFi.scanNetworks();     
     String str = "[";       
    if (n == 0) {
            
        return "[{}]";
    } else {          
        for (int i = 0; i < n; ++i) {   
            if(i == (n-1)){
            str += "{\"ssid\":\""+WiFi.SSID(i)+"\",\"rssi\":"+WiFi.RSSI(i)+"}]";        
            }else{
            str += "{\"ssid\":\""+WiFi.SSID(i)+"\",\"rssi\":"+WiFi.RSSI(i)+"},";
            }  
        }                        
        return str;
    }
}

String Wificonfig::ChipID(){
    String ChipID = "esp_123456";
    return String(ESP.getChipId());
}