#ifndef DHT11_TEMPERATURE_BBB_H
#define DHT11_TEMPERATURE_BBB_H

#include <stdio.h>
#include <errno.h>
#include <sched.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <iostream>
#include <pthread.h>
#include "Sensor_template.h"

#include "TL_Config.h"
#include "bbb_dht_read.h"
#include "bbb_mmio.h"
#include "common_dht_read.h"

using namespace std;




typedef struct tag_DHT11_TEMPERATURE_PIN
{
	int base;
	int num;
}DHT11_TEMPERATURE_PIN;


class DHT11_TEMPERATURE : public Sensor<double>
{
private:
	double hum;
	int type, gpio_base, gpio_num;

protected:
	int _read();

public:
	DHT11_TEMPERATURE(int u_type);
};

#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_TEMPERATURE == DHT11
		extern DHT11_TEMPERATURE TL_Temperature;
	#endif
#endif

#endif
