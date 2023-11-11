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
#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "rs485.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/* USER CODE END Includes */

/* USER CODE BEGIN PV */

/*Estructura para almacenar los datos a transmitir con su respectiva variable declarada*/
typedef struct {
  // Byte de caebcera.
  uint8_t header;
  // 8 entradas analógicas (12 bits).
  uint16_t analogInput1;
  uint16_t analogInput2;
  uint16_t analogInput3;
  uint16_t analogInput4;
  uint16_t analogInput5;
  uint16_t analogInput6;
  uint16_t analogInput7;
  uint16_t analogInput8;
  // 8 entradas digitales.
  uint8_t digitalInputs;

} txStruct_t;
txStruct_t txBufferStruct;

/*Estructura para almacenar los datos recibidos con su respectiva variable declarada*/
typedef struct {
  // 8 entradas analógicas (12 bits).
  uint8_t header;
  uint8_t analogOutput1;
  uint8_t analogOutput2;
  // 8 salidas digitales.
  uint8_t digitalOutputs;

} rxStruct_t; //Fin de struct
rxStruct_t rxBufferStruct;

/*Union para manejar los datos a transmitir con su respectiva variable declarada*/
typedef union
{
  txStruct_t txBuffer;
  char    txBuffer_c[18];
} unionTx_t; //Fin de union
unionTx_t txBufferUnion;

/*Union para manejar los datos recibidos con su respectiva variable declarada*/
typedef union
{
  rxStruct_t rxUnionBuffer;
  char    rxBuffer_c[sizeof(rxStruct_t)];
} unionRx_t; //Fin de union
unionRx_t rxUnion; //variable del tipo unionRx_t

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void PWMCONTROL1();
void PWMCONTROL2();
void salidadigital();
void entradadigital();
void barridomux();
/* USER CODE END PFP */


