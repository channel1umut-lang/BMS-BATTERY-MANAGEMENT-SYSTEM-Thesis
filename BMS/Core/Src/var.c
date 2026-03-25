/*
 * var.c
 *
 *  Created on:
 *      Author:
 */

#include "main.h"


uint8_t	timer_500ms=0,sayi=0;
uint8_t	yarim_sayicisi=0;

uint8_t batmsg1, batmsg2, batmsg3, batmsg4, batmsg5, batmsg6, batmsg7, batmsg8, batmsg9, batmsg10,
 	 	 	 batmsg11, batmsg12, batmsg13, batmsg14, batmsg15, batmsg16, batmsg17, batmsg18, batmsg19, batmsg20;


uint8_t 	adc_count=0;
uint32_t adc1_buffer[10];
uint32_t adc2_buffer[10];
uint32_t adc3_buffer[15];
uint32_t adc4_buffer[10];
uint8_t 	countx1=0;
uint8_t		countx2=0;
uint8_t 	timer_saniye=0;
uint8_t		saniye_dallanma_sayicisi=0;
uint8_t		timer_200ms_islemleri=0;
uint8_t 	adc_saniye=0;

uint16_t adc1_value[4],adc2_value[2];
uint8_t count1=0,count2=0;
uint8_t adc1_okundu=0,adc2_okundu=0;

uint8_t	batarya_tetik=0;

int		bat1_int=0,
		bat2_int=0,
		bat3_int=0,
		bat4_int=0,
		bat5_int=0,
		bat6_int=0,
		bat7_int=0,
		bat8_int=0,
		bat9_int=0,
		bat10_int=0;


float	pil1,pil1_,pil2,pil3,pil4,pil5,pil6,pil7,pil8,pil9,pil10;

float	vtop,vort;

float			bat1_top,bat1_ort,
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


