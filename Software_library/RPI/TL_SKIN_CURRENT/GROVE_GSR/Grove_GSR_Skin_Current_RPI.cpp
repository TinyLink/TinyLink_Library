#include "Grove_GSR_Skin_Current_RPI.h"

namespace tinylink{
	Grove_GSR_Skin_Current_RPI::Grove_GSR_Skin_Current_RPI(): Sensor(0) {
		if (init_dev() == -1) exit(1);	
	}

	int Grove_GSR_Skin_Current_RPI::_read(){
		 _data = analogRead(SKIN_CURRENT_ANALOG);
		 return 0;
	}
}

#if TINYLINK_SKIN_CURRENT == GROVE_GSR
	tinylink::Grove_GSR_Skin_Current_RPI TL_Skin_Current;
#endif
