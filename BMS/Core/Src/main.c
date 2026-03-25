/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

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
ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc2;
ADC_HandleTypeDef hadc3;
ADC_HandleTypeDef hadc4;
DMA_HandleTypeDef hdma_adc1;
DMA_HandleTypeDef hdma_adc2;
DMA_HandleTypeDef hdma_adc3;
DMA_HandleTypeDef hdma_adc4;

TIM_HandleTypeDef htim1;

UART_HandleTypeDef huart1;

DMA_HandleTypeDef hdma_memtomem_dma1_channel2;
/* USER CODE BEGIN PV */
void	timer_100ms_islemleri(void);

uint32_t	temp,temp1=25,temp2=25,temp3=25,temp4=25,temp5=25,temp_ort,temprature;
uint8_t bak_temp=0;
extern 	uint8_t	timer_500ms,sayi;
extern	uint8_t	yarim_sayicisi;

extern	uint8_t 	adc_saniye;
void	adc_filtreleme	(void);
extern	uint8_t	timer_500ms,sayi;
extern	uint8_t	batarya_tetik;
extern	uint8_t 	adc_count;
extern	uint32_t adc1_buffer[10];
extern	uint32_t adc2_buffer[10];
extern	uint32_t adc3_buffer[15];
extern	uint32_t adc4_buffer[10];

extern	uint8_t 	countx1;
extern	uint8_t		countx2;
extern	uint8_t 	timer_saniye;
extern	uint8_t		saniye_dallanma_sayicisi;
extern	uint8_t		timer_200ms_islemleri;

extern	uint8_t batmsg1, batmsg2, batmsg3, batmsg4, batmsg5, batmsg6, batmsg7, batmsg8, batmsg9, batmsg10,
 	 	 	 batmsg11, batmsg12, batmsg13, batmsg14, batmsg15, batmsg16, batmsg17, batmsg18, batmsg19, batmsg20;

extern	float	bat1_top,bat1_ort,
				bat2_top,bat2_ort,
				bat3_top,bat3_ort,
				bat4_top,bat4_ort,
				bat5_top,bat5_ort,
				bat6_top,bat6_ort,
				bat7_top,bat7_ort,
				bat8_top,bat8_ort,
				bat9_top,bat9_ort,
				bat10_top,bat10_ort,
				bat11_top,bat11_ort,
				bat12_top,bat12_ort,
				bat13_top,bat13_ort,
				bat14_top,bat14_ort,
				bat15_top,bat15_ort,
				bat16_top,bat16_ort,
				bat17_top,bat17_ort,
				bat18_top,bat18_ort,
				bat19_top,bat19_ort,
				bat20_top,bat20_ort
				;
extern	float bat1_b,bat1_carp
					,bat2_carp
					,bat3_carp
					,bat4_carp
					,bat5_carp
					,bat6_carp
					,bat7_carp
					,bat8_carp
					,bat9_carp
					,bat10_carp
					,bat11_carp
					,bat12_carp
					,bat13_carp
					,bat14_carp
					,bat15_carp
					,bat16_carp
					,bat17_carp
					,bat18_carp
					,bat19_carp
					,bat20_carp;

