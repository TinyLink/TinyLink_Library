#include "TH02_Humidity_RPI.h"

TH02_Humidity_RPI::TH02_Humidity_RPI():Sensor(0.0), TH02Humi(TH02_dev::getSingleItem()){
}

int TH02_Humidity_RPI::_read(){
	double chk = (double)TH02Humi.ReadHumidity();
	if (chk){
		_data = chk;
		return 0;
	}
	return -1;
}

#if TINYLINK_HUMIDITY == TH02
	TH02_Humidity_RPI TL_Humidity;
#endif
