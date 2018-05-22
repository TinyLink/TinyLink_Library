#include "TH02_Humidity_Arduino_UNO.h"

TH02_Humidity_Arduino_UNO::TH02_Humidity_Arduino_UNO():Sensor(0.0), TH02Humi(TH02_dev::getSingleItem()){
}

int TH02_Humidity_Arduino_UNO::_read(){
	double chk = (double)TH02Humi.ReadHumidity();
	if (!isnan(chk)){
		_data = chk;
		return 0;
	}
	return -1;
}

TH02_Humidity_Arduino_UNO TL_Humidity;
