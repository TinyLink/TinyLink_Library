TL_MQTT mqtt;
int port = 1883;
char serverName[] = "120.26.201.44";
char clientName[] = "username";
char pubTopic[] = "10001@wt";
char subTopic[] = "10001@rt";
char userName[] = "username";
char password[] = "pass";

int aig = 0;

void messageArrived(MQTT::MessageData& md){
  MQTT::Message &message = md.message;
  char res[20];
  strncpy(res, (char*)message.payload, 19);
  if(strncmp(res, "MOTOR_TURNON", strlen("MOTOR_TURNON")) == 0){
	aig = 1;
    TL_Motor.turnOn();
  }else if(strncmp(res, "MOTOR_TURNOFF", strlen("MOTOR_TURNOFF")) == 0){
	aig = 0;
    TL_Motor.turnOff();
  }
}

void setup() {
  TL_WiFi.init();
  TL_WiFi.join("SSID","Pass");
  mqtt = TL_WiFi.fetchMQTT();
  mqtt.connect(serverName, port, clientName, userName, password);
  mqtt.subscribe(subTopic, messageArrived, 0);
}

void loop() {
  TL_Temperature.read();
  String data = "{";
  data += "\"Motor\":";
  data += TL_Motor.state();
  data += ",\"Temperature\":";
  data += TL_Temperature.data();
  data += "}";
  if(TL_Temperature.data()>35){
	TL_Motor.turnOn();
  }else{
	if(aig == 0){
	  TL_Motor.turnOff();
	}
  }
  char buf[100];
  data.toCharArray( buf,100 );
  mqtt.publish(pubTopic, buf, strlen(buf));
  mqtt.yield(2000);
}