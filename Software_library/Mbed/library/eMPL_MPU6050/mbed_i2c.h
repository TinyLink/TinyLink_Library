
/******************************************************************************
 * $Id: mbed_i2c.h $
 *****************************************************************************/
/**
 *  @defgroup MBED_System_Layer MBED System Layer
 *  @brief  MBED System Layer APIs.
 *          To interface with any platform, eMPL needs access to various
 *          system layer functions.
 *
 *  @{
 *      @file       mbed_i2c.h
 *      @brief      Serial communication functions needed by eMPL to
 *                  communicate to the MPU devices.
 *      @details    This driver assumes that eMPL is with a sub-master clock set
 *                  to 20MHz. The following MBEDs are supported:
 */
#ifndef _MBED_I2C_H_
#define _MBED_I2C_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "i2c_api.h"

void mbed_i2c_init(PinName sda, PinName scl);

/**
 *  @brief	Set up the I2C port and configure the MBED as the master.
 *  @return	0 if successful.
 */
int mbed_i2c_enable(void);
/**
 *  @brief  Disable I2C communication.
 *  This function will disable the I2C hardware and should be called prior to
 *  entering low-power mode.
 *  @return 0 if successful.
 */
int mbed_i2c_disable(void);
/**
 *  @brief      Write to a device register.
 *
 *  @param[in]  slave_addr  Slave address of device.
 *  @param[in]  reg_addr	Slave register to be written to.
 *  @param[in]  length      Number of bytes to write.
 *  @param[out] data        Data to be written to register.
 *
 *  @return     0 if successful.
 */
int mbed_i2c_write(unsigned char slave_addr,
                     unsigned char reg_addr,
                     unsigned char length,
                     unsigned char const *data);
/**
 *  @brief      Read from a device.
 *
 *  @param[in]  slave_addr  Slave address of device.
 *  @param[in]  reg_addr	Slave register to be read from.
 *  @param[in]  length      Number of bytes to read.
 *  @param[out] data        Data from register.
 *
 *  @return     0 if successful.
 */
int mbed_i2c_read(unsigned char slave_addr,
                    unsigned char reg_addr,
                    unsigned char length,
                    unsigned char *data);
                    
int mbed_i2c_clear(PinName sda, PinName scl);
                    
#ifdef __cplusplus
}
#endif

#endif  /* _MBED_I2C_H_ */

/**
 * @}
 */
