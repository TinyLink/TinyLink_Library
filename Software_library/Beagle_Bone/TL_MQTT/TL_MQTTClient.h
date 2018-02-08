#ifndef TL_MQTT_H
#define TL_MQTT_H

#include "mqtt_linux.h"
#include "MQTTClient.h"
#include <cstdio>
#include <iostream>
#include "WString.h"

class TL_MQTT {
private:
	char* _serverName; 
	int _port;
	IPStack ipstack;
	MQTT::Client<IPStack, Countdown, 200> client;
	MQTTPacket_connectData data;
public:
	TL_MQTT();
	~TL_MQTT();
	// copy constructor function
/*	TL_MQTT(const TL_MQTT& temp): _port(temp._port) ,ipstack(temp.ipstack), client() data(temp.data) {
		_serverName = (char*)malloc(sizeof(char) * (strlen(temp.serverName) + 1));
		strcpy(_serverName, temp.serverName);	
	}
	// operator = overload function
	TL_MQTT& operator= (const TL_MQTT& temp): _port(temp._port), data(temp.data){
		_serverName = (char*)malloc(sizeof(char) * (strlen(temp.serverName) + 1));
		strcpy(_serverName, temp.serverName);

	}*/

		
	// 0 success
	// -1 fail
	// 1 previously connected
	int connect(const char* serverName, int port, const char* clientName, const char* userName="", const char* passW="");	
	int connect(const String& serverName, int port, const String& clientName, const String& userName="", const String& passW = "");
	int connect(const string& serverName, int port, const string& clientName, const string& userName="", const string& passW = "");
	//  prevent a timeout
	int reconnect();											
	int disconnect();											
	bool isConnected();											
	// the second param. origin void* ? but in the implementation the void* is translated to unsigned char*
	int publish(const char* topicName, const char* data, int length, int qos = 0, bool retained = false);
	int publish(const String& topicName, const String& data, int length, int qos = 0, bool retained = false);
	int publish(const string& topicName, const string& data, int length, int qos = 0, bool retained = false);

	int publish(const char* topicName, const char* data, int length, unsigned short& id, int qos = 1, bool retained = false);
	int publish(const String& topicName, const String& data, int length, unsigned short& id, int qos = 1, bool retained = false);
	int publish(const string& topicName, const string& data, int length, unsigned short& id, int qos = 1, bool retained = false);

	int subscribe(const char* topicFilter, MQTT::Client<IPStack, Countdown>::messageHandler mh, int qos = 0);
	int subscribe(const String& topicFilter, MQTT::Client<IPStack, Countdown>::messageHandler mh, int qos = 0);
	int subscribe(const string& topicFilter, MQTT::Client<IPStack, Countdown>::messageHandler mh, int qos = 0);

	int unsubscribe(const char* topicFilter); 
	int unsubscribe(const String& topicFilter);
	int unsubscribe(const string& topicFilter);

	int yield(unsigned long timeout_ms = 1000L);					
};


#endif
