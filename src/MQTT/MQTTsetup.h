#ifndef MQTTSETUP_H
#define MQTTSETUP_H

#include <PubSubClient.h>

extern PubSubClient client;   // Declare the MQTT client as extern

void setupMQTT();
void handleMQTT();
void reconnectMQTT();

#endif
