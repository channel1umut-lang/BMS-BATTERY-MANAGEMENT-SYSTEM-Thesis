/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f3xx_it.c
  * @brief   Interrupt Service Routines.
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
#include "stm32f3xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

#define VREFIN_CAL ((uint16_t*) ((uint32_t) 0x1FFFF7BA))


extern	uint32_t	temp,temp1,temp2,temp3,temp4,temp5;


extern 	uint8_t 	adc_count;
extern	uint16_t adc1_value[4],adc2_value[2];

float bat1=0,bat2=0,bat3=0,bat4=0,bat5=0,bat6=0,bat7=0,bat8=0,bat9=0,bat10=0,bat11=0,bat12=0,
		bat13=0,bat14=0,bat15=0,bat16=0,bat17=0,bat18=0,bat19=0,bat20=0,vref=0,vdda=0;

extern	uint8_t adc1_okundu,adc2_okundu;
extern 	uint8_t count1,count2;
extern 	uint32_t adc1_buffer[10];
extern 	uint32_t adc2_buffer[10];
extern 	uint32_t adc3_buffer[15];
extern 	uint32_t adc4_buffer[10];
extern	uint8_t 	adc_saniye;
extern	int		bat1_int,
				bat2_int,
				bat3_int,
				bat4_int,
				bat5_int,
				bat6_int,
				bat7_int,
				bat8_int,
				bat9_int,
				bat10_int;

extern	float	pil1,pil1_,pil2,pil3,pil4,pil5,pil6,pil7,pil8,pil9,pil10;
extern float vort;

int bat1_a,bat1_c,bat1_d;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_adc1;
extern DMA_HandleTypeDef hdma_adc2;
extern DMA_HandleTypeDef hdma_adc3;
extern DMA_HandleTypeDef hdma_adc4;
extern TIM_HandleTypeDef htim1;
/* USER CODE BEGIN EV */
extern DMA_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hadc2;
extern DMA_HandleTypeDef hadc3;
extern DMA_HandleTypeDef hadc4;
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F3xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f3xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles DMA1 channel1 global interrupt.
  */
void DMA1_Channel1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel1_IRQn 0 */

  /* USER CODE END DMA1_Channel1_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_adc1);
  /* USER CODE BEGIN DMA1_Channel1_IRQn 1 */

  /* USER CODE END DMA1_Channel1_IRQn 1 */
}

/**
  * @brief This function handles TIM1 update and TIM16 interrupts.
  */
void TIM1_UP_TIM16_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_UP_TIM16_IRQn 0 */

  /* USER CODE END TIM1_UP_TIM16_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_UP_TIM16_IRQn 1 */

  /* USER CODE END TIM1_UP_TIM16_IRQn 1 */
}

/**
  * @brief This function handles DMA2 channel1 global interrupt.
  */
void DMA2_Channel1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Channel1_IRQn 0 */

  /* USER CODE END DMA2_Channel1_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_adc2);
  /* USER CODE BEGIN DMA2_Channel1_IRQn 1 */

  /* USER CODE END DMA2_Channel1_IRQn 1 */
}

/**
  * @brief This function handles DMA2 channel2 global interrupt.
  */
void DMA2_Channel2_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Channel2_IRQn 0 */

  /* USER CODE END DMA2_Channel2_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_adc4);
  /* USER CODE BEGIN DMA2_Channel2_IRQn 1 */

  /* USER CODE END DMA2_Channel2_IRQn 1 */
}

/**
  * @brief This function handles DMA2 channel5 global interrupt.
  */
void DMA2_Channel5_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Channel5_IRQn 0 */

  /* USER CODE END DMA2_Channel5_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_adc3);
  /* USER CODE BEGIN DMA2_Channel5_IRQn 1 */

  /* USER CODE END DMA2_Channel5_IRQn 1 */
}

/* USER CODE BEGIN 1 */


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{




	if(adc_saniye!=0){

		adc_saniye=0;

		vdda=(float)3.3*(*VREFIN_CAL)/adc1_buffer[3];
		vdda=vdda*0.963;


		bat1=(float)vdda/4095*adc1_buffer[0];
		bat2=(float)vdda/4095*adc1_buffer[1];
		bat3=(float)vdda/4095*adc1_buffer[2];
		bat4=(float)vdda/4095*adc2_buffer[0];
		bat5=(float)vdda/4095*adc2_buffer[1];
		bat6=(float)vdda/4095*adc2_buffer[2];
		bat7=(float)vdda/4095*adc2_buffer[3];
		bat8=(float)vdda/4095*adc2_buffer[4];
		bat9=(float)vdda/4095*adc2_buffer[5];
		bat10=(float)vdda/4095*adc3_buffer[0];
		/*bat11=(float)vdda/4095*adc3_buffer[1];
		bat12=(float)vdda/4095*adc3_buffer[2];
		bat13=(float)vdda/4095*adc3_buffer[3];
		bat14=(float)vdda/4095*adc3_buffer[4];
		bat15=(float)vdda/4095*adc3_buffer[5];
		bat16=(float)vdda/4095*adc3_buffer[6];
		bat17=(float)vdda/4095*adc3_buffer[7];
		bat18=(float)vdda/4095*adc3_buffer[8];
		bat19=(float)vdda/4095*adc4_buffer[0];
		bat20=(float)vdda/4095*adc4_buffer[1];
*/
		if(adc4_buffer[2]!=0){temp1=adc4_buffer[2]*(330.0/4095.0);}
		if(adc3_buffer[9]!=0){temp2=adc3_buffer[9]*(330.0/4095.0);}
		if(adc4_buffer[3]!=0){temp3=adc4_buffer[3]*(330.0/4095.0);}
		//if(adc4_buffer[4]!=0){temp4=adc4_buffer[4]*(330.0/4095.0);}
		//if(adc4_buffer[5]!=0){temp5=adc4_buffer[5]*(330.0/4095.0);}

__NOP();


	}

}
/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
