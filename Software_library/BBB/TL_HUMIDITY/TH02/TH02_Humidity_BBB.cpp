#include "TH02_Humidity_BBB.h"

TH02_Humidity_BBB::TH02_Humidity_BBB():Sensor(0.0), TH02Humi(TH02_dev::getSingleItem()){
}

int TH02_Humidity_BBB::_read(){
	double chk = (double)TH02Humi.ReadHumidity();
	if (!isnan(chk)){
		_data = chk;
		return 0;
	}
	return -1;
}
#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_HUMIDITY == TH02
			TH02_Humidity_BBB TL_Humidity;
		#endif
#endif
