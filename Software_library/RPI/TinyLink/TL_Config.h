#ifndef TL_CONFIG_H
#define TL_CONFIG_H

#include "TL_Device_ID.h"

#define PLATFORM 4
#define BOARD 1003
// Serial
#define TINYLINK_SERIAL RPI_SERIAL
// Time
#define TINYLINK_TIME RPI_TIME
// Timer
#define TINYLINK_TIMER RPI_TIMER
// LED
#define TINYLINK_LED GROVE_LED
#define LED_DIGITAL_INPUT 8
#define LED_DIGITAL_OUTPUT 7
// Light
#define TINYLINK_LIGHT GROVE_LIGHT
#define LIGHT_ANALOG A0
// Temperature
#define TINYLINK_TEMPERATURE DHT11
#define TEMPERATURE_DIGITAL_INPUT 5
#define TEMPERATURE_DIGITAL_OUTPUT 4
/*
#define TINYLINK_TEMPERATURE DHT22
#define TEMPERATURE_DIGITAL_INPUT 6
#define TEMPERATURE_DIGITAL_OUTPUT 5
*/
/*
#define TINYLINK_TEMPERATURE GROVE_TEMPERATURE
#define TEMPERATURE_ANALOG A2
*/
// Humidity
#define TINYLINK_HUMIDITY DHT11
#define HUMIDITY_DIGITAL_INPUT 5
#define HUMIDITY_DIGITAL_OUTPUT 4
#define TINYLINK_HCHO GROVE_HCHO
#define HCHO_ANALOG A0
/*
#define TINYLINK_HUMIDITY DHT22
#define HUMIDITY_DIGITAL_INPUT 6
#define HUMIDITY_DIGITAL_OUTPUT 5
*/
// Storage
#define TINYLINK_STORAGE RPI_SD
// Soil_humidity
/*
#define TINYLINK_SOIL_HUMIDITY SOIL_MOISTURE_ANALOG
#define SOIL_HUMIDITY_ANALOG A2
*/
#define TINYLINK_SOIL_HUMIDITY GROVE_MOISTURE
#define SOIL_HUMIDITY_ANALOG A2
// GPS
#define TINYLINK_GPS U_BLOX
#define GPS_UART_RX 10
#define GPS_UART_TX 8
// PM25
#define TINYLINK_PM25 SDS018
#define PM25_UART_RX 10
#define PM25_UART_TX 8
// WiFi
#define TINYLINK_WIFI WIFI_USB
// TCP
#define TINYLINK_TCP RPI_TCP
// Http
#define TINYLINK_HTTP RPI_HTTP
// Mqtt
#define TINYLINK_MQTT RPI_MQTT
// Relay
#define TINYLINK_RELAY GROVE_RELAY
#define RELAY_DIGITAL_INPUT 3
#define RELAY_DIGITAL_OUTPUT 2
// Voice
#define TINYLINK_VOICE VOICE_USB
// Display
#define TINYLINK_DISPLAY GROVE_LCD_RGB
// BUlb
#define TINYLINK_BULB GROVE_CHAINABLE_RGB_BULB
#define BULB_DIGITAL_INPUT 4
#define BULB_DIGITAL_OUTPUT 3
// Car
#define TINYLINK_CAR GROVE_CAR

#endif
