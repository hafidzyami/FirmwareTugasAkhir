#include "MQTTsetup.h"
#include <WiFi.h>
#include <PubSubClient.h>

// WiFiClient and PubSubClient instances
WiFiClient espClient;
PubSubClient client(espClient);

const char *mqtt_server = "mqtt.eclipseprojects.io";  // Replace with your MQTT Broker IP or domain

void setupMQTT()
{
    client.setServer(mqtt_server, 80);  // Configure MQTT server
}

void handleMQTT()
{
    if (!client.connected())
    {
        reconnectMQTT();
    }
    client.loop();  // Keep the MQTT connection alive
}

void reconnectMQTT()
{
    // Loop until we're reconnected
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        // Attempt to connect
        if (client.connect("ESP32Client"))
        {
            Serial.println("connected");
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);  // Wait 5 seconds before retrying
        }
    }
}
