#include "Grove_Car_Car_RPI.h"
#include "math.h"
#include "TL_Config.h"
using tinylink::Grove_Car_Car_RPI;

namespace tinylink{
Grove_Car_Car_RPI::Grove_Car_Car_RPI()
{
	MOTOR_LEFT_ADDR = 0x65;  //set i2c slave address on raspberry i2c bus
	MOTOR_RIGHT_ADDR = 0x60;	
	this->connect(); //try connect.
}

void Grove_Car_Car_RPI::connect()
{
        this->DEVICE_FILE = initDevice(0x60);// set new i2c_client on raspberry, get file number;
}

void Grove_Car_Car_RPI::moveForward(){
	this->Left_Motor(100);
	this->Right_Motor(100);
}

void Grove_Car_Car_RPI::moveBack(){
	this->Left_Motor(-100);
	this->Right_Motor(-100);
}

void Grove_Car_Car_RPI::stop(){
	this->Left_Motor(0);
	this->Right_Motor(0);
}

void Grove_Car_Car_RPI::turnLeft(){
	this->Left_Motor(0);
	this->Right_Motor(100);
}

void Grove_Car_Car_RPI::turnRight(){
	this->Left_Motor(100);
	this->Right_Motor(0);
}

/*
 * set Left/right wheel speed
 * @param speed range from -63 to 63. 
 */
void Grove_Car_Car_RPI::Left_Motor(int speed)
{
        this->selectSlave(MOTOR_LEFT_ADDR);

	uint8_t regValue = 0x80;          //Before we do anything, we'll want to
                                          //  clear the fault status. To do that
                                          //  write 0x80 to register 0x01 on the
                                          //  DRV8830.
        this->sendCommand(0x01, regValue);// Clear the fault status. 

	regValue = (uint8_t)abs(speed);      // Find the byte-ish abs value of the input
  	if (regValue > 63) regValue = 63; // Cap the value at 63.
  	regValue = regValue<<2;           // Left shift to make room for bits 1:0
  	if (speed < 0) regValue |= 0x01;  // Set bits 1:0 based on sign of input.
  	else           regValue |= 0x02;
  
  	this->sendCommand(0x00, regValue);
}


void Grove_Car_Car_RPI::Right_Motor(int speed)
{
        this->selectSlave(MOTOR_RIGHT_ADDR);
	
	uint8_t regValue = 0x80;          //Before we do anything, we'll want to
                                          //  clear the fault status. To do that
                                    	  //  write 0x80 to register 0x01 on the
                                    	  //  DRV8830.
	this->sendCommand(0x01, regValue);// Clear the fault status.

        regValue = (uint8_t)abs(speed);      // Find the byte-ish abs value of the input
        if (regValue > 63) regValue = 63; // Cap the value at 63.
        regValue = regValue<<2;           // Left shift to make room for bits 1:0
        if (speed < 0) regValue |= 0x01;  // Set bits 1:0 based on sign of input.
        else           regValue |= 0x02;
  
        this->sendCommand(0x00, regValue);
}


/**
 * Grove - Mini I2C Motor Driver v1.0
 * send register a byte
 */


void Grove_Car_Car_RPI::sendCommand( uint8_t reg_addr, uint8_t value)
{
        int error = i2c_smbus_write_byte_data(DEVICE_FILE, reg_addr, value);

        if(error == -1)
                throw I2CError("[I2CError writing data: check Motor wirings]\n");
}

/**
 * the LCD has 2 slaves
 * 1 for the RGB backlight color
 * 1 for the actual text
 * therefore there are 2 adresses
 * @param slave 7-bit address
 */
void Grove_Car_Car_RPI::selectSlave(uint8_t slave)
{
	ioctl(DEVICE_FILE,I2C_TENBIT,1); //switch to 10-bit address module

	int error = ioctl(DEVICE_FILE, I2C_SLAVE, slave);//init connection between i2c_client and slave_address;
        if(error == -1)
                throw I2CError("[I2CError selecting Motor address]\n");
}
}
tinylink::Grove_Car_Car_RPI TL_Car;
