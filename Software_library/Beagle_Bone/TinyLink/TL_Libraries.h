#ifndef TL_LIBRARIES_H
#define TL_LIBRARIES_H

#include "TL_Config.h"

#ifdef SERIAL
	#if PLATFORM == 3 && BOARD == 1005
		#if SERIAL == BBB_SERIAL
			#include "UART.h"
		#endif
	#endif
#endif

#ifdef TIME
	#if PLATFORM == 3 && BOARD == 1005
		#if TIME == BBB_TIME
			#include "BBB_Time_Time_BBB.h"
		#endif
	#endif
#endif

#ifdef TIMER
	#if PLATFORM == 3 && BOARD == 1005
		#if TIMER == BBB_TIMER
			#include "BBB_Timer_Timer_BBB.h"
		#endif
	#endif
#endif

#ifdef TEMPERATURE
	#if PLATFORM == 3 && BOARD == 1005
		#if TEMPERATURE == DHT22
			#include "DHT22_Temperature_BBB.h"
		#elif TEMPERATURE == DHT11
			#include "DHT11_Temperature_BBB.h"
		#endif
	#endif
#endif

#ifdef HUMIDITY
	#if PLATFORM == 3 && BOARD == 1005
		#if HUMIDITY == DHT22
			#include "DHT22_Humidity_BBB.h"
	  	#elif HUMIDITY == DHT11
			#include "DHT11_Humidity_BBB.h"
		#endif
	#endif
#endif

#ifdef PM25
	#if PLATFORM == 3 && BOARD == 1005
		#if PM25 == SDS018
			#include "SDS018_PM25_BBB.h"
		#endif
	#endif
#endif

#ifdef PM10
	#if PLATFORM == 3 && BOARD == 1005
		#if PM10 == SDS018
			#include "SDS018_PM10_BBB.h"
		#endif
	#endif
#endif

#ifdef SOIL_HUMIDITY
	#if PLATFORM == 3 && BOARD == 1005
		#if SOIL_HUMIDITY == SOIL_MOISTURE_ANALOG
			#include "Soil_Moisture_Analog_Soil_Humidity_BBB.h"
		#endif
	#endif
#endif

#ifdef LIGHT
	#if PLATFORM == 3 && BOARD == 1005
		#if LIGHT == GROVE_LIGHT
			#include "Grove_Light_Light_BBB.h"
		#endif
	#endif
#endif

#ifdef SOUND
	#if PLATFORM == 3 && BOARD == 1005
		#if SOUND == GROVE_SOUND
			#include "Grove_Sound_Sound_BBB.h"
		#endif
	#endif
#endif

#ifdef GPS
	#if PLATFORM == 3 && BOARD == 1005
		#if GPS == U_BLOX
			#include "u_blox_GPS_BBB.h"
		#endif
	#endif
#endif

#ifdef WIRE
	#if PLATFORM == 3 && BOARD == 1005
		#if WIFI == BBB_WIRE
			#include "BBB_WIRE_WIRE_BBB.h"
		#endif
	#endif
#endif

#ifdef WIFI
	#if PLATFORM == 3 && BOARD == 1005
		#if WIFI == WIFI_USB
			#include "WiFi_USB_WiFi_BBB.h"
		#endif
		#if WIFI == ESP8266
			#include "ESP8266_WiFi_BBB.h"
		#endif
	#endif
#endif

#ifdef STORAGE
	#if PLATFORM == 3 && BOARD == 1005
		#if STORAGE == BBB_SD
			#include "BBB_SD_Storage_BBB.h"
		#endif
	#endif
#endif


#ifdef LED
	#if PLATFORM == 3 && BOARD == 1005
		#if LED == BBB_LED
			#include "BBB_LED_LED_BBB.h"
		#elif LED == OUTLED
			#include "OUTLED_LED_BBB.h"
		#endif
	#endif
#endif

#endif
