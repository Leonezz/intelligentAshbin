#ifndef ADC_PERIPHS_H
#define ADC_PERIPHS_H
#include "modbushandler.h"
#include "main.h"
#define GAS_ADCBUF_ADDR 0x00
#define ADCBufSize 1
extern uint16_t ADCBuf[ADCBufSize];
inline void loadGasDataToModbusProtocolStack();
inline void ADC_DMA_Config();

#endif