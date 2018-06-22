#include "LORA_Shield_LORA_Arduino_UNO.h"

RH_RF95 rf95;

bool LORA_Shield_LORA_Arduino_UNO::init()
{
    return rf95.init();
}

bool LORA_Shield_LORA_Arduino_UNO::available()
{
    return rf95.available();
}

bool LORA_Shield_LORA_Arduino_UNO::recv(uint8_t* buf, uint8_t* len)
{
    return rf95.recv(buf, len);
}

bool LORA_Shield_LORA_Arduino_UNO::send(uint8_t* data, uint8_t len)
{
    return rf95.send(data, len);
}

bool LORA_Shield_LORA_Arduino_UNO::waitPacketSent()
{
    return rf95.waitPacketSent();
}

void LORA_Shield_LORA_Arduino_UNO::setThisAddress(uint8_t thisAddress)
{
    rf95.setThisAddress(thisAddress);
}

void LORA_Shield_LORA_Arduino_UNO::setHeaderTo(uint8_t to)
{
    rf95.setHeaderTo(to);
}

void LORA_Shield_LORA_Arduino_UNO::setHeaderFrom(uint8_t from)
{
    rf95.setHeaderFrom(from);
}

void LORA_Shield_LORA_Arduino_UNO::setHeaderId(uint8_t id)
{
    rf95.setHeaderId(id);
}

void LORA_Shield_LORA_Arduino_UNO::setHeaderFlags(uint8_t set)
{
    rf95.setHeaderFlags(set, 0xff);
}

uint8_t LORA_Shield_LORA_Arduino_UNO::headerTo()
{
    return rf95.headerTo();
}

uint8_t LORA_Shield_LORA_Arduino_UNO::headerFrom()
{
    return rf95.headerFrom();
}

uint8_t LORA_Shield_LORA_Arduino_UNO::headerId()
{
    return rf95.headerId();
}

uint8_t LORA_Shield_LORA_Arduino_UNO::headerFlags()
{
    return rf95.headerFlags();
}

bool LORA_Shield_LORA_Arduino_UNO::setFrequency(float centre)
{
    return rf95.setFrequency(centre);
}

void LORA_Shield_LORA_Arduino_UNO::setTxPower(int8_t power, bool useRFO)
{
    rf95.setTxPower(power, useRFO);
}

int8_t LORA_Shield_LORA_Arduino_UNO::lastRssi()
{
    return rf95.lastRssi();
}


LORA_Shield_LORA_Arduino_UNO TL_LoRa;
