

#ifndef __BATTERY_H__
#define __BATTERY_H__

#include "mbed.h"

class Battery {
public:
    Battery(PinName pin) {
        uint32_t n = (uint32_t) pin;
        channel = 1 << (1 + n);
    }
    
    float read() {
        uint32_t pre_enable_register = NRF_ADC->ENABLE;
        uint32_t pre_config_register = NRF_ADC->CONFIG;
        
        
        NRF_ADC->ENABLE = ADC_ENABLE_ENABLE_Enabled;
        NRF_ADC->CONFIG = (ADC_CONFIG_RES_10bit << ADC_CONFIG_RES_Pos) |
                          (ADC_CONFIG_INPSEL_AnalogInputNoPrescaling << ADC_CONFIG_INPSEL_Pos) |
                          (ADC_CONFIG_REFSEL_VBG << ADC_CONFIG_REFSEL_Pos) |
                          (channel << ADC_CONFIG_PSEL_Pos) |
                          (ADC_CONFIG_EXTREFSEL_None << ADC_CONFIG_EXTREFSEL_Pos);
                          
        NRF_ADC->TASKS_START = 1;
        while (((NRF_ADC->BUSY & ADC_BUSY_BUSY_Msk) >> ADC_BUSY_BUSY_Pos) == ADC_BUSY_BUSY_Busy) {
        } 
        
        uint16_t value = NRF_ADC->RESULT;
        
        NRF_ADC->ENABLE = pre_enable_register;
        NRF_ADC->CONFIG = pre_config_register;
        
        return (float)value * (1.0f / (float)0x3FF) * 1.2 * 12.2 / 2.2;    
    }
    
private:
    uint32_t channel;
};

#endif // __BATTERY_H__
