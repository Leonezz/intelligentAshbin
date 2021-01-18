#include "uart_periphs.h"

uint8_t temperatureAndHumidityRxBuf[USART1_RX_LENGTH] = {0};
uint8_t temperatureAndHumidityTxBuf[USART1_TX_LENGTH] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x02, 0xC4, 0x0B};
uint8_t weightRxBuf[USART3_RX_LENGTH] = {0};
uint8_t weightTxBuf[USART3_TX_LENGTH] = {0x01, 0x03, 0x00, 0x50, 0x00, 0x02, 0xC4, 0x1A};
uint8_t scanerRxBuf[USART6_RX_LENGTH] = {0};
ScanerDataValidStatusTypeDef scanerDataValidBit = INVALID;
uint8_t ultraSoundRxBuf[UART5_RX_LENGTH] = {0};
void tempreatureAndHumityUSART_DMA_Config()
{
    // recive DMA
    LL_DMA_SetMemoryAddress(DMA2, LL_DMA_STREAM_2, (uint32_t)temperatureAndHumidityRxBuf);
    LL_DMA_SetPeriphAddress(DMA2, LL_DMA_STREAM_2, LL_USART_DMA_GetRegAddr(USART1));
    LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_2, USART1_RX_LENGTH);
    LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_2);

    // transmit DMA
    LL_DMA_SetMemoryAddress(DMA2, LL_DMA_STREAM_7, (uint32_t)temperatureAndHumidityTxBuf);
    LL_DMA_SetPeriphAddress(DMA2, LL_DMA_STREAM_7, LL_USART_DMA_GetRegAddr(USART1));
    LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_7, USART1_TX_LENGTH);

    LL_USART_EnableIT_IDLE(USART1);
    LL_USART_EnableDMAReq_RX(USART1);
    LL_USART_EnableDMAReq_TX(USART1);
}

void weightUSART_DMA_Config()
{
    // recive DMA
    LL_DMA_SetMemoryAddress(DMA1, LL_DMA_STREAM_1, (uint32_t)weightRxBuf);
    LL_DMA_SetPeriphAddress(DMA1, LL_DMA_STREAM_1, LL_USART_DMA_GetRegAddr(USART3));
    LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_1, USART3_RX_LENGTH);
    LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_1);

    // transmit DMA
    LL_DMA_SetMemoryAddress(DMA1, LL_DMA_STREAM_3, (uint32_t)weightTxBuf);
    LL_DMA_SetPeriphAddress(DMA1, LL_DMA_STREAM_3, LL_USART_DMA_GetRegAddr(USART3));
    LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_3, USART3_TX_LENGTH);

    LL_USART_EnableIT_IDLE(USART3);
    LL_USART_EnableDMAReq_RX(USART3);
    LL_USART_EnableDMAReq_TX(USART3);
}

void tempreatureAndHumityUSART_Rx_IQR()
{
    if (LL_USART_IsActiveFlag_IDLE(USART1))
    {
        LL_USART_ClearFlag_IDLE(USART1);
        LL_DMA_DisableStream(DMA2, LL_DMA_STREAM_2);
        LL_DMA_ClearFlag_TC2(DMA2);
        LL_DMA_ClearFlag_HT2(DMA2);
        LL_USART_DisableDMAReq_RX(USART1);
        LL_DMA_SetMemoryAddress(DMA2, LL_DMA_STREAM_2, (uint32_t)temperatureAndHumidityRxBuf);
        LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_2, USART1_RX_LENGTH);
        LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_2);
        LL_USART_EnableDMAReq_RX(USART1);
        // load data to protocol stack after receiving
        loadTempreatureAndHumidyDataToModbusProtocolStack();
    }
}

uint8_t tempreatureAndHumityUSART_Send_Bytes(uint8_t *bytes, uint32_t length)
{
    //while (LL_USART_IsActiveFlag_TC(USART1)==0)
    //{
    //}
    LL_DMA_ClearFlag_TC7(DMA2);

    memccpy(temperatureAndHumidityTxBuf, bytes, length);

    LL_DMA_DisableStream(DMA2, LL_DMA_STREAM_7);
    LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_7, length);
    LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_7);

    return 0;
}

