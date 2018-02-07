TL_HTTP http;
String url("http://10.214.149.119/tinylink/receiveData.php?userid=userID&nodeid=NodeID&temperature=");

void setup() {
  TL_WiFi.init();
  TL_WiFi.join("SSID","Pass");
  http = TL_WiFi.fetchHTTP();
}

void loop() {
  TL_Temperature.read();
  TL_Humidity.read();
  TL_PM25.read();
  http.get(url+String(TL_Temperature.data())+String("&humidity=")+String(TL_Humidity.data())+String("&pm25=")+String(TL_PM25.data()));
  TL_Time.delayMillis(3000);
}