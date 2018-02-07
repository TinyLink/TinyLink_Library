#include <stdio.h>
#include <stdlib.h>
#include "Mbed_Bluetooth_Bluetooth_Mbed.h"

BLE& ble = BLE::Instance(BLE::DEFAULT_INSTANCE);
uint8_t buf[TXRX_BUF_LEN] = {};
void connectionCallback(const Gap::ConnectionCallbackParams_t *params) {
}

void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *cbParams) {
	ble.gap().startAdvertising();
}

void WrittenHandler(const GattWriteCallbackParams *Handler) {
	uint16_t bytesRead;//
	//clear the buf
	for (int index = 0; index < TXRX_BUF_LEN; index++)
		buf[index] = '\0';
	//get the message and put it into buf
	ble.gattServer().read(Handler->handle, buf, &bytesRead);
	memset(txValue, 0, TXRX_BUF_LEN);
	memcpy(txValue, buf, TXRX_BUF_LEN);
}



 Mbed_Bluetooth_Bluetooth TL_Bluetooth;