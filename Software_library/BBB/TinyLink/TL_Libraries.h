#ifndef TL_LIBRARIES_H
#define TL_LIBRARIES_H

#include "TL_Config.h"

// System library               --------------------------------------------------------------------
#ifdef TINYLINK_SERIAL
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_SERIAL == BBB_SERIAL
			#include "UART.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_TIME
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_TIME == BBB_TIME
			#include "BBB_Time_Time_BBB.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_TIMER
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_TIMER == BBB_TIMER
			#include "BBB_Timer_Timer_BBB.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_STORAGE
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_STORAGE == BBB_SD
			#include "BBB_SD_Storage_BBB.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_FILE
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_FILE == BBB_FILE
			#include "BBB_File_File_BBB.h"
		#endif
	#endif
#endif

// Communication library        --------------------------------------------------------------------
#ifdef TINYLINK_WIRE
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_WIFI == BBB_WIRE
			#include "BBB_WIRE_WIRE_BBB.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_WIFI
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_WIFI == WIFI_USB
			#include "WiFi_USB_WiFi_BBB.h"
		#elif TINYLINK_WIFI == ESP8266
			#include "ESP8266_WiFi_BBB.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_MQTT
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_MQTT == BBB_MQTT
			#include "BBB_MQTT_MQTT_BBB.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_HTTP
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_HTTP == BBB_HTTP
			#include "BBB_HTTP_HTTP_BBB.h"
		#endif
	#endif
#endif

// Sensing library              --------------------------------------------------------------------
#ifdef TINYLINK_TEMPERATURE
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_TEMPERATURE == DHT22
			#include "DHT22_Temperature_BBB.h"
		#elif TINYLINK_TEMPERATURE == DHT11
			#include "DHT11_Temperature_BBB.h"
		#endif
	#endif
#endif


#ifdef TINYLINK_HUMIDITY
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_HUMIDITY == DHT22
			#include "DHT22_Humidity_BBB.h"
	  	#elif TINYLINK_HUMIDITY == DHT11
			#include "DHT11_Humidity_BBB.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_PM25
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_PM25 == SDS018
			#include "SDS018_PM25_BBB.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_PM10
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_PM10 == SDS018
			#include "SDS018_PM10_BBB.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_SOIL_HUMIDITY
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_SOIL_HUMIDITY == SOIL_MOISTURE_ANALOG
			#include "Soil_Moisture_Analog_Soil_Humidity_BBB.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_LIGHT
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_LIGHT == GROVE_LIGHT
			#include "Grove_Light_Light_BBB.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_SOUND
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_SOUND == GROVE_SOUND
			#include "Grove_Sound_Sound_BBB.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_GPS
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_GPS == U_BLOX
			#include "u_blox_GPS_BBB.h"
		#endif
	#endif
#endif

// Control library              --------------------------------------------------------------------
#ifdef TINYLINK_LED
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_LED == BBB_LED
			#include "BBB_LED_LED_BBB.h"
		#elif TINYLINK_LED == OUTLED
			#include "OUTLED_LED_BBB.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_RELAY
	#if PLATFORM == 3 && BOARD == 1005
		#if TINYLINK_RELAY == GROVE_RELAY
			#include "Grove_Relay_Relay_BBB.h"
		#endif
	#endif
#endif

#endif
