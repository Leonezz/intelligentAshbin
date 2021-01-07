#include "uart_periphs.h"

uint8_t temperatureAndHumidityRxBuf[USART1_RX_LENGTH] = {0};
uint8_t temperatureAndHumidityTxBuf[USART1_TX_LENGTH] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x02, 0xC4, 0x0B};
uint8_t weightRxBuf[USART3_RX_LENGTH] = {0};
uint8_t weightTxBuf[USART3_TX_LENGTH] = {0x01, 0x03, 0x00, 0x50, 0x00, 0x02, 0xC4, 0x1A};
void USART1_DMA_Config()
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

void USART3_DMA_Config()
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

void usart1RxIQR()
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
    }
}

uint8_t usart1SendBytes(uint8_t *bytes, uint32_t length)
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

void loadTempreatureAndHumidyData()
{
    uint16_t tempreature = (temperatureAndHumidityRxBuf[TEMPREATURE_UART_ADDR] << 8) +
                           temperatureAndHumidityRxBuf[TEMPREATURE_UART_ADDR + 1];
    usRegInputBuf[REG_TEMPREATURE_ADDR] = tempreature;
    uint16_t humidy = (temperatureAndHumidityRxBuf[HUMIDITY_UART_ADDR] << 8) +
                      temperatureAndHumidityRxBuf[HUMIDITY_UART_ADDR + 1];
    usRegInputBuf[REG_HUMITY_ADDR] = humidy;
}

void loadWeightData()
{
    uint16_t weight = (weightRxBuf[WEIGHT_UART_ADDR] << 8) +
                      weightRxBuf[WEIGHT_UART_ADDR + 1];
    usRegInputBuf[REG_WEIGHT_ADDR] = weight;
    weight = (weightRxBuf[WEIGHT_UART_ADDR + 2] << 8) +
             (weightRxBuf[WEIGHT_UART_ADDR + 3]);
    usRegInputBuf[REG_WEIGHT_ADDR + 1] = weight;
}

void usart3RxIQR()
{
    if (LL_USART_IsActiveFlag_IDLE(USART3))
    {
        LL_USART_ClearFlag_IDLE(USART3);
        LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_1);
        LL_DMA_ClearFlag_TC1(DMA1);
        LL_DMA_ClearFlag_HT1(DMA1);
        LL_USART_DisableDMAReq_RX(USART3);
        int cnt = LL_DMA_GetDataLength(DMA1, LL_DMA_STREAM_1);
        for (int i = 0; i < cnt; ++i)
        {
            LOGI("%d", weightRxBuf[i]);
        }
        LL_DMA_SetMemoryAddress(DMA1, LL_DMA_STREAM_1, (uint32_t)weightRxBuf);
        LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_1, USART3_RX_LENGTH);
        LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_1);
        LL_USART_EnableDMAReq_RX(USART3);
    }
}

uint8_t usart3SendBytes(uint8_t *bytes, uint32_t length)
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