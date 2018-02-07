#ifndef GROVE_RELAY_RELAY_BBB_H
#define GROVE_RELAY_RELAY_BBB_H

namespace tinylink {
	class Grove_Relay_RPI {

	private:
		int _pin;

	protected:
		
	public:
		Grove_Relay_RPI(int pin);
		void turnOn(void);
                void turnOff(void);
	
	};
}

extern tinylink::Grove_Relay_RPI TL_Relay;

#endif 
