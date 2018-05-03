
#include <stdio.h>
#include "i2c_api.h"
#include "gpio_api.h"
#include "nrf_delay.h"

static i2c_t mbed_i2c_object = {0,};

void mbed_i2c_init(PinName sda, PinName scl)
{
    i2c_init(&mbed_i2c_object, sda, scl);
    i2c_frequency(&mbed_i2c_object, 100000);
}

int mbed_i2c_write(unsigned char slave_addr,
                     unsigned char reg_addr,
                     unsigned char length,
                     unsigned char const *data)
{
    int i;
    slave_addr = slave_addr << 1;
    i2c_start(&mbed_i2c_object);
    i2c_byte_write(&mbed_i2c_object, slave_addr);
    i2c_byte_write(&mbed_i2c_object, reg_addr);
    for (i = 0; i < length; i++) {
        i2c_byte_write(&mbed_i2c_object, data[i]);
    }
    i2c_stop(&mbed_i2c_object);
    return 0;
}

int mbed_i2c_read(unsigned char slave_addr,
                    unsigned char reg_addr,
                    unsigned char length,
                    unsigned char *data)
{
    slave_addr = slave_addr << 1;
    i2c_write(&mbed_i2c_object, slave_addr, &reg_addr, 1, 0);
    return (i2c_read(&mbed_i2c_object, slave_addr, data, length, 1) == length) ? 0 : 1;
}

int mbed_i2c_clear(PinName sda, PinName scl)
{
    gpio_t sda_io, scl_io;
    
    if (mbed_i2c_object.i2c) {
        mbed_i2c_object.i2c->PSELSCL = 31;
        mbed_i2c_object.i2c->PSELSDA = 31;
    }
    
    gpio_init_in(&sda_io, sda);
    
    if (!gpio_read(&sda_io)) {
        printf("sda is always 0, i2c bus is not released\r\n");
        printf("try to clear i2c bus\r\n");
        gpio_init_out(&scl_io, scl);
        
        // Clock max 18 pulses worst case scenario(9 for master to send the rest of command and 9
        // for slave to respond) to SCL line and wait for SDA come high.
        for (int i = 0; i < 18; i++) {
            gpio_write(&scl_io, 0);
            nrf_delay_us(4);
            gpio_write(&scl_io, 1);
            nrf_delay_us(4);
        }
        
        if (!gpio_read(&sda_io)) {
            printf("warning! sda is still 0,, i2c bus is not released\r\n");
        }
    }
    
    
    if (mbed_i2c_object.i2c) {
        mbed_i2c_init(sda, scl);
    }
    
    return 0;
}
