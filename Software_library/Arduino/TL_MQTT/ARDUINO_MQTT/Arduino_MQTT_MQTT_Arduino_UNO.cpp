#include "Arduino_MQTT_MQTT_Arduino_UNO.h"

TL_MQTT::TL_MQTT():_serverName(NULL), _clientName(NULL), _userName(NULL), _password(NULL), tcpClient(NULL), ipstack(NULL), client(NULL){
#if TINYLINK_WIFI == ESP8266
	if(tcpClient == NULL){
		tcpClient = new WiFiEspClient();
	}
#endif
	if(ipstack == NULL){
		ipstack = new IPStack(*tcpClient);
	}
	if(client == NULL){
		client = new MQTT::Client<IPStack, Countdown, 100>(*ipstack);
	}
}

TL_MQTT::TL_MQTT(const TL_MQTT& mqtt):_serverName(NULL), _clientName(NULL), _userName(NULL), _password(NULL), tcpClient(NULL), ipstack(NULL), client(NULL){
#if TINYLINK_WIFI == ESP8266
	if(tcpClient == NULL){
		tcpClient = new WiFiEspClient();
	}
#endif
	if(ipstack == NULL){
		ipstack = new IPStack(*tcpClient);
	}
	if(client == NULL){
		client = new MQTT::Client<IPStack, Countdown, 100>(*ipstack);
	}
}

TL_MQTT::~TL_MQTT(){
	if(_serverName != NULL){
		delete[] _serverName;
		_serverName = NULL;
	}
	if(_clientName != NULL){
		delete[] _clientName;
		_clientName = NULL;
	}
	if(_userName != NULL){
		delete[] _userName;
		_userName = NULL;
	}
	if(_password != NULL){
		delete[] _password;
		_password = NULL;
	}
	if(client != NULL){
		delete client;
		client = NULL;
	}
	if(ipstack != NULL){
		delete ipstack;
		ipstack = NULL;
	}
	if(tcpClient != NULL){
		delete tcpClient;
		tcpClient = NULL;
	}
}

TL_MQTT& TL_MQTT::operator=(const TL_MQTT& mqtt){
#if TINYLINK_WIFI == ESP8266
	if(tcpClient == NULL){
		tcpClient = new WiFiEspClient();
	}
#endif
	if(ipstack == NULL){
		ipstack = new IPStack(*tcpClient);
	}
	if(client == NULL){
		client = new MQTT::Client<IPStack, Countdown, 100>(*ipstack);
	}
	return *this;
}
/*
int TL_MQTT::connect(const String& serverName, const int port, const String& clientName, const String& userName, const String& password){
	Serial.println(password);
	return connect(serverName.c_str(), port, clientName.c_str(), userName.c_str(), password.c_str());
}
*/
int TL_MQTT::connect(const char* serverName, const int port, const char* clientName, const char* userName, const char* password){
	_port = port;
	if(_serverName != NULL){
		delete[] _serverName;
		_serverName = NULL;
	}
	_serverName = new char[strlen(serverName)+1];
	strcpy(_serverName, serverName);
	if(_clientName != NULL){
		delete[] _clientName;
		_clientName = NULL;
	}
	_clientName = new char[strlen(clientName)+1];
	strcpy(_clientName, clientName);
	if(_userName != NULL){
		delete[] _userName;
		_userName = NULL;
	}
	_userName = new char[strlen(userName)+1];
	strcpy(_userName, userName);
	if(_password != NULL){
		delete[] _password;
		_password = NULL;
	}
	_password = new char[strlen(password)+1];
	strcpy(_password, password);
	if(!client->isConnected()){
		int rc = ipstack->connect(_serverName, _port);
		if (rc != 1){
			return rc;
		}
		MQTTPacket_connectData data = MQTTPacket_connectData_initializer;       
		data.MQTTVersion = 4;
		data.clientID.cstring = _clientName;
		data.username.cstring = _userName;
		data.password.cstring = _password;
		rc = client->connect(data);
		return rc;
	}else{
		return 0;
	}
}

int TL_MQTT::reconnect(){
	if(!client->isConnected()){
		int rc = ipstack->connect(_serverName, _port);
		if (rc != 1){
			return rc;
		}
		MQTTPacket_connectData data = MQTTPacket_connectData_initializer;       
		data.MQTTVersion = 4;
		data.clientID.cstring = _clientName;
		data.username.cstring = _userName;
		data.password.cstring = _password;
		rc = client->connect(data);
		return rc;
	}else{
		return 0;
	}
}

int TL_MQTT::disconnect(){
	client->disconnect();
	return 0;
}

bool TL_MQTT::isConnected(){
	return client->isConnected();
}
/*
int publish(const String& topicName, const String& data,  const int length, const int qos=0){
	return publish(topicName.c_str(), data.c_str(), length, qos);
}
*/
int TL_MQTT::publish(const char* topicName, const char* data, const int length, const int qos){
	if(reconnect()!=0){
		return -1;
	}
	MQTT::Message message;
	message.retained = false;
	message.dup = false;
	switch(qos){
		case 1:{
			message.qos = MQTT::QOS1;
			break;
		}
		case 2:{
			message.qos = MQTT::QOS2;
			break;
		}
		default:{
			message.qos = MQTT::QOS0;
			break;
		}
	}
	message.payload = (void*)data;
	message.payloadlen = length;
	int res = client->publish(topicName, message);
	return res;
}
/*
int subscribe(const String& topicFilter, MQTT::Client<IPStack, Countdown>::messageHandler mh, const int qos=0){
	return subscribe(topicFilter.c_str(), mh, qos);
}
*/
int TL_MQTT::subscribe(const char* topicFilter, MQTT::Client<IPStack, Countdown>::messageHandler mh, const int qos){
	if(reconnect()!=0){
		return -1;
	}
	return client->subscribe(topicFilter, MQTT::QoS(qos), mh);
}
/*
int unsubscribe(const String& topicFilter){
	return unsubscribe(topicFilter.c_str());
}
*/
int TL_MQTT::unsubscribe(const char* topicFilter){
	return client->unsubscribe(topicFilter);
}

void TL_MQTT::yield(const int time){
	client->yield(time);
}
