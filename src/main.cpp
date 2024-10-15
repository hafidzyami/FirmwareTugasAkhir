#include <Arduino.h>
#include "WiFi/WiFiSetup.h"
#include "OTA/OTASetup.h"

void setup()
{
  Serial.begin(115200);
  setupWiFiAP();
  setupOTA();
}

void loop()
{
  // put your main code here, to run repeatedly:
  handleOTA();
}
