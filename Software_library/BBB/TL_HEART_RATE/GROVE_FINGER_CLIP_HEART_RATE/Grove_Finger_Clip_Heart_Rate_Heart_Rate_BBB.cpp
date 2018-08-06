#include "Grove_Finger_Clip_Heart_Rate_Heart_Rate_BBB.h"

Grove_Finger_Clip_Heart_Rate_Heart_Rate_BBB::Grove_Finger_Clip_Heart_Rate_Heart_Rate_BBB(): Sensor(0){
	Wire.begin();
}

int Grove_Finger_Clip_Heart_Rate_Heart_Rate_BBB::_read(){
	Wire.requestFrom(0xA0 >> 1, 1);		// request 1 bytes from slave device
	while(Wire.available()) {			// slave may send less than requested
		_data = Wire.read();   			// receive heart rate value (a byte)
    }
    delay(500);
    return 0;
}

Grove_Finger_Clip_Heart_Rate_Heart_Rate_BBB TL_Heart_Rate;
