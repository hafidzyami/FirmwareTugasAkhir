#include "WiFiSetup.h"
#include <WiFi.h>

const char *ssid = "Your-WiFi-SSID";       
const char *password = "Your-WiFi-PASSWORD";

const char *ap_ssid = "Yoanes Bandung AP"; 
const char *ap_password = "";             

void setupWiFi()
{
    WiFi.mode(WIFI_MODE_APSTA); 
    
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }
    
    Serial.println("");
    Serial.println("Connected to WiFi!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

// Set up the ESP32 as an access point (AP)
void setupWiFiAP()
{
    Serial.print("Setting up Access Point (AP)...");
    
    // Create access point
    WiFi.softAP(ap_ssid, ap_password);
    WiFi.setTxPower(WIFI_POWER_19_5dBm); // Optional: Adjust TX power level if needed
    
    IPAddress AP_IP = WiFi.softAPIP(); // Get the IP address of the AP
    Serial.print("AP IP address: ");
    Serial.println(AP_IP); // Print the access point IP address
}
