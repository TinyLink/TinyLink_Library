#ifndef GROVE_GSR_SKIN_CURRENT_Arduino_UNO_H
#define GROVE_GSR_SKIN_CURRENT_Arduino_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"

class Grove_GSR_Skin_Current_Arduino_UNO:public Sensor<int> {
protected:
	int _read();
public:
	Grove_GSR_Skin_Current_Arduino_UNO();
};

extern Grove_GSR_Skin_Current_Arduino_UNO TL_Skin_Current;

#endif
