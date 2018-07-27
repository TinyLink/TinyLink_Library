#include "Grove_DC_Motor_Motor_BBB.h"

namespace tinylink{
	Grove_DC_Motor_Motor_BBB::Grove_DC_Motor_Motor_BBB(Pin pin):stateSig(0),_pin(pin){	
		pinMode(_pin, OUTPUT);
		digitalWrite(_pin, LOW);
	}

	void Grove_DC_Motor_Motor_BBB::turnOn(){
		digitalWrite(_pin, HIGH);
		stateSig = 1;
	}

	void Grove_DC_Motor_Motor_BBB::turnOff(){
		digitalWrite(_pin, LOW);
		stateSig = 0;
	}

	const int Grove_DC_Motor_Motor_BBB::state(){
		return stateSig;
	}
}
#if TINYLINK_MOTOR == GROVE_DC_MOTOR
	tinylink::Grove_DC_Motor_Motor_BBB TL_Motor(MOTOR_DIGITAL_OUTPUT);
#endif
