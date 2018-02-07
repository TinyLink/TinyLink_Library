#ifndef TL_MQTT_H
#define TL_MQTT_H

#include <Arduino.h>
#if WIFI == ONE_WIFI
	#include <LWiFiClient.h>
#endif
#include <IPStack.h>
#include <Countdown.h>
#include <MQTTClient.h>

class TL_MQTT{
private:
	char* _serverName, *_clientName, *_userName, *_password;
	int _port;
	Client* tcpClient;
	IPStack* ipstack;
	MQTT::Client<IPStack, Countdown, 200>* client;
public:
	TL_MQTT();
	TL_MQTT(const TL_MQTT& mqtt);
	~TL_MQTT();
	TL_MQTT& operator=(const TL_MQTT& mqtt);
	int connect(const char* serverName, const int port, const char* clientName, const char* userName="", const char* password="");			// 0 for success
	//int connect(const String& serverName, const int port, const String& clientName, const String& userName="", const String& password=""); 	// 0 for success
	int reconnect();																// 0 for success
	int disconnect();																// 0 for success
	bool isConnected();																// true for success
	int publish(const char* topicName, const char* data, const int length, const int qos=0);							// 0 for success
	//int publish(const String& topicName, const String& data,  const int length, const int qos=0);							// 0 for success
	//int subscribe(const String& topicFilter, MQTT::Client<IPStack, Countdown>::messageHandler mh, const int qos=0);				// 0 for success
	int subscribe(const char* topicFilter, MQTT::Client<IPStack, Countdown>::messageHandler mh, const int qos=0);					// 0 for success
	//int unsubscribe(const String& topicFilter);													// 0 for success
	int unsubscribe(const char* topicFilter);													// 0 for success
	void yield(const int time=100);
};

#endif