void loadTempreatureAndHumidyDataToModbusProtocolStack()
{
    uint16_t tempreature = (temperatureAndHumidityRxBuf[TEMPREATURE_UART_ADDR] << 8) +
                           temperatureAndHumidityRxBuf[TEMPREATURE_UART_ADDR + 1];
    setTempreatureValue(tempreature);
    uint16_t humity = (temperatureAndHumidityRxBuf[HUMIDITY_UART_ADDR] << 8) +
                      temperatureAndHumidityRxBuf[HUMIDITY_UART_ADDR + 1];
    setHumityValue(humity);
}

void loadWeightDataToModbusProtocolStack()
{
    const uint16_t high = (weightRxBuf[WEIGHT_UART_ADDR] << 8) +
                          weightRxBuf[WEIGHT_UART_ADDR + 1];
    const uint16_t low = (weightRxBuf[WEIGHT_UART_ADDR + 2] << 8) +
                         (weightRxBuf[WEIGHT_UART_ADDR + 3]);
    setWeightValue(high, low);
}

void weightUSART_Rx_IQR()
{
    if (LL_USART_IsActiveFlag_IDLE(USART3))
    {
        LL_USART_ClearFlag_IDLE(USART3);
        LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_1);
        LL_DMA_ClearFlag_TC1(DMA1);
        LL_DMA_ClearFlag_HT1(DMA1);
        LL_USART_DisableDMAReq_RX(USART3);
        LL_DMA_SetMemoryAddress(DMA1, LL_DMA_STREAM_1, (uint32_t)weightRxBuf);
        LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_1, USART3_RX_LENGTH);
        LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_1);
        LL_USART_EnableDMAReq_RX(USART3);

        loadWeightDataToModbusProtocolStack();
    }
}

uint8_t weightUSART_Send_Bytes(uint8_t *bytes, uint32_t length)
{
    //while (LL_USART_IsActiveFlag_TC(USART1)==0)
    //{
    //}
    LL_DMA_ClearFlag_TC3(DMA1);

    memccpy(weightTxBuf, bytes, length);

    LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_3);
    LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_3, length);
    LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_3);

    return 0;
}

void scanerUSART_Rx_IQR()
{
    if (LL_USART_IsActiveFlag_IDLE(USART6))
    {
        LL_USART_ClearFlag_IDLE(USART6);
        LL_DMA_DisableStream(DMA2, LL_DMA_STREAM_1);
        LL_DMA_ClearFlag_TC1(DMA2);
        LL_DMA_ClearFlag_HT1(DMA2);
        LL_USART_DisableDMAReq_RX(USART6);
        LL_DMA_SetMemoryAddress(DMA2, LL_DMA_STREAM_1, (uint32_t)(scanerRxBuf));
        LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_1, USART6_RX_LENGTH);
        LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_1);
        LL_USART_EnableDMAReq_RX(USART6);

        scanerDataValidBit = VALID;
        loadScanerDataToModbusProtocolStack();
    }
}

void scanerUSART_DMA_Config()
{
    // recive DMA
    LL_DMA_SetMemoryAddress(DMA2, LL_DMA_STREAM_1, (uint32_t)(scanerRxBuf + 1));
    LL_DMA_SetPeriphAddress(DMA2, LL_DMA_STREAM_1, LL_USART_DMA_GetRegAddr(USART6));
    LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_1, USART6_RX_LENGTH);
    LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_1);

    LL_USART_EnableIT_IDLE(USART6);
    LL_USART_EnableDMAReq_RX(USART6);
    //LL_USART_EnableDMAReq_TX(USART6);
}

void loadScanerDataToModbusProtocolStack()
{
    setScanerData(scanerRxBuf);
    setScanerDataValidStatus(scanerDataValidBit);
}

void ultraSoundUART_DMA_Config()
{
    LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_0, UART5_RX_LENGTH);
    LL_DMA_SetPeriphAddress(DMA1, LL_DMA_STREAM_0, LL_USART_DMA_GetRegAddr(UART5));
    LL_DMA_SetMemoryAddress(DMA1, LL_DMA_STREAM_0, (uint32_t)ultraSoundRxBuf);
    LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_0);

    LL_USART_EnableDMAReq_RX(UART5);
}

void loadUltraSoundDataToMoubusProtocolStack()
{
    uint16_t distanceInMillimeters =
        (ultraSoundRxBuf[ULTRASOUND_DATA_HIGH_POS] << 8) +
        ultraSoundRxBuf[ULTRASOUND_DATA_LOW_POS];
    if (distanceInMillimeters >= 200)
    {
        setUltraSoundValue(distanceInMillimeters);
    }
}