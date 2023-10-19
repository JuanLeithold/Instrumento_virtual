/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "rs485.h"
#include <stdlib.h>
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

char arreglo2 [64];

const char QT_addres []= "0xA0";
union union_var
{
	uint8_t x;
	char arreglo[4];
};

int ready = 0;
uint8_t analog_input [16];
	uint8_t digital_input[8]={1,0,1,0,1,0,1,0};
	uint8_t bufTx [24];
	int j;
	int position=0;
	int data;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	union union_var aux;
	uint8_t rs_buftx[4];
	int32_t c1=0;
	int32_t c2=0;
	char cadena;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_TIM4_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
   HAL_TIM_Base_Start_IT(&htim4);
   HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	 	/* HAL_GPIO_WritePin(GPIOA, RS_MODE_Pin, GPIO_PIN_RESET);// Para rx

	 	  if (HAL_UART_Receive(&huart1, &rs_buftx, 4, TIME_OUT)==HAL_OK)
	 	  	  	  {
	 		  	  	// HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	 		  	  	 for (int i=0; i<4;i++)
	 		  	  	 {
	 		  	  		 aux.arreglo[i]=rs_buftx[i];
	 		  	  	 }
	 		  	  	 c1 = aux.x;
	 		  	  HAL_GPIO_WritePin(GPIOA, RS_MODE_Pin, GPIO_PIN_SET);
	 		  	  HAL_UART_Transmit(&huart1, &rs_buftx, 4, TIME_OUT);
	 	  	 	  }
					htim3.Instance->CCR1=c1;

*/



    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {



	if (htim->Instance == TIM4)
	{

		if (position <8)
		{
			data = position*100;
			analog_input[position*2] = (uint8_t)(0xff & (data>>8));
			analog_input[(position*2)+1]=(uint8_t)(0xff & data);
			position++;
		}
		else
		{
			position=0;
			ready=1;
		}
	}
	if (htim->Instance == TIM2)
	{

		 if (ready)
			  {
			 	 j=0;
				  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
				  for (int i = 0; i < 24; i++)
				  {
					if(i<16)
					{
						bufTx[i]= analog_input[i];
					}
					else
					{
						bufTx[i] = digital_input[j];
						j++;
					}
				  }


				  ready=0;
				  HAL_GPIO_WritePin(GPIOA, RS_MODE_Pin, GPIO_PIN_SET);
				  HAL_UART_Transmit(&huart1, &bufTx, 24, TIME_OUT);
				 //HAL_GPIO_WritePin(GPIOA, RS_MODE_Pin, GPIO_PIN_RESET);

			  }


    }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