int main(void)
{
  /* USER CODE BEGIN 1 */

	static uint16_t adcRead;
	int adcInputCounter =1;		//Contador para ir seleccionando diferentes lecturas del adc y modificar el mux
	int readyToSend=0;
	int digitalDown=0;

	txBufferStruct.header = 0x1c;			//Cabecera para que QT dicierna que datos son correctos
	txBufferStruct.digitalInputs = 0x00;	//valor de i inicio para prueba
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
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_ADC1_Init();

  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);
  HAL_TIM_Base_Start_IT(&htim4);
  HAL_TIM_Base_Start_IT(&htim3);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  	HAL_GPIO_WritePin(GPIOA, RS_MODE_Pin, GPIO_PIN_RESET);				//Para utilizar modulo rs485 en rx
  	HAL_UART_Receive_IT(&huart1, (uint8_t*)&rxUnion,sizeof(rxUnion));	//para recepcion de la blue pil. Esta en proceso.

  	 int countingDown;
  	 while (1)
  	  {
<<<<<<< HEAD
		if	(adcRead==100)
			countingDown=1;
		if (adcRead==0)
			countingDown=0;

		if(countingDown)
			adcRead--;
		else
			adcRead++;


		switch (adcInputCounter)
		{
			case 1: txBufferStruct.analogInput1 = adcRead; break;
			case 2: txBufferStruct.analogInput2 = adcRead; break;
			case 3: txBufferStruct.analogInput3 = adcRead; break;
			case 4: txBufferStruct.analogInput4 = adcRead; break;
			case 5: txBufferStruct.analogInput5 = adcRead; break;
			case 6: txBufferStruct.analogInput6 = adcRead; break;
			case 7: txBufferStruct.analogInput7 = adcRead; break;
			case 8:
			{
				if (txBufferStruct.digitalInputs== 0b11111111)
				{
					digitalDown ==1;

				}
				else if (txBufferStruct.digitalInputs== 0b00000000)
				{
					digitalDown ==1;
				}
				if (digitalDown)
				{
					txBufferStruct.digitalInputs--;
				}
				else
				{
					txBufferStruct.digitalInputs++;
				}

				txBufferStruct.analogInput8 = adcRead;

				readyToSend=1;
				break;
			}
		}
		adcInputCounter++;

		if(readyToSend)
		{
			adcInputCounter=0;
			readyToSend=0;
			//HAL_GPIO_WritePin(GPIOA, RS_MODE_Pin, GPIO_PIN_SET);			//Se programa Modul RS485 para Tx
			HAL_UART_Transmit(&huart1, (uint8_t*)&txBufferStruct, sizeof(txBufferStruct), TIME_OUT);
			//HAL_GPIO_WritePin(GPIOA, RS_MODE_Pin, GPIO_PIN_RESET);
		}
=======
>>>>>>> 0c459ebb008ef5e87410555e15743d164119a668
    /* USER CODE END WHILE */
  		if(readyToSend)
  				{
  					adcInputCounter=0;
  					readyToSend=0;
  					HAL_GPIO_WritePin(GPIOA, RS_MODE_Pin, GPIO_PIN_SET);			//Se programa Modul RS485 para Tx
  					HAL_UART_Transmit(&huart1, (uint8_t*)&txBufferStruct, sizeof(txBufferStruct), TIME_OUT);
  					HAL_GPIO_WritePin(GPIOA, RS_MODE_Pin, GPIO_PIN_RESET);
  				}
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
uint8_t rxBuffer[3];
uint8_t data;
int c1=0;
int c2=0;
int counter=0;
uint8_t digitalOutput;

void PWMCONTROL1(){
	//HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
	htim3.Instance->CCR2=rxUnion.rxUnionBuffer.analogOutput1;
	HAL_GPIO_WritePin(OPWM1_GPIO_Port, OPWM1_Pin, 1);
}
void PWMCONTROL2(){
	//HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);
	htim3.Instance->CCR3=rxUnion.rxUnionBuffer.analogOutput2;
	HAL_GPIO_WritePin(OPWM1_GPIO_Port, OPWM1_Pin, 1);
}

void salidadigital(){
	//for(int z=0;z<8;z++){
		//switch(z){

		/*case 1 : {*/if((rxUnion.rxUnionBuffer.digitalOutputs & 0b10000000)>>7 ==1){
					   HAL_GPIO_TogglePin(O1_GPIO_Port,O1_Pin);}
			         //break;
					//}

		/*case 2 : {*/if((rxUnion.rxUnionBuffer.digitalOutputs & 0b01000000)>>6 ==1){
			   	   	   HAL_GPIO_TogglePin(O2_GPIO_Port,O2_Pin);}
					  //       break;
						//	}
		/*case 3 : {*/if((rxUnion.rxUnionBuffer.digitalOutputs & 0b00100000)>>5 ==1){
			           HAL_GPIO_TogglePin(O3_GPIO_Port,O2_Pin);}
					      //   break;
						//	}
		/*case 4 : {*/if((rxUnion.rxUnionBuffer.digitalOutputs & 0b00010000)>>4 ==1){
			   	   	   HAL_GPIO_TogglePin(O4_GPIO_Port,O4_Pin);}
					  //       break;
						//	}
		/*case 5 : {*/if((rxUnion.rxUnionBuffer.digitalOutputs & 0b00001000)>>3 ==1){
			   	   	   HAL_GPIO_TogglePin(O5_GPIO_Port,O5_Pin);}
					  //       break;
						//	}
		/*case 6 : {*/if((rxUnion.rxUnionBuffer.digitalOutputs & 0b00000100)>>2 ==1){
						HAL_GPIO_TogglePin(O6_GPIO_Port,O6_Pin);}
					      //   break;
						//	}
		/*case 7 : {*/if((rxUnion.rxUnionBuffer.digitalOutputs & 0b00000010)>>1 ==1){
			   	   	   HAL_GPIO_TogglePin(O7_GPIO_Port,O7_Pin);}
					  //       break;
						//	}
		/*case 8 : {*/if((rxUnion.rxUnionBuffer.digitalOutputs & 0b00000001)>>0 ==1){
			   	   	   HAL_GPIO_TogglePin(O8_GPIO_Port,O8_Pin);}
					  //       break;
						//	}

		//}
	//}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	//funciones para poner en el callback. Hablar con dani
	if (huart->Instance == USART1){
	 //se completo la recepcion, ahora a procesar datos y sacar por salida


		PWMCONTROL1(); //se llama a las funciones pwm mandando como parametro los valores recibidos de c1 y c2
		PWMCONTROL2();
		salidadigital();
		//vuelvo a pedir datos
		HAL_UART_Receive_IT(&huart1, (uint8_t*)&rxUnion,sizeof(rxUnion));

	}



}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

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


