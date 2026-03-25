/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

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
#define led_green_Pin GPIO_PIN_2
#define led_green_GPIO_Port GPIOE
#define led_red_Pin GPIO_PIN_3
#define led_red_GPIO_Port GPIOE
#define led_blue_Pin GPIO_PIN_4
#define led_blue_GPIO_Port GPIOE
#define buzzer_tetik_Pin GPIO_PIN_13
#define buzzer_tetik_GPIO_Port GPIOD
#define fan_tetik_Pin GPIO_PIN_14
#define fan_tetik_GPIO_Port GPIOD
#define kontak_tetik_Pin GPIO_PIN_15
#define kontak_tetik_GPIO_Port GPIOD
#define Buz_led_Pin GPIO_PIN_6
#define Buz_led_GPIO_Port GPIOC
#define Fan_led_Pin GPIO_PIN_7
#define Fan_led_GPIO_Port GPIOC
#define Kontak_led_Pin GPIO_PIN_8
#define Kontak_led_GPIO_Port GPIOC
#define BAT20_TETIK_Pin GPIO_PIN_10
#define BAT20_TETIK_GPIO_Port GPIOC
#define BAT19_TETIK_Pin GPIO_PIN_11
#define BAT19_TETIK_GPIO_Port GPIOC
#define BAT18_TETIK_Pin GPIO_PIN_12
#define BAT18_TETIK_GPIO_Port GPIOC
#define BAT17_TETIK_Pin GPIO_PIN_0
#define BAT17_TETIK_GPIO_Port GPIOD
#define BAT16_TETIK_Pin GPIO_PIN_1
#define BAT16_TETIK_GPIO_Port GPIOD
#define BAT15_TETIK_Pin GPIO_PIN_2
#define BAT15_TETIK_GPIO_Port GPIOD
#define BAT14_TETIK_Pin GPIO_PIN_3
#define BAT14_TETIK_GPIO_Port GPIOD
#define BAT13_TETIK_Pin GPIO_PIN_4
#define BAT13_TETIK_GPIO_Port GPIOD
#define BAT12_TETIK_Pin GPIO_PIN_5
#define BAT12_TETIK_GPIO_Port GPIOD
#define BAT11_TETIK_Pin GPIO_PIN_6
#define BAT11_TETIK_GPIO_Port GPIOD
#define BAT10_TETIK_Pin GPIO_PIN_7
#define BAT10_TETIK_GPIO_Port GPIOD
#define BAT9_TETIK_Pin GPIO_PIN_3
#define BAT9_TETIK_GPIO_Port GPIOB
#define BAT8_TETIK_Pin GPIO_PIN_4
#define BAT8_TETIK_GPIO_Port GPIOB
#define BAT7_TETIK_Pin GPIO_PIN_5
#define BAT7_TETIK_GPIO_Port GPIOB
#define BAT6_TETIK_Pin GPIO_PIN_6
#define BAT6_TETIK_GPIO_Port GPIOB
#define BAT5_TETIK_Pin GPIO_PIN_7
#define BAT5_TETIK_GPIO_Port GPIOB
#define BAT4_TETIK_Pin GPIO_PIN_8
#define BAT4_TETIK_GPIO_Port GPIOB
#define BAT3_TETIK_Pin GPIO_PIN_9
#define BAT3_TETIK_GPIO_Port GPIOB
#define BAT2_TETIK_Pin GPIO_PIN_0
#define BAT2_TETIK_GPIO_Port GPIOE
#define BAT1_TETIK_Pin GPIO_PIN_1
#define BAT1_TETIK_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
