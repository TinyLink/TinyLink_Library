#include "SDS018_PM25_LinkIt_One.h"

SDS018_PM25_LinkIt_One::SDS018_PM25_LinkIt_One():Sensor(0.0), start(0), pm25(0), pm10(0){
}

int SDS018_PM25_LinkIt_One::_read(){
	if(!start){
		Serial1.begin(9600);
		start = 1;
	}
	unsigned char t[10];
	int counter = 0;
	int rounds = 0;
	int flag = 0;

	double pm25Sum;
	double pm10Sum;

	pm25 = pm10 = pm25Sum = pm10Sum = 0;

	while(Serial1.available()){
		unsigned char ch = Serial1.read();
		if (ch == 170){
			if (flag == 0){
				flag = 1;
			}else{
				if (counter == 10 && t[1] == 192 && t[9] == 171){
					unsigned char crc = t[2] + t[3] + t[4] + t[5] + t[6] + t[7];
					if (crc == t[8]){
						rounds++;
						double pm25Cur = 1.0 * (int(t[3]) * 256 + int(t[2])) / 10;
						double pm10Cur = 1.0 * (int(t[5]) * 256 + int(t[4])) / 10;
						pm25Sum += pm25Cur;
						pm10Sum += pm10Cur;
					}else{
						// writeFile(String() + "\n" + "CRC error");
					}
				}else{
					// writeFile(String() + "Counter: " + counter + "\nChars: ");
					// Serial.write(t, counter);
					// Serial.println("");
				}
			}
			counter = 0;
		}
		t[counter++] = ch;
	}
	delay(2000);
	if (flag && rounds > 0){
		pm25 = pm25Sum / rounds;
		pm10 = pm10Sum / rounds;
		_data = pm25;
		// writeFile(String() + "SDS018_PM25_LinkIt_One sample rounds: " + rounds);
		return 0;
	}else{
		// writeFile("No SDS data available");
		return -1;
	}
}

SDS018_PM25_LinkIt_One TL_PM25;
