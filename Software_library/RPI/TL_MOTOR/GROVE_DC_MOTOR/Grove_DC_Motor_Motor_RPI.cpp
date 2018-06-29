#include "Grove_DC_Motor_Motor_RPI.h"

namespace tinylink{
	Grove_DC_Motor_Motor_RPI::Grove_DC_Motor_Motor_RPI():stateSig(0){
		if (init_dev() == -1) 
			exit(-1);	
		pinMode(MOTOR_DIGITAL_OUTPUT, OUTPUT);
		digitalWrite(MOTOR_DIGITAL_OUTPUT, LOW);
	}

	void Grove_DC_Motor_Motor_RPI::turnOn(){
		digitalWrite(MOTOR_DIGITAL_OUTPUT, HIGH);
		stateSig = 1;
	}

	void Grove_DC_Motor_Motor_RPI::turnOff(){
		digitalWrite(MOTOR_DIGITAL_OUTPUT, LOW);
		stateSig = 0;
	}

	const int Grove_DC_Motor_Motor_RPI::state(){
		return stateSig;
	}
}
#if TINYLINK_MOTOR == GROVE_DC_MOTOR
	tinylink::Grove_DC_Motor_Motor_RPI TL_Motor;
#endif
