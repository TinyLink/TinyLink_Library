#include "TH02_Temperature_Arduino_UNO.h"

TH02_Temperature_Arduino_UNO::TH02_Temperature_Arduino_UNO():Sensor(0.0), TH02Temp(TH02_dev::getSingleItem()){
}

int TH02_Temperature_Arduino_UNO::_read(){
	double chk = (double)TH02Temp.ReadTemperature();
	if (!isnan(chk)){
		_data = chk;
		return 0;
	}
	return -1;
}

TH02_Temperature_Arduino_UNO TL_Temperature;
