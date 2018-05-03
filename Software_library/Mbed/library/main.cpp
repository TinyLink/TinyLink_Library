#include "mbed.h"
#include "mbed_i2c.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "nrf51.h"
#include "nrf51_bitfields.h"

#include "BLE.h"
#include "DFUService.h"
#include "UARTService.h"

#include "TL_Libraries.h"

extern void setup();
extern void loop();

int main(void){
	setup();
	while(true){
		loop();
	}
	return 0;
}
