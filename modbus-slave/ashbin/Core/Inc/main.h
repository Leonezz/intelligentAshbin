/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_adc.h"
#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx_ll_gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define full_Pin GPIO_PIN_2
#define full_GPIO_Port GPIOE
#define modbusTxEnable_Pin GPIO_PIN_0
#define modbusTxEnable_GPIO_Port GPIOC
#define triggerPutterKey_Pin GPIO_PIN_0
#define triggerPutterKey_GPIO_Port GPIOA
#define modbusSlaveUSART_TX_Pin GPIO_PIN_2
#define modbusSlaveUSART_TX_GPIO_Port GPIOA
#define modbusSlaveUSART_RX_Pin GPIO_PIN_3
#define modbusSlaveUSART_RX_GPIO_Port GPIOA
#define gasConcentrationADC_IN_Pin GPIO_PIN_4
#define gasConcentrationADC_IN_GPIO_Port GPIOA
#define weightUART_TX_Pin GPIO_PIN_10
#define weightUART_TX_GPIO_Port GPIOB
#define weightUART_RX_Pin GPIO_PIN_11
#define weightUART_RX_GPIO_Port GPIOB
#define scaner_RTS_Pin GPIO_PIN_8
#define scaner_RTS_GPIO_Port GPIOG
#define putterControll_Pin GPIO_PIN_9
#define putterControll_GPIO_Port GPIOC
#define temperatureAndHumidityUSART_TX_Pin GPIO_PIN_9
#define temperatureAndHumidityUSART_TX_GPIO_Port GPIOA
#define temperatureAndHumidityUSART_RX_Pin GPIO_PIN_10
#define temperatureAndHumidityUSART_RX_GPIO_Port GPIOA
#define stopper_Pin GPIO_PIN_10
#define stopper_GPIO_Port GPIOC
#define triggerPutterKey_OFFBOARD_Pin GPIO_PIN_11
#define triggerPutterKey_OFFBOARD_GPIO_Port GPIOC
#define distance_Tx_Pin GPIO_PIN_12
#define distance_Tx_GPIO_Port GPIOC
#define distance_Rx_Pin GPIO_PIN_2
#define distance_Rx_GPIO_Port GPIOD
#define fullIndicator_Pin GPIO_PIN_3
#define fullIndicator_GPIO_Port GPIOB
#define weightIndicator_Pin GPIO_PIN_4
#define weightIndicator_GPIO_Port GPIOB
#define tempreatureIndicator_Pin GPIO_PIN_5
#define tempreatureIndicator_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
