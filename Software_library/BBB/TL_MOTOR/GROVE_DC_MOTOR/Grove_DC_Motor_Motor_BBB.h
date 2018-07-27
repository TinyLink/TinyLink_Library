#ifndef GROVE_DC_MOTOR_BBB_H
#define GROVE_DC_MOTOR_BBB_H


#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream>
#include <cstdio>
#include "CommonDefines.h"
#include "GPIO.h"
#include "OVERLAY.h"
#include "TL_Config.h"

namespace tinylink{
	class Grove_DC_Motor_Motor_BBB{
	private:
		int stateSig;
		Pin _pin;
	public:
		Grove_DC_Motor_Motor_BBB(Pin pin);
		void turnOn();
		void turnOff();
		const int state();						// 0 for OFF, 1 for ON
	};
}
#if TINYLINK_MOTOR == GROVE_DC_MOTOR
	extern tinylink::Grove_DC_Motor_Motor_BBB TL_Motor;
#endif

#endif
