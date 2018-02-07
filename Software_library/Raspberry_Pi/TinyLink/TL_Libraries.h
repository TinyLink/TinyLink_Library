#ifndef TL_LIBRARIES_H
#define TL_LIBRARIES_H

#include "TL_Config.h"

#ifdef SERIAL
	#if PLATFORM == 4 && BOARD == 1003
		#if SERIAL == RPI_SERIAL
			#include "SERIAL_RPI.h"
		#endif
	#endif
#endif

#ifdef TIME
	#if PLATFORM == 4 && BOARD == 1003
		#if TIME == RPI_TIME
			#include "RPI_Time_Time_RPI.h"
		#endif
	#endif
#endif

#ifdef TIMER
	#if PLATFORM == 4 && BOARD == 1003
		#if TIMER == RPI_TIMER
			#include "RPI_Timer_Timer_RPI.h"
		#endif
	#endif
#endif

// gas sesnor
#ifdef PM25
	#if PLATFORM == 4 && BOARD == 1003
		#if PM25 == SDS018
			#include "SDS018_PM25_RPI.h"
		#endif
	#endif
#endif

#ifdef TEMPERATURE
	#if PLATFORM == 4 && BOARD == 1003
		#if TEMPERATURE == DHT11
			#include "DHT11_Temperature_RPI.h"
		#endif
	#endif
#endif

#ifdef HUMIDITY
	#if PLATFORM == 4 && BOARD == 1003
		#if HUMIDITY == DHT11
			#include "DHT11_Humidity_RPI.h"
		#endif
	#endif
#endif

#ifdef SOIL_HUMIDITY
	#if PLATFORM == 4 && BOARD == 1003
		#if SOIL_HUMIDITY == SOIL_MOISTURE_ANALOG
			#include "Soil_Moisture_Analog_Soil_Humidity_RPI.h"
		#endif
	#endif
#endif

#ifdef GPS
	#if PLATFORM == 4 && BOARD == 1003
		#if GPS == U_BLOX
			#include "u_blox_GPS_RPI.h"
		#endif
	#endif
#endif


#ifdef WIRE
#endif

#ifdef WIFI
	#if PLATFORM == 4 && BOARD == 1003
		#if WIFI == WIFI_USB
			#include "WiFi_USB_WiFi_RPI.h"
		#endif
	#endif
#endif

#ifdef STORAGE
	#if PLATFORM == 4 && BOARD == 1003
		#if STORAGE == RPI_SD
			#include "RPI_SD_Storage_RPI.h"
		#endif
	#endif
#endif

#ifdef LED
	#if PLATFORM == 4 && BOARD == 1003
		#if LED == OUTLED
			#include "OUTLED_LED_RPI.h"
		#endif
	#endif
#endif

#ifdef LIGHT
	#if PLATFORM == 4 && BOARD == 1003
		#if LIGHT == GROVE_LIGHT
			#include "Grove_Light_Light_RPI.h"
		#endif
	#endif
#endif

#ifdef RELAY
	#if PLATFORM == 4 && BOARD == 1003
		#if RELAY == GROVE_RELAY
			#include "Grove_Relay_Relay_RPI.h"
		#endif
	#endif
#endif

#ifdef VOICE
	#if PLATFORM == 4 && BOARD == 1003
		#if VOICE == VOICE_USB
			#include "Voice_USB_Voice_RPI.h"
		#endif
	#endif
#endif

#ifdef DISPLAY
	#if PLATFORM == 4 && BOARD == 1003
		#if DISPLAY == GROVE_LCD_RGB
			#include "Grove_LCD_RGB_Display_RPI.h"
		#endif
	#endif
#endif

#endif
