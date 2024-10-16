/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#define byte unsigned int
#define bit int
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

const uint16_t pins = { GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_8, GPIO_PIN_9 };

const int Logo122[4][122]=//122x32 pixel, каждые 8 вертикальных точек собраны в байт
	{
		{	0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00
		},
		{	0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00
		},
		{	0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00
		},
		{	0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
			0x0E,0x11,0x21,0x42,0x84,0x42,0x21,0x11,0x0E,0x00
		}
	};

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

int get_nth_bit(int by, int n) {
	unsigned int mask = 1 << n;
	return by & mask;
}

// Процедура выдачи байта в индикатор
void write_byte_lcd_indic(byte b, bit cd, bit lr) {
	// RW IS ALWAYS GROUNDED
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, cd); //Выдача байта в индикатор как данных или команды LCD_A0
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, lr); // LCD.D=b; //Выбрать кристалл индикатора и выдать байт на шину данных индикатора

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, get_nth_bit(b, 0));
	auto readpin = get_nth_bit(b, 0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, get_nth_bit(b, 1));
	readpin = get_nth_bit(b, 1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, get_nth_bit(b, 2));
	readpin = get_nth_bit(b, 2);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, get_nth_bit(b, 3));
	readpin = get_nth_bit(b, 3);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, get_nth_bit(b, 4));
	readpin = get_nth_bit(b, 4);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, get_nth_bit(b, 5));
	readpin = get_nth_bit(b, 5);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, get_nth_bit(b, 6));
	readpin = get_nth_bit(b, 6);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, get_nth_bit(b, 7));
	readpin = get_nth_bit(b, 7);

	HAL_Delay(2);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 0);
	HAL_Delay(2);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 1);
	HAL_Delay(2);
}

byte read_byte_lcd_indic(bit cd, bit lr) {
byte b;
//При необходимости настроить здесь шину данных на ввод
	write_byte_lcd_indic(0xE0, 0, lr); // LCD.RW=1;
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, cd); // LCD.A0=cd;
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, lr); // LCD.CS=lr;		//Выбрать нужный кристалл индикатора
	HAL_Delay(1);		//Это время предустановки адреса (tAW)
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 0); // LCD.E=0;
	HAL_Delay(1);	//Минимально допустимая длительность сигнала E=0 (время доступа (tACC) попало сюда)
  b = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) << 0;
  b = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1) << 1;
  b = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2) << 2;
  b = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3) << 3;
  b = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4) << 4;
  b = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5) << 5;
  b = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6) << 6;
  b = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) << 7;
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 1); // LCD.E=1;		//Сбросить сигнал E индикатору
	HAL_Delay(1);	//Минимально допустимый интервал между сигналами E=0

	write_byte_lcd_indic(0xEE, 0, lr); // LCD.RW = 0;

	return b;		//Вернуть прочитанный байт
}

void write_code_l(byte b) { write_byte_lcd_indic(b, 0, 1); }
void write_code_r(byte b) { write_byte_lcd_indic(b, 0, 0); }

void write_data_l(byte b) { write_byte_lcd_indic(b, 1, 1); }
void write_data_r(byte b) { write_byte_lcd_indic(b, 1, 0); }

byte read_data_l(void) { return read_byte_lcd_indic(1,1); }
byte read_data_r(void) { return read_byte_lcd_indic(1,0); }

byte read_status_l(void) { return read_byte_lcd_indic(0,1); }
byte read_status_r(void) { return read_byte_lcd_indic(0,0); }

void point_set(byte x, byte y, bit c) {//Записать одну точку в индикатор (координата 0,0 в левом верхнем углу индикатора)
byte c8;//Временное хранение считаного из индикатора байта
byte m8;//Маска нужного бита в байте
	if ((x>121)||(y>31)) return;//Выход за пределы индикатора
	if (x<61) {//Выводить в левую половину индикатора
		write_code_l(0xB8|(y>>3));//Установить нужную страницу индикатора
		write_code_l(0x13+x);//Установить адрес нужного байта
		c8=ReadDataL();//Фиктивное чтение
		c8=ReadDataL();//Чтение нужного байта из индикатора
		m8=1<<(y&0x07);//Вычислить маску нужного бита в байте
		if (c==1) {	//Зажигать точку?
			c8|=m8; //Установить нужный бит в байте
		}
		else	{	//Или гасить точку?
			c8&=~m8;//Сбросить нужный бит в байте
		}
		write_code_l(0x13+x);//Снова установить адрес нужного байта
		write_data_l(c8);//Записать изменённый байт обратно в индикатор
	} else {//Выводить в правую половину индикатора
		write_code_r(0xB8|(y>>3));//Установить нужную страницу индикатора
		write_code_r(x-61);//Установить адрес нужного байта
		c8=ReadDataR();//Фиктивное чтение
		c8=ReadDataR();//Чтение нужного байта из индикатора
		m8=1<<(y&0x07);//Вычислить маску нужного бита в байте
		if (c==1) { c8|=m8; }//Установить нужный бит в байте
		else { c8&=~m8; }//Сбросить нужный бит в байте
		write_code_r(x-61);//Снова установить адрес нужного байта
		write_data_r(c8);//Записать изменённый байт обратно в индикатор
	}
}

