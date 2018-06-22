#ifndef LORA_SHIELD_ARDUINO_UNO_H
#define LORA_SHIELD_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "RH_RF95.h"

class LORA_Shield_LORA_Arduino_UNO
{

public:
    bool init();
    bool available();
    bool recv(uint8_t* buf, uint8_t* len);
    bool send(uint8_t* data, uint8_t len);
    bool waitPacketSent();
    void setThisAddress(uint8_t thisAddress);
    void setHeaderTo(uint8_t to);
    void setHeaderFrom(uint8_t from);
    void setHeaderId(uint8_t id);
    void setHeaderFlags(uint8_t set);
    uint8_t headerTo();
    uint8_t headerFrom();
    uint8_t headerId();
    uint8_t headerFlags();
    bool setFrequency(float centre);
    void setTxPower(int8_t power, bool useRFO = false);
    int8_t lastRssi();
    
protected:
    
private:

};

extern LORA_Shield_LORA_Arduino_UNO TL_LoRa;

#endif
