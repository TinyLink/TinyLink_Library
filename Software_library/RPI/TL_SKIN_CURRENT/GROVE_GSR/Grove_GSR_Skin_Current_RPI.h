#ifndef GROVE_GSR_SKIN_CURRENT_RPI_H
#define GROVE_GSR_SKIN_CURRENT_RPI_H

#include "grovepi.h"
#include "TL_Config.h"
#include "Sensor_template.h"

namespace tinylink
{
	class Grove_GSR_Skin_Current_RPI:public Sensor<int> {
	private:
		int _pin;
	protected:
		int _read();
	public:
		Grove_GSR_Skin_Current_RPI(int pin);
	};
}
#if TINYLINK_SKIN_CURRENT == GROVE_GSR
	extern tinylink::Grove_GSR_Skin_Current_RPI TL_Skin_Current;
#endif

#endif
