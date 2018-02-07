#include "Dual_Ble_Bluetooth_Arduino_UNO.h"

#if BLUETOOTH_UART_TX == 0 && BLUETOOTH_UART_RX == 1
	#define blueToothSerial Serial
#else
	SoftwareSerial blueToothSerial(BLUETOOTH_UART_TX, BLUETOOTH_UART_RX);
#endif

int Dual_Ble_Bluetooth::init(const String& name){
	blueToothSerial.begin(9600);
	delay(500);
	String command = String("AT+NAME")+name;
	if(sendBlueToothCommand(command.c_str()) != 0){
		return -1;
	}
	command = String("AT+NAMB")+name;
	if(sendBlueToothCommand(command.c_str()) != 0){
		return -1;
	}
	sendBlueToothCommand("AT+RESET");
    	blueToothSerial.begin(9600);
	delay(3000);
	if(sendBlueToothCommand("AT") != 0){
		return -1;
	}
	return 0;
}

int Dual_Ble_Bluetooth::init(const char* name){
	blueToothSerial.begin(9600);
	delay(500);
	String command = String("AT+NAME")+String(name);
	if(sendBlueToothCommand(command.c_str()) != 0){
		return -1;
	}
	command = String("AT+NAMB")+name;
	if(sendBlueToothCommand(command.c_str()) != 0){
		return -1;
	}
	sendBlueToothCommand("AT+RESET");
    	blueToothSerial.begin(9600);
	delay(3000);
	if(sendBlueToothCommand("AT") != 0){
		return -1;
	}
	return 0;
}

int Dual_Ble_Bluetooth::sendBlueToothCommand(const char command[]){
	blueToothSerial.print(command);
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
		if(blueToothSerial.available()){
			recv_str[i] = char(blueToothSerial.read());
			i++;
			break;
		}
		time++;
		if(time > (timeout / 50)) return -1;
	}
	while(blueToothSerial.available() && (i < 100)){
		recv_str[i] = char(blueToothSerial.read());
		i++;
	}
	recv_str[i] = '\0';
	return 0;
}

int Dual_Ble_Bluetooth::send(const String& data){
	int res = blueToothSerial.print(data.c_str());
	if(res > 0){
		return 0;
	}else{
		return -1;
	}
}

int Dual_Ble_Bluetooth::send(const char* data){
	int res = blueToothSerial.print(data);
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
