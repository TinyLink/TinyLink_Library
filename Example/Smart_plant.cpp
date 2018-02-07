TL_MQTT mqtt;
int port = 1883;
char serverName[] = "120.26.201.44";
char clientName[] = "username";
char pubTopic[] = "10001@wt";
char subTopic[] = "10001@rt";
char userName[] = "username";
char password[] = "pass";

void setup() {
  TL_WiFi.init();
  TL_WiFi.join("SSID","Pass");
  mqtt = TL_WiFi.fetchMQTT();
  mqtt.connect(serverName, port, clientName, userName, password);
}

void loop() {
  TL_Temperature.read();
  TL_Soil_Humidity.read();
  TL_Light.read();
  TL_Temperature.read();
  String data = "{";
  data += "\"Temperature\":";
  data += TL_Temperature.data();
  data += ",\"Soil_Humidity\":";
  data += TL_Soil_Humidity.data();
  data += ",\"Light\":";
  data += TL_Light.data();
  data += "}";
  char buf[100];
  data.toCharArray( buf,100 );
  mqtt.publish(pubTopic, buf, strlen(buf));
  TL_Time.delayMillis(3000);
}