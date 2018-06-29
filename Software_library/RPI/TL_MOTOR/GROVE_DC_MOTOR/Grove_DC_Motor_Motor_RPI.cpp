#include "Grove_DC_Motor_Motor_RPI.h"

namespace tinylink{
	Grove_DC_Motor_Motor_RPI::Grove_DC_Motor_Motor_RPI(int pin):stateSig(0),_pin(pin){
		if (init_dev() == -1) 
			exit(-1);	
		pinMode(_pin, OUTPUT);
		digitalWrite(_pin, LOW);
	}

	void Grove_DC_Motor_Motor_RPI::turnOn(){
		digitalWrite(_pin, HIGH);
		stateSig = 1;
	}

	void Grove_DC_Motor_Motor_RPI::turnOff(){
		digitalWrite(_pin, LOW);
		stateSig = 0;
	}

	const int Grove_DC_Motor_Motor_RPI::state(){
		return stateSig;
	}
}
#if TINYLINK_MOTOR == GROVE_DC_MOTOR
	tinylink::Grove_DC_Motor_Motor_RPI TL_Motor(MOTOR_DIGITAL_OUTPUT);
#endif
