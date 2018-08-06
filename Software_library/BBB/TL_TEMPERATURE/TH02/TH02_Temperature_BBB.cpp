#include "TH02_Temperature_BBB.h"

TH02_Temperature_BBB::TH02_Temperature_BBB():Sensor(0.0), TH02Temp(TH02_dev::getSingleItem()){
}

int TH02_Temperature_BBB::_read(){
	double chk = (double)TH02Temp.ReadTemperature();
	if (!isnan(chk)){
		_data = chk;
		return 0;
	}
	return -1;
}
#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_TEMPERATURE == TH02
		TH02_Temperature_BBB TL_Temperature;
	#endif
#endif
