#ifndef UART_PERIPHS_H
#define UART_PERIPHS_H
#include "main.h"
#include "modbushandler.h"
#include "log.h"
#define USART1_RX_LENGTH            9
#define USART1_TX_LENGTH            8
#define TEMPREATURE_UART_ADDR       3
#define HUMIDITY_UART_ADDR          5
#define BYTE_LENGTH_IN_UART1BUF     2
extern uint8_t temperatureAndHumidityTxBuf[USART1_TX_LENGTH];
extern uint8_t temperatureAndHumidityRxBuf[USART1_RX_LENGTH];


#define USART3_RX_LENGTH            9
#define USART3_TX_LENGTH            8
#define WEIGHT_UART_ADDR            3
extern uint8_t weightRxBuf[USART3_RX_LENGTH];
extern uint8_t weightTxBuf[USART3_TX_LENGTH];

void usart1RxIQR();
uint8_t usart1SendBytes(uint8_t* bytes,uint32_t length);
inline void USART1_DMA_Config(void);

void loadTempreatureAndHumidyData();
void loadWeightData();
void usart3RxIQR();
inline void USART3_DMA_Config();
uint8_t usart3SendBytes(uint8_t* bytes,uint32_t length);
#endif