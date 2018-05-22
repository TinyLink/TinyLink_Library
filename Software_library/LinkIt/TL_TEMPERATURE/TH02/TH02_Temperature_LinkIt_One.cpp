#include "TH02_Temperature_LinkIt_One.h"

TH02_Temperature_LinkIt_One::TH02_Temperature_LinkIt_One():Sensor(0.0), sig(0){
}

int TH02_Temperature_LinkIt_One::_read(){
	if(!sig){
		TH02Temp.begin();
		sig = 1;
	}
	double chk = (double)TH02Temp.ReadTemperature();
	if (!isnan(chk)){
		_data = chk;
		return 0;
	}
	return -1;
}

TH02_Temperature_LinkIt_One TL_Temperature;
