#include <cstdio>
#include <cstdlib>
#include "Mbed_Accelerometer_Accelerometer_Mbed.h"

Mbed_Accelerometer_Accelerometer_Mbed::Mbed_Accelerometer_Accelerometer_Mbed(){
        mbed_i2c_clear(MPU6050_SDA, MPU6050_SCL);
	mbed_i2c_init(MPU6050_SDA, MPU6050_SCL);
        if(mpu_init(0)==0)
        //设置所需要的传感器陀螺仪和加速度
        mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL);
        //使能FIFO,采样完成后，自动将数据放入FIFO中
        mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);
        mpu_set_sample_rate(DEFAULT_MPU_HZ);			
        mpu_set_accel_fsr(accel_fsr);
} 


int Mbed_Accelerometer_Accelerometer_Mbed::read(){
       return mpu_get_accel_reg(accel,&sensor_timestamp);
}

int Mbed_Accelerometer_Accelerometer_Mbed::setFSR(unsigned short fsr){
	if(mpu_set_accel_fsr(fsr)){
		return -1;
	}else {
		accel_fsr = fsr;
		return 0;
	}
}
//三个加速度分量均以重力加速度g的倍数为单位
double Mbed_Accelerometer_Accelerometer_Mbed::data_x(){
	return (double) accel[0] * accel_fsr/ 32768;
}
double Mbed_Accelerometer_Accelerometer_Mbed::data_y(){
	return (double) accel[1] * accel_fsr/ 32768;
}
double Mbed_Accelerometer_Accelerometer_Mbed::data_z(){
	return (double) accel[2] * accel_fsr/ 32768;
}

Mbed_Accelerometer_Accelerometer_Mbed TL_Accelerometer;
