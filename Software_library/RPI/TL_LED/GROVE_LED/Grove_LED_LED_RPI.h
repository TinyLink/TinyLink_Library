#ifndef GROVE_LED_LED_RPI_H
#define GROVE_LED_LED_RPI_H

#include "TL_Config.h"

namespace tinylink {
	class Grove_LED_LED_RPI {
	private:
		int stateSig;
	public:
		Grove_LED_LED_RPI();
		void turnOn(void);
		void turnOff(void);
		void toggle(void);
		const int state(void);
	};
}

extern tinylink::Grove_LED_LED_RPI TL_LED;

#endif
