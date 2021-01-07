#include "adc_periphs.h"

uint16_t ADCBuf[ADCBufSize] = {1};
void loadGasData()
{
  usRegInputBuf[REG_GAS_ADDR] = ADCBuf[GAS_ADCBUF_ADDR];
}

void ADC_DMA_Config()
{
  LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_0, ADCBufSize);
  LL_DMA_SetPeriphAddress(DMA2, LL_DMA_STREAM_0, LL_ADC_DMA_GetRegAddr(ADC1, LL_ADC_DMA_REG_REGULAR_DATA));
  LL_DMA_SetMemoryAddress(DMA2, LL_DMA_STREAM_0, (uint32_t)ADCBuf);
  LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_0);

  LL_ADC_Enable(ADC1);
  LL_ADC_REG_SetDMATransfer(ADC1, LL_ADC_REG_DMA_TRANSFER_UNLIMITED);
  LL_ADC_REG_StartConversionSWStart(ADC1);
}