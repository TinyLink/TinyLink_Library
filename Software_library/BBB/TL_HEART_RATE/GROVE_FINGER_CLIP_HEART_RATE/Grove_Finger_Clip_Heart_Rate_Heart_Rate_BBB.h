#ifndef GROVE_FINGER_CLIP_HEART_RATE_HEART_RATE_BBB_H
#define GROVE_FINGER_CLIP_HEART_RATE_HEART_RATE_BBB_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "Wire.h"


class Grove_Finger_Clip_Heart_Rate_Heart_Rate_BBB: public Sensor<int>{
protected:
	int _read();
public:
	Grove_Finger_Clip_Heart_Rate_Heart_Rate_BBB();
};

extern Grove_Finger_Clip_Heart_Rate_Heart_Rate_BBB TL_Heart_Rate;

#endif
