#ifndef TL_LIBRARIES_H
#define TL_LIBRARIES_H

#include "TL_Config.h"

#ifdef TINYLINK_SERIAL
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_SERIAL == RPI_SERIAL
			#include "UART.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_TIME
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_TIME == RPI_TIME
			#include "RPI_Time_Time_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_TIMER
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_TIMER == RPI_TIMER
			#include "RPI_Timer_Timer_RPI.h"
		#endif
	#endif
#endif

// gas sesnor
#ifdef TINYLINK_PM25
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_PM25 == SDS018
			#include "SDS018_PM25_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_TEMPERATURE
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_TEMPERATURE == DHT11
			#include "DHT11_Temperature_RPI.h"
		#elif TINYLINK_TEMPERATURE == DHT22
			#include "DHT22_Temperature_RPI.h"
		#elif TINYLINK_TEMPERATURE == GROVE_TEMPERATURE
			#include "Grove_Temperature_Temperature_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_HUMIDITY
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_HUMIDITY == DHT11
			#include "DHT11_Humidity_RPI.h"
		#elif TINYLINK_HUMIDITY == DHT22
			#include "DHT22_Humidity_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_SOIL_HUMIDITY
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_SOIL_HUMIDITY == SOIL_MOISTURE_ANALOG
			#include "Soil_Moisture_Analog_Soil_Humidity_RPI.h"
		#elif TINYLINK_SOIL_HUMIDITY == GROVE_MOISTURE
			#include "Grove_Moisture_Soil_Humidity_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_HCHO
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_HCHO == GROVE_HCHO
			#include "Grove_HCHO_HCHO_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_GPS
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_GPS == U_BLOX
			#include "u_blox_GPS_RPI.h"
		#endif
	#endif
#endif


#ifdef TINYLINK_WIRE
#endif

#ifdef TINYLINK_WIFI
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_WIFI == WIFI_USB
			#include "WiFi_USB_WiFi_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_TCP
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_TCP == RPI_TCP
			#include "RPI_TCP_TCP_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_MQTT
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_MQTT == RPI_MQTT
			#include "RPI_MQTT_MQTT_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_HTTP
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_HTTP == RPI_HTTP
			#include "RPI_HTTP_HTTP_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_STORAGE
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_STORAGE == RPI_SD
			#include "RPI_SD_Storage_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_FILE
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_FILE == RPI_FILE
			#include "RPI_File_File_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_LED
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_LED == GROVE_LED
			#include "Grove_LED_LED_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_LIGHT
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_LIGHT == GROVE_LIGHT
			#include "Grove_Light_Light_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_RELAY
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_RELAY == GROVE_RELAY
			#include "Grove_Relay_Relay_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_VOICE
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_VOICE == VOICE_USB
			#include "Voice_USB_Voice_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_DISPLAY
	#if TINYLINK_DISPLAY == GROVE_LCD_RGB
		#include "Grove_LCD_RGB_Display_RPI.h"
	#endif
#endif

#ifdef TINYLINK_BULB
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_BULB == GROVE_CHAINABLE_RGB_BULB
			#include "Grove_Chainable_RGB_Bulb_Bulb_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_CAR
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_CAR == GROVE_CAR
			#include "Grove_Car_Car_RPI.h"
		#endif
	#endif
#endif

#ifdef TINYLINK_MOTOR
	#if PLATFORM == 4 && BOARD == 1003
		#if TINYLINK_MOTOR == GROVE_DC_MOTOR
			#include "Grove_DC_Motor_Motor_RPI.h"
		#endif
	#endif
#endif

#endif
