#include "TL_MQTTClient.h"

// MQTT Client
TL_MQTT::TL_MQTT():_serverName(NULL), _port(0), client(ipstack) {
	data = MQTTPacket_connectData_initializer;
}

TL_MQTT::~TL_MQTT() {
	// free a NULL, no operation will performed
	free(_serverName);
}

int TL_MQTT::connect(const char* serverName, int port, const char* clientName, const char* userName, const char* password) {
	_port = port;
	_serverName = (char*)malloc(sizeof(char) * (strlen(serverName) + 1));
	strcpy(_serverName, serverName);
	if(!client.isConnected()) {
		int rc = ipstack.connect(_serverName, _port);
		// the status is differetn from Arduino  0 ? 1
		if (rc != 0){
			return -1;
		}    
		data.MQTTVersion = 4;
		data.clientID.cstring = (char*)clientName;
		data.username.cstring = (char*)userName;
		data.password.cstring = (char*)password;
		rc = client.connect(data);
		return rc;
	} 
	else {
		return 1;
	}
}

int TL_MQTT::connect(const String& serverName, int port, const String& clientName, const String& userName, const String& passW) {
	return connect(serverName.c_str(), port, clientName.c_str(), userName.c_str(), passW.c_str());
}

int TL_MQTT::connect(const string& serverName, int port, const string& clientName, const string& userName, const string& passW) {
	return connect(serverName.c_str(), port, clientName.c_str(), userName.c_str(), passW.c_str());
}


int TL_MQTT::reconnect(){
	if(!client.isConnected()){
		int rc = ipstack.connect(_serverName, _port);
		if (rc != 0){
			return -1;
		}    
		rc = client.connect(data);
		return rc;
	}
	else {
		return 1;
	}
}

int TL_MQTT::disconnect(){
	return client.disconnect();
}

bool TL_MQTT::isConnected(){
	return client.isConnected();
}

int TL_MQTT::publish(const char* topicName, const char* data, int length, int qos, bool retained) {
	if(!reconnect()){
		return -1;
	}
	return client.publish(topicName, (void*)data, length, MQTT::QoS(qos), retained);

}

int TL_MQTT::publish(const string& topicName, const string& data, int length, int qos, bool retained) {
	return publish(topicName.c_str(), data.c_str(), length, qos, retained);
}

int TL_MQTT::publish(const String& topicName, const String& data, int length, int qos, bool retained) {
	return publish(topicName.c_str(), data.c_str(), length, qos, retained);
}



int TL_MQTT::publish(const char* topicName, const char* data, int length, unsigned short& id, int qos, bool retained) { 
	if(!reconnect()){
		return -1;
	}
	return client.publish(topicName, (void*)data, length, id, MQTT::QoS(qos), retained);

}

int TL_MQTT::publish(const string& topicName, const string& data, int length, unsigned short& id, int qos, bool retained) {
	return publish(topicName.c_str(), data.c_str(), length, id, qos, retained);	
}

int TL_MQTT::publish(const String& topicName, const String& data, int length, unsigned short& id, int qos, bool retained) {
	return publish(topicName.c_str(), data.c_str(), length, id, qos, retained);	
}


int TL_MQTT::subscribe(const char* topicFilter, MQTT::Client<IPStack, Countdown>::messageHandler mh, int qos) {
	if(!reconnect()){
		return -1;
	}
	return client.subscribe(topicFilter, MQTT::QoS(qos), mh);
}

int TL_MQTT::subscribe(const string& topicFilter, MQTT::Client<IPStack, Countdown>::messageHandler mh, int qos) {
	return subscribe(topicFilter.c_str(), mh, qos);
}

int TL_MQTT::subscribe(const String& topicFilter, MQTT::Client<IPStack, Countdown>::messageHandler mh, int qos) {
	return subscribe(topicFilter.c_str(), mh, qos);
}


int TL_MQTT::unsubscribe(const char* topicFilter){
	return client.unsubscribe(topicFilter);
}

int TL_MQTT::unsubscribe(const string& topicFilter){
	return unsubscribe(topicFilter.c_str());
}
int TL_MQTT::unsubscribe(const String& topicFilter){
	return unsubscribe(topicFilter.c_str());
}

int TL_MQTT::yield(unsigned long timeout_ms){
	return client.yield(timeout_ms);
}