#include "Grove_DC_Motor_Motor_Arduino_Uno.h"

Grove_DC_Motor_Motor_Arduino_Uno::Grove_DC_Motor_Motor_Arduino_Uno():stateSig(0){
	pinMode(MOTOR_DIGITAL_OUTPUT, OUTPUT);
	digitalWrite(MOTOR_DIGITAL_OUTPUT, LOW);
}

void Grove_DC_Motor_Motor_Arduino_Uno::turnOn(){
	digitalWrite(MOTOR_DIGITAL_OUTPUT, HIGH);
	stateSig = 1;
}

void Grove_DC_Motor_Motor_Arduino_Uno::turnOff(){
	digitalWrite(MOTOR_DIGITAL_OUTPUT, LOW);
	stateSig = 0;
}

const int Grove_DC_Motor_Motor_Arduino_Uno::state(){
	return stateSig;
}

Grove_DC_Motor_Motor_Arduino_Uno TL_Motor;
