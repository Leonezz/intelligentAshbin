#ifndef UART_PERIPHS_H
#define UART_PERIPHS_H
#include "main.h"
#include "modbushandler.h"
#include "log.h"
#define USART1_RX_LENGTH 9
#define USART1_TX_LENGTH 8
#define TEMPREATURE_UART_ADDR 3
#define HUMIDITY_UART_ADDR 5
#define BYTE_LENGTH_IN_UART1BUF 2
extern uint8_t temperatureAndHumidityTxBuf[USART1_TX_LENGTH];
extern uint8_t temperatureAndHumidityRxBuf[USART1_RX_LENGTH];

#define USART3_RX_LENGTH 9
#define USART3_TX_LENGTH 8
#define WEIGHT_UART_ADDR 3
extern uint8_t weightRxBuf[USART3_RX_LENGTH];
extern uint8_t weightTxBuf[USART3_TX_LENGTH];

inline void tempreatureAndHumityUSART_Rx_IQR();
inline uint8_t tempreatureAndHumityUSART_Send_Bytes(uint8_t *bytes, uint32_t length);
inline void tempreatureAndHumityUSART_DMA_Config(void);
static inline void loadTempreatureAndHumidyDataToModbusProtocolStack();

static inline void loadWeightDataToModbusProtocolStack();
inline void weightUSART_Rx_IQR();
inline void weightUSART_DMA_Config();
inline uint8_t weightUSART_Send_Bytes(uint8_t *bytes, uint32_t length);

#define USART6_RX_LENGTH 13
#define SCANER_DATA_START_ADDR 0

extern uint8_t scanerRxBuf[USART6_RX_LENGTH];

extern ScanerDataValidStatusTypeDef scanerDataValidBit;
inline void scanerUSART_DMA_Config();
inline void scanerUSART_Rx_IQR();
static inline void loadScanerDataToModbusProtocolStack();

#define UART5_RX_LENGTH 4
#define ULTRASOUND_DATA_LOW_POS 2
#define ULTRASOUND_DATA_HIGH_POS 1
extern uint8_t ultraSoundRxBuf[UART5_RX_LENGTH];
inline void ultraSoundUART_DMA_Config();
inline void loadUltraSoundDataToMoubusProtocolStack();
#endif