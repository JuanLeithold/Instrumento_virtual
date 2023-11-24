/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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
#define O1_Pin GPIO_PIN_14
#define O1_GPIO_Port GPIOC
#define O2_Pin GPIO_PIN_15
#define O2_GPIO_Port GPIOC
#define O3_Pin GPIO_PIN_0
#define O3_GPIO_Port GPIOA
#define O4_Pin GPIO_PIN_1
#define O4_GPIO_Port GPIOA
#define O5_Pin GPIO_PIN_2
#define O5_GPIO_Port GPIOA
#define O6_Pin GPIO_PIN_3
#define O6_GPIO_Port GPIOA
#define O7_Pin GPIO_PIN_4
#define O7_GPIO_Port GPIOA
#define O8_Pin GPIO_PIN_5
#define O8_GPIO_Port GPIOA
#define OPWM1_Pin GPIO_PIN_7
#define OPWM1_GPIO_Port GPIOA
#define OPWM2_Pin GPIO_PIN_0
#define OPWM2_GPIO_Port GPIOB
#define MUXA_Pin GPIO_PIN_1
#define MUXA_GPIO_Port GPIOB
#define MUXB_Pin GPIO_PIN_10
#define MUXB_GPIO_Port GPIOB
#define MUXC_Pin GPIO_PIN_11
#define MUXC_GPIO_Port GPIOB
#define EN_Pin GPIO_PIN_12
#define EN_GPIO_Port GPIOB
#define BUZZER_Pin GPIO_PIN_15
#define BUZZER_GPIO_Port GPIOB
<<<<<<< HEAD
=======
#define RS_MODE_Pin GPIO_PIN_8
#define RS_MODE_GPIO_Port GPIOA
>>>>>>> c499ee18f90316c201fdafdd6c6c334d44865699
#define TX_Pin GPIO_PIN_9
#define TX_GPIO_Port GPIOA
#define RX_Pin GPIO_PIN_10
#define RX_GPIO_Port GPIOA
#define ID8_Pin GPIO_PIN_15
#define ID8_GPIO_Port GPIOA
#define ID7_Pin GPIO_PIN_3
#define ID7_GPIO_Port GPIOB
#define ID6_Pin GPIO_PIN_4
#define ID6_GPIO_Port GPIOB
#define ID5_Pin GPIO_PIN_5
#define ID5_GPIO_Port GPIOB
#define ID4_Pin GPIO_PIN_6
#define ID4_GPIO_Port GPIOB
#define ID3_Pin GPIO_PIN_7
#define ID3_GPIO_Port GPIOB
#define ID2_Pin GPIO_PIN_8
#define ID2_GPIO_Port GPIOB
#define ID1_Pin GPIO_PIN_9
#define ID1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
