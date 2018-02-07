#ifndef GROVE_DC_MOTOR_LINKIT_ONE_H
#define GROVE_DC_MOTOR_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"

class Grove_DC_Motor_Motor_LinkIt_One{
private:
	int stateSig;
public:
	Grove_DC_Motor_Motor_LinkIt_One();
	void turnOn();
	void turnOff();
	const int state();						// 0 for OFF, 1 for ON
};

extern Grove_DC_Motor_Motor_LinkIt_One TL_Motor;

#endif
