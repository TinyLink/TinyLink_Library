#ifndef TL_LIBRARIES_H
#define TL_LIBRARIES_H

#include "TL_Config.h"

// System library		--------------------------------------------------------------------
#ifdef TINYLINK_SERIAL
	#if TINYLINK_SERIAL == ONE_SERIAL
		#include "One_Serial_Serial_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_TIME
	#if TINYLINK_TIME == ONE_TIME
		#include "One_Time_Time_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_TIMER
	#if TINYLINK_TIMER == ONE_TIMER
		#include "One_Timer_Timer_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_STORAGE
	#if TINYLINK_STORAGE == ONE_SD
		#include "One_SD_Storage_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_FILE
	#if TINYLINK_FILE == ONE_FILE
		#include "One_File_File_LinkIt_One.h"
	#endif
#endif

// Commuincation library	--------------------------------------------------------------------
#ifdef TINYLINK_BLUETOOTH
	#if TINYLINK_BLUETOOTH == ONE_BLUETOOTH
		#include "One_Bluetooth_Bluetooth_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_WIFI
	#if TINYLINK_WIFI == ONE_WIFI
		#include "One_WiFi_WiFi_LinkIt_One.h"
	#endif
#endif
/* MQTT is currently not supported by LinkIt One
#ifdef TINYLINK_MQTT
	#if TINYLINK_MQTT == ONE_MQTT
		#include "One_MQTT_MQTT_LinkIt_One.h"
	#endif
#endif
*/
#ifdef TINYLINK_HTTP
	#if TINYLINK_HTTP == ONE_HTTP
		#include "One_HTTP_HTTP_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_GPRS
	// not available
#endif

// Sensing library		--------------------------------------------------------------------
#ifdef TINYLINK_TEMPERATURE
	#if TINYLINK_TEMPERATURE == DHT11
		#include "DHT11_Temperature_LinkIt_One.h"
	#elif TINYLINK_TEMPERATURE == DHT22
		#include "DHT22_Temperature_LinkIt_One.h"
	#elif TINYLINK_TEMPERATURE == GROVE_TEMPERATURE
		#include "Grove_Temperature_Temperature_LinkIt_One.h"
	#elif TINYLINK_TEMPERATURE == TH02
		#include "TH02_Temperature_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_HUMIDITY
	#if TINYLINK_HUMIDITY == DHT11
		#include "DHT11_Humidity_LinkIt_One.h"
	#elif TINYLINK_HUMIDITY == DHT22
		#include "DHT22_Humidity_LinkIt_One.h"
	#elif TINYLINK_HUMIDITY == TH02
		#include "TH02_Humidity_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_PM25
	#if TINYLINK_PM25 == SDS018
		#include "SDS018_PM25_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_LIGHT
	#if TINYLINK_LIGHT == GROVE_LIGHT
		#include "Grove_Light_Light_LinkIt_One.h"
	#elif TINYLINK_LIGHT == GROVE_DIGITAL_LIGHT
		#include "Grove_Digital_Light_Light_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_SOIL_HUMIDITY
	#if TINYLINK_SOIL_HUMIDITY == SOIL_MOISTURE_ANALOG
		#include "Soil_Moisture_Analog_Soil_Humidity_LinkIt_One.h"
	#elif TINYLINK_SOIL_HUMIDITY == GROVE_MOISTURE
		#include "Grove_Moisture_Soil_Humidity_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_SOUND
	// not available
#endif

#ifdef TINYLINK_ACCELEROMETER
	#if TINYLINK_ACCELEROMETER == GROVE_IMU9
		#include "Grove_IMU9_Accelerometer_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_GYRO
	#if TINYLINK_GYRO == GROVE_IMU9
		#include "Grove_IMU9_Gyro_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_MAGNET
	#if TINYLINK_MAGNET == GROVE_IMU9
		#include "Grove_IMU9_Magnet_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_GPS
	#if TINYLINK_GPS == ONE_GPS
  		#include "One_GPS_GPS_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_HEART_RATE
	#if TINYLINK_HEART_RATE == GROVE_FINGER_CLIP_HEART_RATE
		#include "Grove_Finger_Clip_Heart_Rate_Heart_Rate_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_SKIN_CURRENT
	#if TINYLINK_SKIN_CURRENT == GROVE_GSR
		#include "Grove_GSR_Skin_Current_LinkIt_One.h"
	#endif
#endif

// Control library		--------------------------------------------------------------------
#ifdef TINYLINK_LED
	#if TINYLINK_LED == ONE_LED
		#include "One_LED_LED_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_MOTOR
	#if TINYLINK_MOTOR == GROVE_DC_MOTOR
		#include "Grove_DC_Motor_Motor_LinkIt_One.h"
	#endif
#endif

#ifdef TINYLINK_DISPLAY
	#if TINYLINK_DISPLAY == GROVE_LCD_RGB
		#include "Grove_LCD_RGB_Display_LinkIt_One.h"
	#endif
#endif

#endif
