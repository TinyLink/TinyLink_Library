#ifndef GROVE_DC_MOTOR_RPI_H
#define GROVE_DC_MOTOR_RPI_H


#include "TL_Config.h"
#include "grovepi.h"

namespace tinylink{
	class Grove_DC_Motor_Motor_RPI{
	private:
		int stateSig;
	public:
		Grove_DC_Motor_Motor_RPI();
		void turnOn();
		void turnOff();
		const int state();						// 0 for OFF, 1 for ON
	};
}
#if TINYLINK_MOTOR == GROVE_DC_MOTOR
	extern tinylink::Grove_DC_Motor_Motor_RPI TL_Motor;
#endif

#endif
