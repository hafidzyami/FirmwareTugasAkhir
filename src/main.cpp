#include <Arduino.h>
#include "WiFi/WiFiSetup.h"
#include "OTA/OTASetup.h"
#include <TinyGPS++.h>
#include <HardwareSerial.h>
#include <GPS/GPSsetup.h>

void setup()
{
  Serial.begin(115200);
  setupWiFiAP();
  setupOTA();
  setupGPS();
}


void loop()
{
  handleOTA();
  handleGPS();
}
