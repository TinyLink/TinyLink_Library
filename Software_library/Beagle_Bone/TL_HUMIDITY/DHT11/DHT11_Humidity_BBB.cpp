#include "DHT11_Humidity_BBB.h"
//#define DEBUG 108
//P8
static DHT11_HUMIDITY_PIN P8_3 = {1, 6};
static DHT11_HUMIDITY_PIN P8_4 = {1, 7};
static DHT11_HUMIDITY_PIN P8_5 = {1, 2};
static DHT11_HUMIDITY_PIN P8_6 = {1, 3};
static DHT11_HUMIDITY_PIN P8_7 = {2, 2};
static DHT11_HUMIDITY_PIN P8_8 = {2, 3};
static DHT11_HUMIDITY_PIN P8_9 = {2, 5};
static DHT11_HUMIDITY_PIN P8_10 = {2, 4};

static DHT11_HUMIDITY_PIN P8_11 = {1, 13};
static DHT11_HUMIDITY_PIN P8_12 = {1, 12};
static DHT11_HUMIDITY_PIN P8_13 = {0, 23};
static DHT11_HUMIDITY_PIN P8_14 = {0, 26};
static DHT11_HUMIDITY_PIN P8_15 = {1, 15};
static DHT11_HUMIDITY_PIN P8_16 = {1, 14};
static DHT11_HUMIDITY_PIN P8_17 = {0, 27};
static DHT11_HUMIDITY_PIN P8_18 = {2, 1};
static DHT11_HUMIDITY_PIN P8_19 = {0, 22};
static DHT11_HUMIDITY_PIN P8_20 = {1, 31};

static DHT11_HUMIDITY_PIN P8_21 = {1, 30};
static DHT11_HUMIDITY_PIN P8_22 = {1, 5};
static DHT11_HUMIDITY_PIN P8_23 = {1, 4};
static DHT11_HUMIDITY_PIN P8_24 = {1, 1};
static DHT11_HUMIDITY_PIN P8_25 = {1, 0};
static DHT11_HUMIDITY_PIN P8_26 = {1, 29};
static DHT11_HUMIDITY_PIN P8_27 = {2, 22};
static DHT11_HUMIDITY_PIN P8_28 = {2, 24};
static DHT11_HUMIDITY_PIN P8_29 = {2, 23};
static DHT11_HUMIDITY_PIN P8_30 = {2, 25};


static DHT11_HUMIDITY_PIN P8_31 = {0, 10};
static DHT11_HUMIDITY_PIN P8_32 = {0, 11};
static DHT11_HUMIDITY_PIN P8_33 = {0, 9};
static DHT11_HUMIDITY_PIN P8_34 = {2, 17};
static DHT11_HUMIDITY_PIN P8_35 = {0, 8};
static DHT11_HUMIDITY_PIN P8_36 = {2, 16};
static DHT11_HUMIDITY_PIN P8_37 = {2, 14};
static DHT11_HUMIDITY_PIN P8_38 = {2, 15};
static DHT11_HUMIDITY_PIN P8_39 = {2, 12};
static DHT11_HUMIDITY_PIN P8_40 = {2, 13};

static DHT11_HUMIDITY_PIN P8_41 = {2, 10};
static DHT11_HUMIDITY_PIN P8_42 = {1, 11};
static DHT11_HUMIDITY_PIN P8_43 = {2, 8};
static DHT11_HUMIDITY_PIN P8_44 = {2, 9};
static DHT11_HUMIDITY_PIN P8_45 = {2, 6};
static DHT11_HUMIDITY_PIN P8_46 = {2, 7};

//P9
static DHT11_HUMIDITY_PIN P9_11 = {0, 30};
static DHT11_HUMIDITY_PIN P9_12 = {1, 28};
static DHT11_HUMIDITY_PIN P9_13 = {0, 31};
static DHT11_HUMIDITY_PIN P9_14 = {1, 18};
static DHT11_HUMIDITY_PIN P9_15 = {1, 16};
static DHT11_HUMIDITY_PIN P9_16 = {1, 19};
static DHT11_HUMIDITY_PIN P9_17 = {0, 5};
static DHT11_HUMIDITY_PIN P9_18 = {0, 4};
static DHT11_HUMIDITY_PIN P9_19 = {0, 13};
static DHT11_HUMIDITY_PIN P9_20 = {0, 12};

static DHT11_HUMIDITY_PIN P9_21 = {0, 3};
static DHT11_HUMIDITY_PIN P9_22 = {0, 2};
static DHT11_HUMIDITY_PIN P9_23 = {1, 17};
static DHT11_HUMIDITY_PIN P9_24 = {0, 15};
static DHT11_HUMIDITY_PIN P9_25 = {3, 21};
static DHT11_HUMIDITY_PIN P9_26 = {0, 14};
static DHT11_HUMIDITY_PIN P9_27 = {3, 19};
static DHT11_HUMIDITY_PIN P9_28 = {3, 17};
static DHT11_HUMIDITY_PIN P9_29 = {3, 15};
static DHT11_HUMIDITY_PIN P9_30 = {3, 16};

static DHT11_HUMIDITY_PIN P9_31 = {3, 14};

static DHT11_HUMIDITY_PIN P9_41 = {0, 20};
static DHT11_HUMIDITY_PIN P9_42 = {0, 7};
//static DHT11_HUMIDITY_PIN P9_42 = {3, 20};

DHT11_HUMIDITY::DHT11_HUMIDITY(int u_type):Sensor(0.0), tem(0.0), type(u_type){
	#if HUMIDITY == DHT11
	gpio_base = HUMIDITY_DIGITAL_OUTPUT.base;
	gpio_num = HUMIDITY_DIGITAL_OUTPUT.num;
	#endif
}


int DHT11_HUMIDITY::_read(){
	float temp_hum = 0, temp_tem = 0;
	int x = bbb_dht_read(type, gpio_base, gpio_num, &temp_hum, &temp_tem);
	#ifdef DEBUG
	cout << (x == 0 ? "Success ":"Error ") << x << " " << "Tempperature: " << temp_tem << " Humidity: " << temp_hum <<"%"<<endl;
	#endif
	if (!x) {
		tem = temp_tem, _data = temp_hum;	
	}
	return x;
}



#if PLATFORM == 3 && BOARD == 1005
#if HUMIDITY == DHT11
DHT11_HUMIDITY TL_Humidity(11);
#endif
#endif
