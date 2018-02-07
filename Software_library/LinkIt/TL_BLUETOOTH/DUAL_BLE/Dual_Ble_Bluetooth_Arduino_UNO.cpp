#include "Dual_Ble_Bluetooth_Arduino_UNO.h"

int Dual_Ble_Bluetooth::init(){
  Serial1.begin(9600);
  delay(500);
  if(sendBlueToothCommand("AT") != 0){
    return -1;
  }
  return 0;
}

int Dual_Ble_Bluetooth::sendBlueToothCommand(char command[]){
  Serial1.print(command);
  char buf[50];
  if(recvMsg(400, buf) != 0){
    return -1;
  }
  return 0;
}

int Dual_Ble_Bluetooth::recvMsg(unsigned int timeout, char* recv_str){
  unsigned int time = 0;
  unsigned char i;
  i = 0;
  while(1){
    delay(50);
    if(Serial1.available()){
      recv_str[i] = char(Serial1.read());
      i++;
      break;
    }
    time++;
    if(time > (timeout / 50)) return -1;
  }
  while(Serial1.available() && (i < 100)){
    recv_str[i] = char(Serial1.read());
    i++;
  }
  recv_str[i] = '\0';
  return 0;
}

int Dual_Ble_Bluetooth::send(const String& data){
  int res = Serial1.print(data.c_str());
  if(res > 0){
	return 0;
  }else{
	return -1;
  }
}

int Dual_Ble_Bluetooth::send(const char* data){
  int res = Serial1.print(data);
  if(res > 0){
	return 0;
  }else{
	return -1;
  }
}

int Dual_Ble_Bluetooth::recv(String& data){
  char buf[50];
  if(recvMsg(400, buf) != 0){
    return -1;
  }
  data = String(buf);
  return 0;
}

int Dual_Ble_Bluetooth::recv(char* data){
  if(recvMsg(400, data) != 0){
    return -1;
  }
  return 0;
}

Dual_Ble_Bluetooth TL_Bluetooth;
