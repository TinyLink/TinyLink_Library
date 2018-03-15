#include "SDS018_PM25_BBB.h"

SDS018_PM25::SDS018_PM25():Sensor(0.0), pm10(0.0){
}

static unsigned char t[10]="";
static int counter = 0;
static int rounds = 0;
static int flag = 0;


int SDS018_PM25::_read(){
	double pm25Sum = 0, pm10Sum = 0;
	rounds = 0;
	//while(1) {
	// TL_Serial2 -> SDS018_PM25_Serial
		while(SDS018_PM25_Serial.available()) {
			// TL_Serial2 -> SDS018_PM25_Serial
			unsigned char ch = SDS018_PM25_Serial.read();
			//cout << "I receive: " << (int)ch << "  counter: " << counter << endl;
			if (ch == 170){
				if (flag == 0){
					flag = 1;
				}
				else {
					if (counter == 10 && t[1] == 192 && t[9] == 171) {
						unsigned char crc = t[2] + t[3] + t[4] + t[5] + t[6] + t[7];
						if (crc == t[8])
						{
							rounds++;
							double pm25Cur = 1.0 * (int(t[3]) * 256 + int(t[2])) / 10;
							double pm10Cur = 1.0 * (int(t[5]) * 256 + int(t[4])) / 10;
							//cout << "PM25: "<< pm25Cur << " PM10: "<< pm10Cur << endl;
							pm25Sum += pm25Cur;
							pm10Sum += pm10Cur;
						}
						else{
							#ifdef DEBUG
							cout << "CRC ERROR"<<endl;
							#endif
							return -1;
						}	

					}
				}	

				counter = 0;
			}
			if(counter == 10) counter = 0;
			t[counter++] = ch;
		}	

		if (flag && rounds){
			_data = pm25Sum / rounds;
			pm10 = pm10Sum / rounds;
			#ifdef DEBUG
			cout << "Reading successfully! PM25: " << _data << " PM10: " <<pm10 <<endl;
			#endif
			return 0;
		}
		//cout << "Reading error! " <<endl;
		return -2;
	//}
}


#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_PM25 == SDS018
		SDS018_PM25 TL_PM25;
	#endif
#endif
