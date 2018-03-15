#ifndef GROVE_DC_MOTOR_ARDUINO_UNO_H
#define GROVE_DC_MOTOR_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"

class Grove_DC_Motor_Motor_Arduino_UNO{
private:
	int stateSig;
public:
	Grove_DC_Motor_Motor_Arduino_UNO();
	void turnOn();
	void turnOff();
	const int state();						// 0 for OFF, 1 for ON
};

extern Grove_DC_Motor_Motor_Arduino_UNO TL_Motor;

#endif
