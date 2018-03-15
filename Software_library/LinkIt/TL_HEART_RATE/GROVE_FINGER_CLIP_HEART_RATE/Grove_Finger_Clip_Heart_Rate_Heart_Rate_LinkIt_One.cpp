#include "Grove_Finger_Clip_Heart_Rate_Heart_Rate_LinkIt_One.h"

Grove_Finger_Clip_Heart_Rate_Heart_Rate_LinkIt_One::Grove_Finger_Clip_Heart_Rate_Heart_Rate_LinkIt_One(): Sensor(0){
}

int Grove_Finger_Clip_Heart_Rate_Heart_Rate_LinkIt_One::_read(){
	Wire.begin();
	Wire.requestFrom(0xA0 >> 1, 1);			// request 1 bytes from slave device
	while(Wire.available()) {			// slave may send less than requested
		_data = Wire.read();			// receive heart rate value (a byte)
	}
	delay(500);
	return 0;
}

Grove_Finger_Clip_Heart_Rate_Heart_Rate_LinkIt_One TL_Heart_Rate;
