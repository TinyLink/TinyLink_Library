// GrovePi C library
// v0.1
//
// This library provides the basic functions for using the GrovePi in C
//
// The GrovePi connects the Raspberry Pi and Grove sensors.  You can learn more about GrovePi here:  http://www.dexterindustries.com/GrovePi
//
// Have a question about this example?  Ask on the forums here: http://forum.dexterindustries.com/c/grovepi
//
// 	History
// 	------------------------------------------------
// 	Author		Date      		Comments
//	Karan		28 Dec 15		Initial Authoring

/*
License

The MIT License (MIT)

GrovePi for the Raspberry Pi: an open source platform for connecting Grove Sensors to the Raspberry Pi.
Copyright (C) 2015  Dexter Industries

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "grovepi.h"

int fd;													
char *fileName = "/dev/i2c-1";								
int  address = 0x04;									
unsigned char w_buf[5],ptr,r_buf[32];	
unsigned long reg_addr=0;    

static int max_i2c_retries = 5;

#define dbg 0
int init_dev(void)
{
	if ((fd = open(fileName, O_RDWR)) < 0) 
	{					// Open port for reading and writing
		printf("Failed to open i2c port\n");
		return -1;
	}
	
	if (ioctl(fd, I2C_SLAVE, address) < 0) 
	{					// Set the port options and set the address of the device 
		printf("Unable to get bus access to talk to slave\n");
		return -1;
	}
	return 1;
}

/**
 * sleep raspberry
 * @param milliseconds time
 */
void delay(unsigned int milliseconds)
{
        usleep(milliseconds * 1000);
}


static uint8_t gpioHardwareRevision()
{
        int revision = 0;
        FILE * filp = fopen("/proc/cpuinfo", "r");
        char buffer[512];
        char term;

        if(filp != NULL)
        {
                while(fgets(buffer,sizeof(buffer),filp) != NULL)
                {
                        if(!strncasecmp("revision\t", buffer, 9))
                        {
                                if(sscanf(buffer + strlen(buffer) - 5, "%x%c", &revision, &term) == 2)
                                {
                                        if(term == '\n')
                                                break;
                                        revision = 0;
                                }
                        }
                }
                fclose(filp);
        }
        return revision;
}


/**
 * determines wheter I2C is found at "/dev/i2c-0" or "/dev/i2c-1"
 * depending on the raspberry model
 *
 * @param smbus_name string to hold the filename
 *
 * hw_rev    0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
 * Type.1    X  X  -  -  X  -  -  X  X  X  X  X  -  -  X  X
 * Type.2    -  -  X  X  X  -  -  X  X  X  X  X  -  -  X  X
 * Type.3          X  X  X  X  X  X  X  X  X  X  X  X  X  X
 *
 * hw_rev    16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
 * Type.1    -  X  X  -  -  X  X  X  X  X  -  -  -  -  -  -
 * Type.2    -  X  X  -  -  -  X  X  X  X  -  X  X  X  X  X
 * Type.3    X  X  X  X  X  X  X  X  X  X  X  X  -  -  -  -
 *
 */
void SMBusName(char *smbus_name)
{
        unsigned int hw_revision = gpioHardwareRevision();
        unsigned int smbus_rev;

        if(hw_revision < 4)
                // type 1 
                smbus_rev = 1;
        else if(hw_revision < 16)
                // type 2 
                smbus_rev = 2;
        else
                // type 3 
                smbus_rev = 3;

        if(smbus_rev == 2 || smbus_rev == 3)
                strcpy(smbus_name, "/dev/i2c-1");
        else
                strcpy(smbus_name, "/dev/i2c-0");
}


/**
 * for setting the address of an I2C device
 * @param address 7-bit address of the slave device
 */
