REQUIRE("BeagleBone Black");
TL_MQTT mqtt;

int port = 1883;
/*
char serverName[]= "a1oc7wU4yWd.iot-as-mqtt.cn-shanghai.aliyuncs.com";
char clientName[] = "549642238|securemode=3,signmethod=hmacsha1,timestamp=132323232|";
char userName[] = "rhcqdk8RtZOgJeJ0bIK5&a1oc7wU4yWd";
char password[] = "f8e751017aebbdd3f1f246cd3ac7926a1f128a1c";
*/
char serverName[]= "a1oc7wU4yWd.iot-as-mqtt.cn-shanghai.aliyuncs.com";
char clientName[] = "549642238|securemode=3,signmethod=hmacsha1,timestamp=132323232|";
char userName[] = "testDevice1&a1oc7wU4yWd";
char password[] = "2ee99556711f9bf6bad02c4eabf3e952a4be3e41";

char propertyPostTopic[] = "/sys/a1oc7wU4yWd/testDevice1/thing/event/property/post";
char propertyGetTopic[] = "/sys/a1oc7wU4yWd/testDevice1/thing/service/property/get";
char serviceOnFanCallTopic[] = "/sys/a1oc7wU4yWd/testDevice1/thing/service/TURNON_FAN";
char serviceOnFanReplyTopic[] = "/sys/a1oc7wU4yWd/testDevice1/thing/service/TURNON_FAN_reply";
char serviceOffFanCallTopic[] = "/sys/a1oc7wU4yWd/testDevice1/thing/service/TURNOFF_FAN";
char serviceOffFanReplyTopic[] = "/sys/a1oc7wU4yWd/testDevice1/thing/service/TURNOFF_FAN_reply";
unsigned int messageID = 0;

void fetchEle(const char* origin, const char* para, char* res){
	char* content = (char*)malloc(sizeof(char)*(strlen(origin)+1));
	strncpy(content, origin+1, strlen(origin)-2);
	char* target;
	char* items = strtok(content, ",");
	while(items!=NULL){
		while(items[0] == ' '){
			++items;
		}
		if(strncmp(items, para, strlen(para)) == 0){
			target = items;
		}
		items = strtok(NULL, ",");
	}
	while(target[0] != ':'){
		++target;
	}
	while(target[0] == ' '){
		++target;
	}
	strncpy(res, target+1, strlen(target)-2);
	free(content);
}

void propertyGetTopicMethod(MQTT::MessageData& md){
	cout<<"Property get"<<endl;
    MQTT::Message &message = md.message;
	char* res = (char*)malloc(sizeof(char)*(message.payloadlen+1));
	strncpy(res, (char*)message.payload, message.payloadlen);
	char properties[100];
	fetchEle(res, "\"params\"", properties);
	char* item = strtok(properties, ",");
	char property[30];
	char buf[200];
	String payload = "{\"id\":\"";
	payload += messageID;
	payload += "\"";
	payload += ",\"code\":200";
	payload += ",\"data\":{";
	int first = 1;
	while(item != NULL){
		int i = 0;
		while(item[0] == ' '){
			++item;
		}
		while(item[i+1] != '"'){
			property[i] = tolower(item[i+1]);
			++i;
		}
		property[i] = '\0';
		if(strcmp(property, "currenttemperature") == 0){
			if(first != 1){
				payload += ",";
			}else{
				first = 0;
			}
			payload += "\"CurrentTemperature\":";
			payload += TL_Temperature.data();
		}else if(strcmp(property, "relativehumidity") == 0){
			if(first != 1){
				payload += ",";
			}else{
				first = 0;
			}
			payload += "\"RelativeHumidity\":";
			payload += TL_Humidity.data();
		}
		item = strtok(NULL, ",");
	}
	payload += "}}";
	int payloadlength = payload.length();
	payload.toCharArray( buf, 200 );
	mqtt.publish(propertyPostTopic, buf, payloadlength);
	messageID++;
	free(res);
}

void serviceOnFanCallTopicMethod(MQTT::MessageData& md){
	cout<<"Turn on fan"<<endl;
	MQTT::Message &message = md.message;
	char* res = (char*)malloc(sizeof(char)*(message.payloadlen+1));
	strncpy(res, (char*)message.payload, message.payloadlen);
	TL_LED.turnOn();
	char buf[200];
	String payload = "{\"id\":\"";
	payload += messageID;
	payload += "\"";
	payload += ",\"code\":200";
	payload += ",\"data\":{";
	payload += "}}";
	int payloadlength = payload.length();
	payload.toCharArray( buf, 200 );
	mqtt.publish(serviceOnFanReplyTopic, buf, payloadlength);
	messageID++;
	free(res);
}

void serviceOffFanCallTopicMethod(MQTT::MessageData& md){
	cout<<"Turn off fan"<<endl;
	MQTT::Message &message = md.message;
	char* res = (char*)malloc(sizeof(char)*(message.payloadlen+1));
	strncpy(res, (char*)message.payload, message.payloadlen);
	TL_LED.turnOff();
	char buf[200];
	String payload = "{\"id\":\"";
	payload += messageID;
	payload += "\"";
	payload += ",\"code\":200";
	payload += ",\"data\":{";
	payload += "}}";
	int payloadlength = payload.length();
	payload.toCharArray( buf, 200 );
	mqtt.publish(serviceOffFanReplyTopic, buf, payloadlength);
	messageID++;
	free(res);
}

void setup() {
	TL_WiFi.init();
	TL_WiFi.join("EmNets-301","eagle402");
	mqtt = TL_WiFi.fetchMQTT();
	mqtt.connect(serverName, port, clientName, userName, password);
	// Subscribe topics
	mqtt.subscribe(propertyGetTopic, propertyGetTopicMethod, 0);
	mqtt.subscribe(serviceOnFanCallTopic, serviceOnFanCallTopicMethod, 0);
	mqtt.subscribe(serviceOffFanCallTopic, serviceOffFanCallTopicMethod, 0);
	
}

void loop() {
	TL_Temperature.read();
	TL_Humidity.read();
	char buf[200];
	String payload = "{\"id\":\"";
	payload += messageID;
	payload += "\"";
	payload += ",\"version\":\"1.0\"";
	payload += ",\"params\":{\"CurrentTemperature\":";
	payload += TL_Temperature.data()+30;
	payload += ",";
	payload += "\"RelativeHumidity\":";
	payload += TL_Humidity.data()+42;
	payload += "},\"method\":\"thing.event.property.post\"}";
	int payloadlength = payload.length();
	payload.toCharArray( buf, 200 );
	cout<<buf<<endl;
	mqtt.publish(propertyPostTopic, buf, payloadlength);
	messageID++;
	mqtt.yield(3000);
}
