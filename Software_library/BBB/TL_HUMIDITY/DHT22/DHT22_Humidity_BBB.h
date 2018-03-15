#ifndef DHT22_HUMIDITY_BBB_H
#define DHT22_HUMIDITY_BBB_H

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




typedef struct tag_DHT22_HUMIDITY_PIN
{
	int base;
	int num;
}DHT22_HUMIDITY_PIN;


class DHT22_HUMIDITY : public Sensor<double>
{
private:
	double tem;
	int type, gpio_base, gpio_num;
protected:
	int _read();
public:
	DHT22_HUMIDITY(int u_type);
};



#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_HUMIDITY == DHT22
		extern DHT22_HUMIDITY TL_Humidity;
	#endif
#endif

#endif
