#include "Grove_Finger_Clip_Heart_Rate_Heart_Rate_Arduino_UNO.h"

Grove_Finger_Clip_Heart_Rate_Heart_Rate_Arduino_UNO::Grove_Finger_Clip_Heart_Rate_Heart_Rate_Arduino_UNO(): Sensor(0){
	Wire.begin();
}

int Grove_Finger_Clip_Heart_Rate_Heart_Rate_Arduino_UNO::_read(){
	Wire.requestFrom(0xA0 >> 1, 1);		// request 1 bytes from slave device
	while(Wire.available()) {			// slave may send less than requested
		_data = Wire.read();   			// receive heart rate value (a byte)
    }
    delay(500);
    return 0;
}

Grove_Finger_Clip_Heart_Rate_Heart_Rate_Arduino_UNO TL_Heart_Rate;