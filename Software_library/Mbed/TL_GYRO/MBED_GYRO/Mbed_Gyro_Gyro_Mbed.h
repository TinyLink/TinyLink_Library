#ifndef MBED_GYRO_GYRO_MBED_H
#define MBED_GYRO_GYRO_MBED_H
 
#include "mbed.h"
#include "mbed_i2c.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "nrf51.h"
#include "nrf51_bitfields.h"
 

#include "DFUService.h"

 
#define MPU6050_SDA p12
#define MPU6050_SCL p13
 
/* Starting sampling rate. */
#define DEFAULT_MPU_HZ  (100)

class Mbed_Gyro_Gyro_Mbed{
private:
	unsigned long sensor_timestamp;
	short gyro[3];
	unsigned short gyro_fsr=1000, gyro_rate;
	/*setDPS full-scale:250 or 500 or 1000 or 2000 Degree Per Second*/
	int setFSR(unsigned short fsr);
public:
	/*init GYRO*/
	Mbed_Gyro_Gyro_Mbed();
	/*read GYRO X,Y,Z raw data if success return 0, none data return -1, and set data cache 0*/
	int read();
	double data_x();
	double data_y();
	double data_z();
}; 

extern Mbed_Gyro_Gyro_Mbed TL_Gyro;

#endif

