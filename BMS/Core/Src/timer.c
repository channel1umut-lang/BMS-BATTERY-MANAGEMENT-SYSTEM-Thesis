/*
 * timer.c
 *
 *  Created on:
 *      Author:
 */


#include "main.h"


extern	uint32_t adc1_buffer[10];
extern	uint32_t adc2_buffer[10];
extern	uint32_t adc3_buffer[15];
extern	uint32_t adc4_buffer[10];

extern	ADC_HandleTypeDef hadc1;
extern	ADC_HandleTypeDef hadc2;
extern	ADC_HandleTypeDef hadc3;
extern	ADC_HandleTypeDef hadc4;
extern	DMA_HandleTypeDef hdma_adc1;
extern	DMA_HandleTypeDef hdma_adc2;
extern	DMA_HandleTypeDef hdma_adc3;
extern	DMA_HandleTypeDef hdma_adc4;
extern	uint8_t 	adc_saniye;
void	adc_filtreleme	(void);
extern	uint8_t 	adc_count;
extern	uint32_t adc1_buffer[10];
extern	uint32_t adc2_buffer[10];
extern	uint32_t adc3_buffer[15];
extern	uint8_t 	countx1;
extern	uint8_t		countx2;
extern	uint8_t 	timer_saniye;
extern	uint8_t		saniye_dallanma_sayicisi;
extern 	uint8_t		timer_200ms_islemleri;

extern	float 	vdda;
extern 	uint8_t	yarim_sayicisi;
extern	uint8_t	timer_500ms,sayi;

extern	float bat1,bat2,bat3,bat4,bat5,bat6,bat7,bat8,bat9,bat10,bat11,bat12,
		bat13,bat14,bat15,bat16,bat17,bat18,bat19,bat20;

extern	float			bat1_top,bat1_ort,
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

float bat1_b,bat1_carp
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

float	bat1_temp,
		bat2_temp,
		bat3_temp,
		bat4_temp,
		bat5_temp,
		bat6_temp,
		bat7_temp,
		bat8_temp,
		bat9_temp,
		bat10_temp,
		bat11_temp,
		bat12_temp,
		bat13_temp,
		bat14_temp,
		bat15_temp,
		bat16_temp,
		bat17_temp,
		bat18_temp,
		bat19_temp,
		bat20_temp
		;
float battery_ort,battery_toplam;


void	timer_100ms_islemleri(void)
{


}

