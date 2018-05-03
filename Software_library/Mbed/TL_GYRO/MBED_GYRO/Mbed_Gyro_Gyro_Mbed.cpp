#include "Mbed_Gyro_Gyro_Mbed.h"

Mbed_Gyro_Gyro_Mbed::Mbed_Gyro_Gyro_Mbed(){   
	mbed_i2c_clear(MPU6050_SDA, MPU6050_SCL);
	mbed_i2c_init(MPU6050_SDA, MPU6050_SCL);
	mpu_init(0); 
	/* Get/set hardware configuration. Start gyro. */
	mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL);
	/* Push gyro data into the FIFO. */
	mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);
	mpu_set_sample_rate(DEFAULT_MPU_HZ);  
	/* Read back configuration in case it was set improperly. */
	mpu_get_sample_rate(&gyro_rate);
	mpu_get_gyro_fsr(&gyro_fsr);
}

int Mbed_Gyro_Gyro_Mbed::read(){
	return mpu_get_gyro_reg(gyro, &sensor_timestamp);
}

int Mbed_Gyro_Gyro_Mbed::setFSR(unsigned short fsr){
	if(mpu_set_gyro_fsr(fsr)){
	 return -1;
	}else{
	 gyro_fsr = fsr;
	 return 0;
	}
}

double Mbed_Gyro_Gyro_Mbed::data_x(){
	return (double)gyro[0]*gyro_fsr/32768;
}
double Mbed_Gyro_Gyro_Mbed::data_y(){
	return (double)gyro[1]*gyro_fsr/32768;
}
double Mbed_Gyro_Gyro_Mbed::data_z(){
	return (double)gyro[2]*gyro_fsr/32768;
}

Mbed_Gyro_Gyro_Mbed TL_Gyro;   