void draw() {
	byte	p;//Номер текущей страницы индикатора
	byte	c;//Позиция по горизонтали выводимого байта
	/*
	write_data_l(0xFF);
	write_data_r(0xFF);
	write_data_l(0xFF);
	write_data_r(0xFF);
	write_data_l(0xFF);
	write_data_r(0xFF);
	write_data_l(0xFF);
	write_data_r(0xFF);
	*/
	for(p=0; p<4; p++) {//Цикл по всем 4-м страницам индикатора
		write_code_l(p|0xB8);//Установка текущей страницы для левого кристалла индикатора
		write_code_l(0x13);//Установка текущего адреса для записи данных в левую отображаемую позицию левой половины индикатора
		for(c=0; c<61; c++) {//Цикл вывода данных в левую половину индикатора
			write_data_l(Logo122[p][c]);//Вывод очередного байта в индикатор
		}
		write_code_r(p|0xB8);//Установка текущей страницы для правого кристалла индикатора
		write_code_r(0x00);//Установка текущего адреса для записи данных в левую отображаемую позицию правой половины индикатора
		for(c=61; c<122; c++) {//Цикл вывода данных в правую половину индикатора
			write_data_r(Logo122[p][c]);//Вывод очередного байта в индикатор
		}
	}
}


/*
 * Для начальной установки индикатора необходимо выполнить следующие действия:
1. после подачи напряжения питания удерживать вывод RES в состоянии логического “0” еще не менее 10 мкс;
2. подать перепад на вывод RES c логического “0” в логическую “1”, длительность фронта не более 10 мкс;
3. ожидать сброса бита RESET в байте состояния или выждать не менее 2 мс;
4. подать команду снятия флага RMW (END);
5. подать команду включения обычного режима работы (Static Drive ON/OFF);
6. подать команду выбора мультиплекса (Duty Select);
7. подать команду включения дисплея (Display ON/OFF).
 *
 */
void lcd_init() {
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 1); // Начальное значение сигнала индикатору LCD_E
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, 0); // LSD_RES
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, 1); //Снять сигнал RES
	HAL_Delay(2);

	// RESET CMD
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0); // LCD_A to 0
//	write_code_l(0xE2);
//	write_code_r(0xE2);

	// RMW OFF
	write_code_l(0xEE);
	write_code_r(0xEE);

	// Static drive ON
	write_code_l(0xA4);
	write_code_r(0xA4);

	// Duty select
	write_code_l(0xA9);//Мультиплекс 1/32
	write_code_r(0xA9);//Мультиплекс 1/32

	// check display on
//	volatile auto state_l = read_status_l();
//	volatile auto state_r = read_status_r();

	HAL_Delay(1);

	// Set display start line
	write_code_l(0xC0);
	write_code_r(0xC0);

//	// Set page
//	write_code_l(0x5C);
//	write_code_r(0x5C);
//
//	// Set column
//	write_code_l(0);
//	write_code_r(0);

	// Display ON
	write_code_l(0xAF);
	write_code_r(0xAF);

	// ADC select right
	write_code_l(0xA1);
	write_code_r(0xA0);

	volatile auto state_l = read_status_l();
	volatile auto state_r = read_status_r();

	// ====== DRAW ======

	// Write data
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1); // LCD_A to 1
	HAL_Delay(2);
	draw();
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0); // LCD_A to 1

}

void on_click_turn_on_display()
{
	/*
	 * paster before loop
	   volatile int check = 0;
  volatile readpin1 = HAL_GPIO_ReadPin( GPIOC, GPIO_PIN_2);
  uint8_t tx_buff[]={0,1,2,3,4,5,6,7,8,9};

	 */
  if(HAL_GPIO_ReadPin( GPIOB, GPIO_PIN_2)) {
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

  } else {
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
  }
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

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
    /* USER CODE END WHILE */
	  if(!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2)) {
		  // LED ON
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, SET);
		  // LCD ON
		  lcd_init();
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_5;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
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
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC0 PC1 PC2 PC3
                           PC4 PC5 PC6 PC7
                           PC9 PC10 PC11 PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB2 */
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
