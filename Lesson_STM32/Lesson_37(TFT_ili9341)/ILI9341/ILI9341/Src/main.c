/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "fatfs.h"
#include "usb_host.h"

/* USER CODE BEGIN Includes */
#include "main.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

RNG_HandleTypeDef hrng;

SRAM_HandleTypeDef hsram1;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
extern ApplicationTypeDef Appli_state;
extern uint16_t X_SIZE;
extern uint16_t Y_SIZE;
FATFS USBDISKFatFs;
FIL MyFile;
extern USBH_HandleTypeDef hUsbHostFS;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Error_Handler(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_FSMC_Init(void);
static void MX_RNG_Init(void);
void MX_USB_HOST_Process(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
//------------------------------------
__STATIC_INLINE void DelayMicro(uint32_t __IO micros)
{
	micros *=(SystemCoreClock/1000000)/5;
	while(micros--);
}
//------------------------------------
void FileReadWrite(void)
{
	uint8_t i=0;
	if(f_mount(&USBDISKFatFs,(TCHAR const*)USBH_Path,0)!=FR_OK)
	{
		Error_Handler();
	}
	else
	{
		while(1)
		{
			TFT9341_SetTextColor(YELLOW);
			TFT9341_SetBackColor(BLUE);
			TFT9341_SetFont(24);
			TFT9341_DrawChar(10,10,('S'));
			TFT9341_DrawChar(27,10,('t'));
			TFT9341_DrawChar(44,10,('m'));
			TFT9341_DrawChar(61,10,('3'));
			TFT9341_DrawChar(78,10,('2'));
			TFT9341_SetTextColor(GREEN);
			TFT9341_SetBackColor(RED);
			TFT9341_SetFont(20);
			TFT9341_DrawChar(10,34,('S'));
			TFT9341_DrawChar(24,34,('t'));
			TFT9341_DrawChar(38,34,('m'));
			TFT9341_DrawChar(52,34,('3'));
			TFT9341_DrawChar(66,34,('2'));
			TFT9341_SetTextColor(BLUE);
			TFT9341_SetBackColor(YELLOW);
			TFT9341_SetFont(16);
			TFT9341_DrawChar(10,54,('S'));
			TFT9341_DrawChar(21,54,('t'));
			TFT9341_DrawChar(32,54,('m'));
			TFT9341_DrawChar(43,54,('3'));
			TFT9341_DrawChar(54,54,('2'));
			TFT9341_SetTextColor(CYAN);
			TFT9341_SetBackColor(BLACK);
			TFT9341_SetFont(12);
			TFT9341_DrawChar(10,70,('S'));
			TFT9341_DrawChar(17,70,('t'));
			TFT9341_DrawChar(24,70,('m'));
			TFT9341_DrawChar(31,70,('3'));
			TFT9341_DrawChar(38,70,('2'));
			TFT9341_SetTextColor(RED);
			TFT9341_SetBackColor(GREEN);
			TFT9341_SetFont(8);
			TFT9341_DrawChar(10,82,('S'));
			TFT9341_DrawChar(15,82,('t'));
			TFT9341_DrawChar(20,82,('m'));
			TFT9341_DrawChar(25,82,('3'));
			TFT9341_DrawChar(30,82,('2'));
			TFT9341_SetTextColor(YELLOW);
			TFT9341_SetBackColor(BLUE);
			for(i=0;i<16;i++)
			{
				TFT9341_SetFont(24);
				TFT9341_FillScreen(BLACK);
				TFT9341_String(1,100,"ABCDEF12345678");
				TFT9341_SetFont(20);
				TFT9341_String(1,124,"ABCDEFGHI12345678");
				TFT9341_SetFont(16);
				TFT9341_String(1,144,"ABCDEFGHIKL123456789");
				TFT9341_SetFont(12);
				TFT9341_String(1,160,"ABCDEFGHIKLMNOPQRSTUVWXY 123456789");
				TFT9341_SetFont(8);
				TFT9341_String(1,172,"ABCDEFGHIKLMNOPQRSTUVWXYZ 123456789ABCDEFGHIKL");
				HAL_Delay(2000);
				TFT9341_SetRotation(i%4);
			}
			HAL_Delay(10000);
			TFT9341_FillScreen(BLACK);
			TFT9341_SetRotation(0);
			TFT9341_DrawBitmap(0,0,"001.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "002.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "003.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "004.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "005.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "006.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "007.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "008.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "009.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "010.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "011.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "012.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "013.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "014.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "015.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "016.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "017.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "018.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "019.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "020.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "021.bmp");
			HAL_Delay(5000);
			TFT9341_DrawBitmap(0, 0, "022.bmp");
			HAL_Delay(5000);
		}
	}
}
/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */
	//char str[100];
	uint16_t i,j;
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_FATFS_Init();
  MX_USB_HOST_Init();
  MX_FSMC_Init();
  MX_RNG_Init();

  /* USER CODE BEGIN 2 */
	LCD_ini();
	LCD_Clear();
	TFT9341_ini();
	for(i=0;i<20;i++)
	{
		TFT9341_FillScreen(TFT9341_RandColor());
		HAL_Delay(150);
	}
	TFT9341_FillScreen(BLACK);
	HAL_Delay(500);
	for(i=0;i<20;i++)
	{
		TFT9341_FillRect(TFT9341_RandColor(), 0, 0, X_SIZE/2-1, Y_SIZE/2-1);
		HAL_Delay(100);
		TFT9341_FillRect(TFT9341_RandColor(), X_SIZE/2, 0, X_SIZE-1, Y_SIZE/2-1);
		HAL_Delay(100);
		TFT9341_FillRect(TFT9341_RandColor(), 0, Y_SIZE/2, X_SIZE/2-1, Y_SIZE-1);
		HAL_Delay(100);
		TFT9341_FillRect(TFT9341_RandColor(), X_SIZE/2, Y_SIZE/2, X_SIZE-1, Y_SIZE-1);
		HAL_Delay(100);
	}
	TFT9341_FillScreen(BLACK);
	HAL_Delay(500);
	for(i=0;i<15000;i++)
	{
		TFT9341_DrawPixel(HAL_RNG_GetRandomNumber(&hrng)%X_SIZE,
											HAL_RNG_GetRandomNumber(&hrng)%Y_SIZE,
											TFT9341_RandColor());
		DelayMicro(100);
	}
	TFT9341_FillScreen(BLACK);
	HAL_Delay(500);
	for(j=0;j<20;j++)
	{
		for(i=0;i<X_SIZE;i++)
		{
	
			TFT9341_DrawLine(TFT9341_RandColor(),i,0,i,Y_SIZE-1);
		}
	}
	TFT9341_FillScreen(BLACK);
	HAL_Delay(500);
	for(i=0;i<1000;i++)
	{
			TFT9341_DrawLine(TFT9341_RandColor(),
											 HAL_RNG_GetRandomNumber(&hrng)%X_SIZE,
											 HAL_RNG_GetRandomNumber(&hrng)%Y_SIZE,
											 HAL_RNG_GetRandomNumber(&hrng)%X_SIZE,
											 HAL_RNG_GetRandomNumber(&hrng)%Y_SIZE);
			HAL_Delay(10);
	}
	TFT9341_FillScreen(BLACK);
	HAL_Delay(500);
	for(j=0;j<20;j++)
	{
		for(i=0;i<X_SIZE/2;i++)
		{
			TFT9341_DrawRect(TFT9341_RandColor(), i, i, X_SIZE-i-1, Y_SIZE-i-1);
		}
	}
	TFT9341_FillScreen(BLACK);
	HAL_Delay(500);
	for(i=0;i<2000;i++)
	{
		TFT9341_DrawCircle(HAL_RNG_GetRandomNumber(&hrng)%(X_SIZE-40)+20,
											 HAL_RNG_GetRandomNumber(&hrng)%(Y_SIZE-40)+20,
											 20,TFT9341_RandColor());
		HAL_Delay(3);
	}
	TFT9341_FillScreen(BLACK);
	HAL_Delay(500);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */
    MX_USB_HOST_Process();

  /* USER CODE BEGIN 3 */
		if(Appli_state==APPLICATION_START)
		{
			FileReadWrite();
		}
		else if(Appli_state==APPLICATION_IDLE)
		{
		}
	}	
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* I2C1 init function */
static void MX_I2C1_Init(void)
{

  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

}

/* RNG init function */
static void MX_RNG_Init(void)
{

  hrng.Instance = RNG;
  if (HAL_RNG_Init(&hrng) != HAL_OK)
  {
    Error_Handler();
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PD12 PD6 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* FSMC initialization function */
static void MX_FSMC_Init(void)
{
  FSMC_NORSRAM_TimingTypeDef Timing;
  FSMC_NORSRAM_TimingTypeDef ExtTiming;

  /** Perform the SRAM1 memory initialization sequence
  */
  hsram1.Instance = FSMC_NORSRAM_DEVICE;
  hsram1.Extended = FSMC_NORSRAM_EXTENDED_DEVICE;
  /* hsram1.Init */
  hsram1.Init.NSBank = FSMC_NORSRAM_BANK1;
  hsram1.Init.DataAddressMux = FSMC_DATA_ADDRESS_MUX_DISABLE;
  hsram1.Init.MemoryType = FSMC_MEMORY_TYPE_SRAM;
  hsram1.Init.MemoryDataWidth = FSMC_NORSRAM_MEM_BUS_WIDTH_8;
  hsram1.Init.BurstAccessMode = FSMC_BURST_ACCESS_MODE_DISABLE;
  hsram1.Init.WaitSignalPolarity = FSMC_WAIT_SIGNAL_POLARITY_LOW;
  hsram1.Init.WrapMode = FSMC_WRAP_MODE_DISABLE;
  hsram1.Init.WaitSignalActive = FSMC_WAIT_TIMING_BEFORE_WS;
  hsram1.Init.WriteOperation = FSMC_WRITE_OPERATION_ENABLE;
  hsram1.Init.WaitSignal = FSMC_WAIT_SIGNAL_DISABLE;
  hsram1.Init.ExtendedMode = FSMC_EXTENDED_MODE_ENABLE;
  hsram1.Init.AsynchronousWait = FSMC_ASYNCHRONOUS_WAIT_DISABLE;
  hsram1.Init.WriteBurst = FSMC_WRITE_BURST_DISABLE;
  hsram1.Init.PageSize = FSMC_PAGE_SIZE_NONE;
  /* Timing */
  Timing.AddressSetupTime = 2;
  Timing.AddressHoldTime = 15;
  Timing.DataSetupTime = 15;
  Timing.BusTurnAroundDuration = 15;
  Timing.CLKDivision = 16;
  Timing.DataLatency = 17;
  Timing.AccessMode = FSMC_ACCESS_MODE_A;
  /* ExtTiming */
  ExtTiming.AddressSetupTime = 2;
  ExtTiming.AddressHoldTime = 15;
  ExtTiming.DataSetupTime = 3;
  ExtTiming.BusTurnAroundDuration = 3;
  ExtTiming.CLKDivision = 16;
  ExtTiming.DataLatency = 17;
  ExtTiming.AccessMode = FSMC_ACCESS_MODE_A;

  if (HAL_SRAM_Init(&hsram1, &Timing, &ExtTiming) != HAL_OK)
  {
    Error_Handler();
  }

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
