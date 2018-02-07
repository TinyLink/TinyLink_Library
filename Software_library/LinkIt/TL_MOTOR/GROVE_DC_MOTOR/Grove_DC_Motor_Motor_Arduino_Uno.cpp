#include "Grove_DC_Motor_Motor_LinkIt_One.h"

Grove_DC_Motor_Motor_LinkIt_One::Grove_DC_Motor_Motor_LinkIt_One():stateSig(0){
	pinMode(MOTOR_DIGITAL_OUTPUT, OUTPUT);
	digitalWrite(MOTOR_DIGITAL_OUTPUT, LOW);
}

void Grove_DC_Motor_Motor_LinkIt_One::turnOn(){
	digitalWrite(MOTOR_DIGITAL_OUTPUT, HIGH);
	stateSig = 1;
}

void Grove_DC_Motor_Motor_LinkIt_One::turnOff(){
	digitalWrite(MOTOR_DIGITAL_OUTPUT, LOW);
	stateSig = 0;
}

const int Grove_DC_Motor_Motor_LinkIt_One::state(){
	return stateSig;
}

Grove_DC_Motor_Motor_LinkIt_One TL_Motor;
