#ifndef TH02_HUMIDITY_RPI_H
#define TH02_HUMIDITY_RPI_H


#include "TL_Config.h"
#include "Sensor_template.h"
#include "RPI_th02.h"

class TH02_Humidity_RPI: public Sensor<double>{
private:
	TH02_dev& TH02Humi;
	int _read();
public:
	TH02_Humidity_RPI();
};

#if TINYLINK_HUMIDITY == TH02
	extern TH02_Humidity_RPI TL_Humidity;
#endif

#endif
