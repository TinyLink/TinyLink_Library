#ifndef GROVE_GSR_SKIN_CURRENT_LINKIT_ONE_H
#define GROVE_GSR_SKIN_CURRENT_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"

class Grove_GSR_Skin_Current_LinkIt_One:public Sensor<int> {
protected:
	int _read();
public:
	Grove_GSR_Skin_Current_LinkIt_One();
};

extern Grove_GSR_Skin_Current_LinkIt_One TL_Skin_Current;

#endif
