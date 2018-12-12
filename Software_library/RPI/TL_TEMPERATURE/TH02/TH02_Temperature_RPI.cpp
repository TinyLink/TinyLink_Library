#include "TH02_Temperature_RPI.h"

TH02_Temperature_RPI::TH02_Temperature_RPI():Sensor(0.0), TH02Temp(TH02_dev::getSingleItem()){
}

int TH02_Temperature_RPI::_read(){
	double chk = (double)TH02Temp.ReadTemperature();
	if (chk){
		_data = chk;
		return 0;
	}
	return -1;
}

#if TINYLINK_TEMPERATURE == TH02
	TH02_Temperature_RPI TL_Temperature;
#endif