uint8_t soc;
extern	float battery_ort,battery_toplam;
extern float bat1,bat2,bat3,bat4,bat5;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
static void MX_ADC2_Init(void);
static void MX_ADC3_Init(void);
static void MX_ADC4_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM1_Init(void);
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
	  uint8_t MSG[32] = {'\0'};
	  uint8_t X = 0;
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
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_ADC3_Init();
  MX_ADC4_Init();
  MX_USART1_UART_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim1);

  HAL_ADC_Start_DMA(&hadc1,adc1_buffer,4) ;
  HAL_ADC_Start_DMA(&hadc2,adc2_buffer,6) ;
  HAL_ADC_Start_DMA(&hadc3,adc3_buffer,10) ;
  HAL_ADC_Start_DMA(&hadc4,adc4_buffer,6) ;

  HAL_GPIO_WritePin(GPIOD, fan_tetik_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD, buzzer_tetik_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD,kontak_tetik_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin	(GPIOE, BAT1_TETIK_Pin , GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOE, BAT2_TETIK_Pin , GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOB, BAT3_TETIK_Pin , GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOB, BAT4_TETIK_Pin , GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOB, BAT5_TETIK_Pin , GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOB, BAT6_TETIK_Pin , GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOB, BAT7_TETIK_Pin , GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOB, BAT8_TETIK_Pin , GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOB, BAT9_TETIK_Pin , GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOD, BAT10_TETIK_Pin, GPIO_PIN_RESET);
 /* HAL_GPIO_WritePin	(GPIOD, BAT11_TETIK_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOD, BAT12_TETIK_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOD, BAT13_TETIK_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOD, BAT14_TETIK_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOD, BAT15_TETIK_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOD, BAT16_TETIK_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOD, BAT17_TETIK_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOC, BAT18_TETIK_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOC, BAT19_TETIK_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin	(GPIOC, BAT20_TETIK_Pin, GPIO_PIN_RESET);
*/
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

		if(saniye_dallanma_sayicisi==8)
		{
			saniye_dallanma_sayicisi=0;

			  HAL_GPIO_WritePin	(GPIOE, BAT1_TETIK_Pin , GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOE, BAT2_TETIK_Pin , GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOB, BAT3_TETIK_Pin , GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOB, BAT4_TETIK_Pin , GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOB, BAT5_TETIK_Pin , GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOB, BAT6_TETIK_Pin , GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOB, BAT7_TETIK_Pin , GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOB, BAT8_TETIK_Pin , GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOB, BAT9_TETIK_Pin , GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOD, BAT10_TETIK_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOD, BAT11_TETIK_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOD, BAT12_TETIK_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOD, BAT13_TETIK_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOD, BAT14_TETIK_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOD, BAT15_TETIK_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOD, BAT16_TETIK_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOD, BAT17_TETIK_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOC, BAT18_TETIK_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOC, BAT19_TETIK_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin	(GPIOC, BAT20_TETIK_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOC, Buz_led_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOD, buzzer_tetik_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOC, Fan_led_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOD, fan_tetik_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOC, Kontak_led_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOD, kontak_tetik_Pin, GPIO_PIN_RESET);

		}

		  if(saniye_dallanma_sayicisi==1)
		  {

				timer_saniye=0;

				adc_saniye=1;

				adc_filtreleme();


				bat1_carp=bat1_ort*1.421;
				bat2_carp=bat2_ort*1.420;
				bat3_carp=bat3_ort*1.414;
				bat4_carp=bat4_ort*1.396;
				bat5_carp=bat5_ort*1.431;
				bat6_carp=bat6_ort*1.431;
				bat7_carp=bat7_ort*1.421;
				bat8_carp=bat8_ort*1.439;
				bat9_carp=bat9_ort*1.424;
				bat10_carp=bat10_ort*1.410;
				bat11_carp=bat11_ort*1.413;
				bat12_carp=bat12_ort*1.350;
				bat13_carp=bat13_ort*1.436;
				bat14_carp=bat14_ort*1.410;
				bat15_carp=bat15_ort*1.427;
				bat16_carp=bat16_ort*1.390;
				bat17_carp=bat17_ort*1.413;
				bat18_carp=bat18_ort*1.373;
				bat19_carp=bat19_ort*1.403;
				bat20_carp=bat20_ort*1.385;


				battery_toplam=	bat1_carp+bat2_carp+bat3_carp+bat4_carp+bat5_carp+bat6_carp+bat7_carp+bat8_carp+bat9_carp+bat10_carp+
				bat11_carp+bat12_carp+bat13_carp+bat14_carp+bat15_carp+bat16_carp+bat17_carp+bat18_carp+bat19_carp+bat20_carp;

				battery_ort=battery_toplam/20;


		  }

		  if(saniye_dallanma_sayicisi==4)
		  {

	//		  if(bat1_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOE, BAT1_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat2_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOE, BAT2_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat3_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOB, BAT3_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat4_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOB, BAT4_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat5_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOB, BAT5_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat6_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOB, BAT6_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat7_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOB, BAT7_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat8_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOB, BAT8_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat9_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOB, BAT9_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat10_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOD, BAT10_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat11_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOD, BAT11_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat12_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOD, BAT12_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat13_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOD, BAT13_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat14_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOD, BAT14_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat15_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOD, BAT15_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat16_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOD, BAT16_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat17_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOD, BAT17_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat18_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOC, BAT18_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat19_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOC, BAT19_TETIK_Pin , GPIO_PIN_RESET);}
	//		  if(bat20_carp<=(battery_ort-0.03)){ HAL_GPIO_WritePin(GPIOC, BAT20_TETIK_Pin , GPIO_PIN_RESET);}


			  if(bat1_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOE, BAT1_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat2_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOE, BAT2_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat3_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOB, BAT3_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat4_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOB, BAT4_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat5_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOB, BAT5_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat6_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOB, BAT6_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat7_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOB, BAT7_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat8_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOB, BAT8_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat9_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOB, BAT9_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat10_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOD, BAT10_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat11_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOD, BAT11_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat12_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOD, BAT12_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat13_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOD, BAT13_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat14_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOD, BAT14_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat15_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOD, BAT15_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat16_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOD, BAT16_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat17_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOD, BAT17_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat18_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOC, BAT18_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat19_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOC, BAT19_TETIK_Pin , GPIO_PIN_SET);}
			  if(bat20_carp>(battery_ort+0.06)){ HAL_GPIO_WritePin(GPIOC, BAT20_TETIK_Pin , GPIO_PIN_SET);}





			  temp_ort=(temp1+temp2+temp3+temp4+temp5)/5;

			  bak_temp++;
			  temp+=temp_ort;
			  if(bak_temp>5)
			  {
				  bak_temp=0;
				  temprature=temp/5;
				  temp=0;

			  }





			  if(temp3>35)
			  {

				  HAL_GPIO_WritePin(GPIOC, Buz_led_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOD, buzzer_tetik_Pin, GPIO_PIN_SET);
			  }
			  if(temp3>55)
		  {
			  HAL_GPIO_WritePin(GPIOC, Fan_led_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GPIOD, fan_tetik_Pin, GPIO_PIN_SET);
		  }
//		  if(temp3>120)
//		  {
//				  HAL_GPIO_WritePin(GPIOC, Kontak_led_Pin, GPIO_PIN_SET);
//				  HAL_GPIO_WritePin(GPIOD, kontak_tetik_Pin, GPIO_PIN_SET);
//			  }




			//  HAL_GPIO_WritePin(GPIOE, led_red_Pin, GPIO_PIN_SET);

			//  HAL_GPIO_WritePin(GPIOE, led_green_Pin, GPIO_PIN_SET);



			  batmsg1 = bat1_carp*100/2;//uratta yaptigimiz haberllesme 8 bit. Bat1_carp=3.67*100/2=183 = 8 bit deger araliginda.
			  batmsg2 = bat2_carp*100/2;
			  batmsg3 = bat3_carp*100/2;
			  batmsg4 = bat4_carp*100/2;
			  batmsg5 = bat5_carp*100/2;
			  batmsg6 = bat6_carp*100/2;
			  batmsg7 = bat7_carp*100/2;
			  batmsg8 = bat8_carp*100/2;
			  batmsg9 = bat9_carp*100/2;
			  batmsg10 = bat10_carp*100/2;
			  batmsg11 = bat11_carp*100/2;
			  batmsg12 = bat12_carp*100/2;
			  batmsg13 = bat13_carp*100/2;
			  batmsg14 = bat14_carp*100/2;
			  batmsg15 = bat15_carp*100/2;
			  batmsg16 = bat16_carp*100/2;
			  batmsg17 = bat17_carp*100/2;
			  batmsg18 = bat18_carp*100/2;
			  batmsg19 = bat19_carp*100/2;
			  batmsg20 = bat20_carp*100/2;




			  MSG[0] =  0x47;	//
			  MSG[1] =  0x47;	//
			  MSG[2] =  batmsg1;
			  MSG[3] =  batmsg2;
			  MSG[4] =  batmsg3;
			  MSG[5] =  batmsg4;
			  MSG[6] =  batmsg5;
			  MSG[7] =  batmsg6;
			  MSG[8] =  batmsg7;
			  MSG[9] =  batmsg8;
			  MSG[10] = batmsg9;
			  MSG[11] = batmsg10;
			  MSG[12] = batmsg11;
			  MSG[13] = batmsg12;
			  MSG[14] = batmsg13;
			  MSG[15] = batmsg14;
			  MSG[16] = batmsg15;
			  MSG[17] = batmsg16;
			  MSG[18] = batmsg17;
			  MSG[19] = batmsg18;
			  MSG[20] = batmsg19;
			  MSG[21] = batmsg20;
			  MSG[22] = temp1;
			  MSG[23] = temp2;
			  MSG[24] = temp3;
			  MSG[25] = temp4;
			  MSG[26] = temp5;
			  MSG[27] = soc;
			  MSG[28] = battery_toplam;
			  MSG[29] = 0x25	+	X;
			  MSG[30] = 0x26	+	X;
			  MSG[31] = 0x27	+	X;
			  MSG[32] = X;

			     HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
			     HAL_Delay(75);

			     X++;
			     if(X == 47) X = 0;

		  }


		  if(timer_500ms==1)
		  {

			  timer_500ms=0;

			  if(battery_toplam>=84)soc=100;
			  		  if((battery_toplam>=83)  && (battery_toplam<84))soc=96;
			  		  if((battery_toplam>=82)  && (battery_toplam<83))soc=92;
			  		  if((battery_toplam>=81)  && (battery_toplam<82))soc=88;
			  		  if((battery_toplam>=80)  && (battery_toplam<81))soc=84;
			  		  if((battery_toplam>=79)  && (battery_toplam<80))soc=80;
			  		  if((battery_toplam>=78)  && (battery_toplam<79))soc=76;
			  		  if((battery_toplam>=77)  && (battery_toplam<78))soc=72;
			  		  if((battery_toplam>=76)  && (battery_toplam<77))soc=68;
			  		  if((battery_toplam>=75)  && (battery_toplam<76))soc=64;
			  		  if((battery_toplam>=74)  && (battery_toplam<75))soc=60;
			  		  if((battery_toplam>=73)  && (battery_toplam<74))soc=56;
			  		  if((battery_toplam>=72)  && (battery_toplam<73))soc=52;
			  		  if((battery_toplam>=71)  && (battery_toplam<72))soc=48;
			  		  if((battery_toplam>=70)  && (battery_toplam<71))soc=44;
			  		  if((battery_toplam>=69)  && (battery_toplam<70))soc=40;
			  		  if((battery_toplam>=68)  && (battery_toplam<69))soc=36;
			  		  if((battery_toplam>=67)  && (battery_toplam<68))soc=32;
			  		  if((battery_toplam>=66)  && (battery_toplam<67))soc=28;
			  		  if((battery_toplam>=65)  && (battery_toplam<66))soc=24;
			  		  if((battery_toplam>=64)  && (battery_toplam<65))soc=20;
			  		  if((battery_toplam>=63)  && (battery_toplam<64))soc=16;
			  		  if((battery_toplam>=62)  && (battery_toplam<63))soc=12;
			  		  if((battery_toplam>=61)  && (battery_toplam<62))soc=8;
			  		  if((battery_toplam>=60)  && (battery_toplam<61))soc=4;
			  		  if((battery_toplam>=59)  && (battery_toplam<60))soc=0;

	/*


			  sayi++;
			  if(sayi>3)sayi=0;

			  if(sayi==0)
			  {
				  HAL_GPIO_WritePin(GPIOE, led_blue_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOE, led_red_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOE, led_green_Pin, GPIO_PIN_RESET);

			  }
			  if(sayi==1)
			  {
				  HAL_GPIO_WritePin(GPIOE, led_blue_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOE, led_red_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOE, led_green_Pin, GPIO_PIN_RESET);
			  }
			  if(sayi==2)
			  {
				  HAL_GPIO_WritePin(GPIOE, led_blue_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOE, led_red_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOE, led_green_Pin, GPIO_PIN_SET);
			  }
			  if(sayi==3)
			  {
				  HAL_GPIO_WritePin(GPIOE, led_blue_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOE, led_red_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOE, led_green_Pin, GPIO_PIN_SET);
			  }
	*/
		  }

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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_TIM1
                              |RCC_PERIPHCLK_ADC12|RCC_PERIPHCLK_ADC34;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInit.Adc12ClockSelection = RCC_ADC12PLLCLK_DIV8;
  PeriphClkInit.Adc34ClockSelection = RCC_ADC34PLLCLK_DIV8;
  PeriphClkInit.Tim1ClockSelection = RCC_TIM1CLK_HCLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 4;
  hadc1.Init.DMAContinuousRequests = ENABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.SamplingTime = ADC_SAMPLETIME_181CYCLES_5;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_5;
  sConfig.Rank = ADC_REGULAR_RANK_3;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_VREFINT;
  sConfig.Rank = ADC_REGULAR_RANK_4;
  sConfig.SamplingTime = ADC_SAMPLETIME_601CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief ADC2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC2_Init(void)
{

  /* USER CODE BEGIN ADC2_Init 0 */

  /* USER CODE END ADC2_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC2_Init 1 */

  /* USER CODE END ADC2_Init 1 */
  /** Common config
  */
  hadc2.Instance = ADC2;
  hadc2.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc2.Init.Resolution = ADC_RESOLUTION_12B;
  hadc2.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc2.Init.ContinuousConvMode = ENABLE;
  hadc2.Init.DiscontinuousConvMode = DISABLE;
  hadc2.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc2.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc2.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc2.Init.NbrOfConversion = 6;
  hadc2.Init.DMAContinuousRequests = ENABLE;
  hadc2.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc2.Init.LowPowerAutoWait = DISABLE;
  hadc2.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
  if (HAL_ADC_Init(&hadc2) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.SamplingTime = ADC_SAMPLETIME_181CYCLES_5;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = ADC_REGULAR_RANK_3;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = ADC_REGULAR_RANK_4;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_5;
  sConfig.Rank = ADC_REGULAR_RANK_5;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_11;
  sConfig.Rank = ADC_REGULAR_RANK_6;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC2_Init 2 */

  /* USER CODE END ADC2_Init 2 */

}

/**
  * @brief ADC3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC3_Init(void)
{

  /* USER CODE BEGIN ADC3_Init 0 */

  /* USER CODE END ADC3_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC3_Init 1 */

  /* USER CODE END ADC3_Init 1 */
  /** Common config
  */
  hadc3.Instance = ADC3;
  hadc3.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc3.Init.Resolution = ADC_RESOLUTION_12B;
  hadc3.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc3.Init.ContinuousConvMode = ENABLE;
  hadc3.Init.DiscontinuousConvMode = DISABLE;
  hadc3.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc3.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc3.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc3.Init.NbrOfConversion = 10;
  hadc3.Init.DMAContinuousRequests = ENABLE;
  hadc3.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc3.Init.LowPowerAutoWait = DISABLE;
  hadc3.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
  if (HAL_ADC_Init(&hadc3) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc3, &multimode) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_12;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.SamplingTime = ADC_SAMPLETIME_181CYCLES_5;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_13;
  sConfig.Rank = ADC_REGULAR_RANK_3;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_6;
  sConfig.Rank = ADC_REGULAR_RANK_4;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = ADC_REGULAR_RANK_5;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_14;
  sConfig.Rank = ADC_REGULAR_RANK_6;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_15;
  sConfig.Rank = ADC_REGULAR_RANK_7;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_16;
  sConfig.Rank = ADC_REGULAR_RANK_8;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = ADC_REGULAR_RANK_9;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_5;
  sConfig.Rank = ADC_REGULAR_RANK_10;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC3_Init 2 */

  /* USER CODE END ADC3_Init 2 */

}

/**
  * @brief ADC4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC4_Init(void)
{

  /* USER CODE BEGIN ADC4_Init 0 */

  /* USER CODE END ADC4_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC4_Init 1 */

  /* USER CODE END ADC4_Init 1 */
  /** Common config
  */
  hadc4.Instance = ADC4;
  hadc4.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc4.Init.Resolution = ADC_RESOLUTION_12B;
  hadc4.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc4.Init.ContinuousConvMode = ENABLE;
  hadc4.Init.DiscontinuousConvMode = DISABLE;
  hadc4.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc4.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc4.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc4.Init.NbrOfConversion = 6;
  hadc4.Init.DMAContinuousRequests = ENABLE;
  hadc4.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc4.Init.LowPowerAutoWait = DISABLE;
  hadc4.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
  if (HAL_ADC_Init(&hadc4) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.SamplingTime = ADC_SAMPLETIME_181CYCLES_5;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc4, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc4, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = ADC_REGULAR_RANK_3;
  if (HAL_ADC_ConfigChannel(&hadc4, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = ADC_REGULAR_RANK_4;
  if (HAL_ADC_ConfigChannel(&hadc4, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_5;
  sConfig.Rank = ADC_REGULAR_RANK_5;
  if (HAL_ADC_ConfigChannel(&hadc4, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_12;
  sConfig.Rank = ADC_REGULAR_RANK_6;
  if (HAL_ADC_ConfigChannel(&hadc4, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC4_Init 2 */

  /* USER CODE END ADC4_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 63999;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 99;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * Enable DMA controller clock
  * Configure DMA for memory to memory transfers
  *   hdma_memtomem_dma1_channel2
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* Configure DMA request hdma_memtomem_dma1_channel2 on DMA1_Channel2 */
  hdma_memtomem_dma1_channel2.Instance = DMA1_Channel2;
  hdma_memtomem_dma1_channel2.Init.Direction = DMA_MEMORY_TO_MEMORY;
  hdma_memtomem_dma1_channel2.Init.PeriphInc = DMA_PINC_ENABLE;
  hdma_memtomem_dma1_channel2.Init.MemInc = DMA_MINC_ENABLE;
  hdma_memtomem_dma1_channel2.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
  hdma_memtomem_dma1_channel2.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
  hdma_memtomem_dma1_channel2.Init.Mode = DMA_NORMAL;
  hdma_memtomem_dma1_channel2.Init.Priority = DMA_PRIORITY_MEDIUM;
  if (HAL_DMA_Init(&hdma_memtomem_dma1_channel2) != HAL_OK)
  {
    Error_Handler( );
  }

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
  /* DMA2_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Channel1_IRQn);
  /* DMA2_Channel2_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Channel2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Channel2_IRQn);
  /* DMA2_Channel5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Channel5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Channel5_IRQn);

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
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, led_green_Pin|led_red_Pin|led_blue_Pin|BAT2_TETIK_Pin
                          |BAT1_TETIK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, buzzer_tetik_Pin|fan_tetik_Pin|kontak_tetik_Pin|BAT17_TETIK_Pin
                          |BAT16_TETIK_Pin|BAT15_TETIK_Pin|BAT14_TETIK_Pin|BAT13_TETIK_Pin
                          |BAT12_TETIK_Pin|BAT11_TETIK_Pin|BAT10_TETIK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, Buz_led_Pin|Fan_led_Pin|Kontak_led_Pin|BAT20_TETIK_Pin
                          |BAT19_TETIK_Pin|BAT18_TETIK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, BAT9_TETIK_Pin|BAT8_TETIK_Pin|BAT7_TETIK_Pin|BAT6_TETIK_Pin
                          |BAT5_TETIK_Pin|BAT4_TETIK_Pin|BAT3_TETIK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : led_green_Pin led_red_Pin led_blue_Pin BAT2_TETIK_Pin
                           BAT1_TETIK_Pin */
  GPIO_InitStruct.Pin = led_green_Pin|led_red_Pin|led_blue_Pin|BAT2_TETIK_Pin
                          |BAT1_TETIK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : buzzer_tetik_Pin fan_tetik_Pin kontak_tetik_Pin BAT17_TETIK_Pin
                           BAT16_TETIK_Pin BAT15_TETIK_Pin BAT14_TETIK_Pin BAT13_TETIK_Pin
                           BAT12_TETIK_Pin BAT11_TETIK_Pin BAT10_TETIK_Pin */
  GPIO_InitStruct.Pin = buzzer_tetik_Pin|fan_tetik_Pin|kontak_tetik_Pin|BAT17_TETIK_Pin
                          |BAT16_TETIK_Pin|BAT15_TETIK_Pin|BAT14_TETIK_Pin|BAT13_TETIK_Pin
                          |BAT12_TETIK_Pin|BAT11_TETIK_Pin|BAT10_TETIK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : Buz_led_Pin Fan_led_Pin Kontak_led_Pin BAT20_TETIK_Pin
                           BAT19_TETIK_Pin BAT18_TETIK_Pin */
  GPIO_InitStruct.Pin = Buz_led_Pin|Fan_led_Pin|Kontak_led_Pin|BAT20_TETIK_Pin
                          |BAT19_TETIK_Pin|BAT18_TETIK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : BAT9_TETIK_Pin BAT8_TETIK_Pin BAT7_TETIK_Pin BAT6_TETIK_Pin
                           BAT5_TETIK_Pin BAT4_TETIK_Pin BAT3_TETIK_Pin */
  GPIO_InitStruct.Pin = BAT9_TETIK_Pin|BAT8_TETIK_Pin|BAT7_TETIK_Pin|BAT6_TETIK_Pin
                          |BAT5_TETIK_Pin|BAT4_TETIK_Pin|BAT3_TETIK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){

	if(htim->Instance==TIM1){

		saniye_dallanma_sayicisi++;


		yarim_sayicisi++;
		if(yarim_sayicisi>4)
		{
			yarim_sayicisi=0;
			timer_500ms=1;
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
