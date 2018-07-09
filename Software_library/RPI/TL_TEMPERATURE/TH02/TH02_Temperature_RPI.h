#ifndef TH02_TEMPERATURE_RPI_H
#define TH02_TEMPERATURE_RPI_H

#include "TL_Config.h"
#include "Sensor_template.h"
#include "RPI_th02.h"

class TH02_Temperature_RPI: public Sensor<double>{
public:
	TH02_Temperature_RPI();

private:
	TH02_dev& TH02Temp;
	int _read();
};

#if TINYLINK_TEMPERATURE == TH02
	extern TH02_Temperature_RPI TL_Temperature;
#endif
#endif
