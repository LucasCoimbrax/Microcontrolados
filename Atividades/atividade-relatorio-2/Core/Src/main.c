/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "button.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
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
  uint32_t i;
  uint32_t lendo = 1;
  uint16_t existe_objeto = 0;
  uint16_t nao_existe_objeto = 0;
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    if( button_release( GPIOA, GPIO_PIN_5, 0) )
    {

      HAL_GPIO_WritePin( GPIOA, TRIGGER_Pin, 1);
      HAL_Delay(10);
      HAL_GPIO_WritePin( GPIOA, TRIGGER_Pin, 0);

      while ( lendo == 1)
      {
        if( HAL_GPIO_ReadPin( GPIOA, ECHO_Pin ) == 1)
        {
          HAL_GPIO_WritePin( GPIOB, GPIO_PIN_4, 1 );
          HAL_GPIO_WritePin( GPIOB, GPIO_PIN_5, 1 );
          lendo = 0;
        } 
        else
        {
          HAL_GPIO_WritePin( GPIOB, GPIO_PIN_3, 1 );

          if( button_release( GPIOA, GPIO_PIN_5, 0) )
          {
            lendo = 0;
            HAL_GPIO_WritePin( GPIOB, GPIO_PIN_3, 0 );
          }
        }
      }
      lendo = 1;

      HAL_GPIO_WritePin( GPIOB, GPIO_PIN_4, 0 );
      HAL_GPIO_WritePin( GPIOB, GPIO_PIN_5, 0 );

      HAL_Delay(1000);

    // if( button_release( GPIOA, GPIO_PIN_5, 0) )
    // {

    //   HAL_GPIO_WritePin( GPIOB, GPIO_PIN_4, 0 );
    //   HAL_GPIO_WritePin( GPIOB, GPIO_PIN_3, 0 );

    //   HAL_GPIO_WritePin( GPIOA, GPIO_PIN_7, 1);
    //   HAL_Delay(30);
    //   HAL_GPIO_WritePin( GPIOA, GPIO_PIN_7, 0);

    //   while ( lendo )
    //   {
    //     if( HAL_GPIO_ReadPin( GPIOA, GPIO_PIN_6 ) )
    //     {
    //       HAL_GPIO_WritePin( GPIOB, GPIO_PIN_4, 1 );
    //       HAL_GPIO_WritePin( GPIOB, GPIO_PIN_5, 1 );
    //       lendo--;
    //     } 
    //     else
    //     {
    //       HAL_GPIO_WritePin( GPIOB, GPIO_PIN_3, 1 );

    //       if( button_release( GPIOA, GPIO_PIN_5, 0) )
    //       {
    //         lendo--;
    //       }
    //     }
    //   }
    //   lendo++;

      
      
    }
      

      // if( HAL_GPIO_ReadPin( GPIOA, GPIO_PIN_6) )
      // {
      //   HAL_GPIO_WritePin( GPIOB, LED_PERTO_Pin, 0);
      //   HAL_GPIO_WritePin( GPIOB, LED_LONGE_1_Pin, 1);
      //   HAL_GPIO_WritePin( GPIOB, LED_LONGE_2_Pin, 1);
      // } else {
      //   HAL_GPIO_WritePin( GPIOB, LED_PERTO_Pin, 1);
      //   HAL_GPIO_WritePin( GPIOB, LED_LONGE_1_Pin, 0);
      //   HAL_GPIO_WritePin( GPIOB, LED_LONGE_2_Pin, 0);
      // }
    

    // HAL_GPIO_WritePin( GPIOA, TRIGGER_Pin, 1);
    // HAL_Delay(120);
    // HAL_GPIO_WritePin( GPIOA, TRIGGER_Pin, 0);


    // if( HAL_GPIO_ReadPin( GPIOA, ECHO_Pin) )
    // {
    //   HAL_GPIO_WritePin( GPIOB, LED_PERTO_Pin, 1);
    // } else {
    //   HAL_GPIO_WritePin( GPIOB, LED_PERTO_Pin, 0);
    // }


    // if( button_release( GPIOA, GPIO_PIN_5, 0) )
    // {
    //   HAL_GPIO_TogglePin( GPIOA, TRIGGER_Pin);

    //   if( !HAL_GPIO_ReadPin( GPIOA, ECHO_Pin) )
    //   {
    //     HAL_GPIO_WritePin( GPIOB, LED_PERTO_Pin, 1);
    //   } else {
    //     HAL_GPIO_WritePin( GPIOB, LED_PERTO_Pin, 0);
    //   }
    // }

      // if( !HAL_GPIO_ReadPin( GPIOA, ECHO_Pin) )
      // {
      //   HAL_GPIO_WritePin( GPIOB, LED_LONGE_1_Pin, 0);
      //   HAL_GPIO_WritePin( GPIOB, LED_LONGE_2_Pin, 0);

      //   HAL_GPIO_WritePin( GPIOB, LED_PERTO_Pin, 1);

      //   nao_existe_objeto++;
      // } 
      // else 
      // {
      //   HAL_GPIO_WritePin( GPIOB, LED_PERTO_Pin, 0);

      //   HAL_GPIO_WritePin( GPIOB, LED_LONGE_1_Pin, 1);
      //   HAL_GPIO_WritePin( GPIOB, LED_LONGE_2_Pin, 1);

      //   existe_objeto++;
      // }    

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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(KIT_LED_GPIO_Port, KIT_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(TRIGGER_GPIO_Port, TRIGGER_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_PERTO_Pin|LED_LONGE_1_Pin|LED_LONGE_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : KIT_LED_Pin */
  GPIO_InitStruct.Pin = KIT_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(KIT_LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : BUTTON_Pin ECHO_Pin */
  GPIO_InitStruct.Pin = BUTTON_Pin|ECHO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : TRIGGER_Pin */
  GPIO_InitStruct.Pin = TRIGGER_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(TRIGGER_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_PERTO_Pin LED_LONGE_1_Pin LED_LONGE_2_Pin */
  GPIO_InitStruct.Pin = LED_PERTO_Pin|LED_LONGE_1_Pin|LED_LONGE_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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