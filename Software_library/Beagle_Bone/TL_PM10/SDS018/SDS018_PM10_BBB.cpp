#include "SDS018_PM10_BBB.h"

SDS018_PM10::SDS018_PM10():Sensor(0.0), pm25(0.0){

}

static unsigned char t[10]="";
static int counter = 0;
static int rounds = 0;
static int flag = 0;


int SDS018_PM10::_read(){
	double pm25Sum = 0, pm10Sum = 0;
	rounds = 0;
	//while(1) {
	// TL_Serial2 -> SDS018_PM10_Serial
		while(SDS018_PM10_Serial.available()) {
			// TL_Serial2 -> SDS018_PM10_Serial
			unsigned char ch = SDS018_PM10_Serial.read();
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
							//cout << "PM10: "<< pm25Cur << " PM10: "<< pm10Cur << endl;
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
			pm25 = pm25Sum / rounds;
			_data = pm10Sum / rounds;
			#ifdef DEBUG
			cout << "Reading successfully! PM10: " << pm25 << " PM10: " << _data <<endl;
			#endif
			return 0;
		}
		return -2;
	//}
}


#if PLATFORM == 3 && BOARD == 1005
#if PM10 == SDS018
SDS018_PM10 TL_PM10;
#endif
#endif