int initDevice(uint8_t address)
{
        char filename[11];           // enough to hold "/dev/i2c-x"
        int current_retry = 0;
        int i2c_file_device;
        SMBusName(filename);

        // try to connect for a number of times
        while(current_retry < max_i2c_retries)
        {
                // increase the counter
                current_retry += 1;

                // open port for read/write operation
                if((i2c_file_device = open(filename, O_RDWR)) < 0)
                {
                        printf("[failed to open i2c port]\n");
                        // try in the next loop to connect
                        continue;
                }
                // setting up port options and address of the device
                if(ioctl(i2c_file_device, I2C_SLAVE, address) < 0)
                {
                        printf("[unable to get bus access to talk to slave]\n");
                        // try in the next loop to connect
                        continue;
                }

                // if it got connected, then exit
                break;
        }

        // if connection couldn't be established
        // throw exception
        if(current_retry == max_i2c_retries)
                throw I2CError("[I2CError on opening port]\n");

        return i2c_file_device;
}


//Write a register
int write_block(char cmd,char v1,char v2,char v3)
{			
	int dg;
	w_buf[0]=cmd;
    w_buf[1]=v1;
    w_buf[2]=v2;
    w_buf[3]=v3;
	
    dg=i2c_smbus_write_i2c_block_data(fd,1,4,w_buf);
	
	if (dbg)
		printf("wbk: %d\n",dg);
	
    // if (i2c_smbus_write_i2c_block_data(fd,1,4,w_buf) != 5) 
    // {								
        // printf("Error writing to GrovePi\n");
        // return -1;
    // }
    return 1; 
}

//write a byte to the GrovePi
int write_byte(char b)
{
    w_buf[0]=b;													
    if ((write(fd, w_buf, 1)) != 1) 
    {								
        printf("Error writing to GrovePi\n");
        return -1;
    }
    return 1; 
}

//Read 1 byte of data
char read_byte(void)
{
	r_buf[0]=i2c_smbus_read_byte(fd);
	if (dbg)
		printf("rbt: %d\n",r_buf[0]);
	// if (read(fd, r_buf, reg_size) != reg_size) {								
		// printf("Unable to read from GrovePi\n");
		// //exit(1);
        // return -1;
	// }
    
    return r_buf[0];
}

//Read a 32 byte block of data from the GrovePi
char read_block(void)
{
    int ret;
    ret=i2c_smbus_read_i2c_block_data(fd,1,32,&r_buf[0]);
	//&r_buf[0]=&ptr;
	if(dbg)
		printf("rbk: %d\n",ret);
	// if (read(fd, r_buf, reg_size) != reg_size) {								
		// printf("Unable to read from GrovePi\n");
		// //exit(1);
        // return -1;
	// }
    
    return 1;
}

void pi_sleep(int t) 
{
	usleep(t*1000);
}

// Read analog value from Pin
int analogRead(int pin)
{
	int data;
	write_block(aRead_cmd,pin,0,0);
	read_byte();
	read_block();
	data=r_buf[1]* 256 + r_buf[2];
	if (data==65535)
		return -1;
	return data;
}

//Write a digital value to a pin
int digitalWrite(int pin,int value)
{
	return write_block(dWrite_cmd,pin,value,0);
}

//Set the mode of a pin
//mode
//	1: 	output
//	0:	input
int pinMode(int pin,int mode)
{
	return write_block(pMode_cmd,pin,mode,0);
}

//Read a digital value from a pin
int digitalRead(int pin)
{
	write_block(dRead_cmd,pin,0,0);
	usleep(10000);
	return read_byte();
}

//Write a PWM value to a pin
int analogWrite(int pin,int value)
{
	return write_block(aWrite_cmd,pin,value,0);
}

float toFloat(unsigned char a[4]) {
    float ans;
    memcpy(&ans, a, 4);
    return ans;
}

pair<float, float> dht(int pin, int module) {
	int data;
	write_block(40 ,pin,module,0);
	read_byte();
	read_block();
    return pair<float, float>(toFloat(r_buf + 1), toFloat(r_buf + 5));
}

const char* I2CError::detail()
{
        return this->what();
}

