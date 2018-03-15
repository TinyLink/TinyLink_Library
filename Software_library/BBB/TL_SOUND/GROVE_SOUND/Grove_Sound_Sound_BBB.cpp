#include "Grove_Sound_Sound_BBB.h"

Grove_Sound_BBB::Grove_Sound_BBB(adcPin pin):ReadStream(0.0) {
	Grove_Sound_Pin = pin;
}

int Grove_Sound_BBB::readOnce() {
	data_stream = (double)analogRead(Grove_Sound_Pin);
	return 1;
}

#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_SOUND == GROVE_SOUND
		Grove_Sound_BBB TL_Sound(SOUND_ANALOG);
	#endif
#endif
