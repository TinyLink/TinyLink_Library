#ifndef MBED_BLUETOOTH_BLUETOOTH_MBED_H
#define MBED_BLUETOOTH_BLUETOOTH_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mbed.h"
#include "BLE.h"
#include "GattCallbackParamTypes.h"
#include "TL_Config.h"

//ble instance
extern BLE& ble;
//buffer's max size
static const int TXRX_BUF_LEN = 20;
//buffer restored for message by ble 
extern uint8_t buf[TXRX_BUF_LEN];
//call when ble connected
 void connectionCallback(const Gap::ConnectionCallbackParams_t *params);
//call when ble disconnected
 void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *cbParams);
//call when server ble has something to write to the client ble
 void WrittenHandler(const GattWriteCallbackParams *Handler);
//init the gattservice
static const uint16_t uart_base_uuid = 0xA000 ;//The UUID of the Nordic UART Service
static const uint16_t tx_uuid =  0xA002;//The UUID of the TX Characteristic
static const uint16_t rx_uuid = 0xA001;//The UUID of the RX Characteristic
static uint8_t txValue[TXRX_BUF_LEN] = { 0, };//data 's payload from server ble
static uint8_t rxValue[TXRX_BUF_LEN] = { 0, };//data's payload from client ble
static WriteOnlyArrayGattCharacteristic<uint8_t, sizeof(txValue)>  txCharacteristic(tx_uuid, txValue);																						
static ReadOnlyArrayGattCharacteristic<uint8_t, sizeof(rxValue)> rxCharacteristic(rx_uuid, rxValue);
static GattCharacteristic *uartChars[] = { &txCharacteristic ,&rxCharacteristic };
static GattService  uartService(uart_base_uuid, uartChars, sizeof(uartChars) / sizeof(GattCharacteristic *));

class Mbed_Bluetooth_Bluetooth_T {
public:
	/***********************************************************************
	class constructor 
	***********************************************************************/
	Mbed_Bluetooth_Bluetooth_T() {
	}
	/***********************************************************************
	init the tinyble to passive scanning
	***********************************************************************/
	int init(char *DEVICE_NAME) {
		ble.init();
		/* Set device name characteristic data */
		ble.gap().setDeviceName((const uint8_t *)DEVICE_NAME);
		/* ble's reaction when it is disconnected  */
		ble.gap().onDisconnection(disconnectionCallback);
		/* ble's reaction when it is connected  */
		ble.gap().onConnection(connectionCallback);
		/* ble's reaction when server bluetooth want to send data */
		ble.gattServer().onDataWritten(WrittenHandler);
		/*set the Advertising Type to undirected,so that every device should see the advertisement */
		ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
		/* set the payload in order to advertising */
		ble.gap().clearAdvertisingPayload();/* reset and clear Advertising payload  */
		ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);/* Sacrifice 3B of 31B to Advertising Flags */
		ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::SHORTENED_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME) - 1);/* Optional: Add name to device */
		/* add some service to the server bluetooth */
		ble.addService(uartService);
		/* Set advertising interval. Longer interval == longer battery life *//* 100ms */
		ble.gap().setAdvertisingInterval(160);
		/* Start advertising */
		ble.gap().startAdvertising();
		/* wait for connection event */
		ble.waitForEvent();
		return 0;
	}
	/***********************************************************************
	tinyble send data
	***********************************************************************/
	int send(char* data) {
		BLE::Instance(BLE::DEFAULT_INSTANCE).gattServer().write(rxCharacteristic.getValueHandle(), (uint8_t *)data, strlen(data));
		return 0;
	}
	/***********************************************************************
	tinyble receive data
	***********************************************************************/
	int recv(char* data) {
		//wait for the data from the server ble
		while(!strcmp((char*)buf,"")) {
			ble.waitForEvent();
		}
		//copy the data sent from server ble
		int i = 0;
		for (i = 0; buf[i] != '\0'; i++) {
			data[i] = buf[i];
		}
		data[i] = '\0';
		//clear the buffer to ready the next operation
		for (int index = 0; index < TXRX_BUF_LEN; index++)
			buf[index] = '\0';
		//return to indicate recv succeed
		return 0;
	}
};
typedef Mbed_Bluetooth_Bluetooth_T Mbed_Bluetooth_Bluetooth;
extern Mbed_Bluetooth_Bluetooth  TL_Bluetooth;

#endif