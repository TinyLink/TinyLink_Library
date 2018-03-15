#ifndef GROVE_RELAY_RELAY_ARDUINO_UNO_H
#define GROVE_RELAY_RELAY_ARDUINO_UNO_H

class Grove_Relay_Relay_Arduino_UNO{
private:
	int stateSig;
public:
	Grove_Relay_Relay_Arduino_UNO();
	void turnOn();
	void turnOff();
	void toggle();
	const int state();
};

extern Grove_Relay_Relay_Arduino_UNO TL_Relay;

#endif
