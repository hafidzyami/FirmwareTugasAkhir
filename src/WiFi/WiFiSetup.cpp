#include "WiFiSetup.h"
#include <WiFi.h>

const char *ssid = "Yoanes Bandung";
const char *password = "";

void setupWiFiAP()
{
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);
  WiFi.setTxPower(WIFI_POWER_19_5dBm);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
}
