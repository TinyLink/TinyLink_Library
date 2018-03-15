#include "Grove_Light_Light_BBB.h"

Grove_Light_BBB::Grove_Light_BBB(adcPin pin):Sensor(0.0) {
	Grove_Light_Pin = pin;
}

int Grove_Light_BBB::_read() {
	_data = (double)analogRead(Grove_Light_Pin);
	return 1;
}

#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_LIGHT == GROVE_LIGHT
		Grove_Light_BBB TL_Light(LIGHT_ANALOG);
	#endif
#endif
