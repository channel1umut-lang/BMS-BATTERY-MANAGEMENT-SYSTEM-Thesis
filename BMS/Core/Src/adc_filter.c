/*
 * Adc_Filter.c
 *
 *  Created on: Jul 19, 2021
 *      Author: Oguzhan
 */


#include "main.h"

extern	uint8_t 	adc_count;
extern	uint32_t adc1_buffer[10];
extern	uint32_t adc2_buffer[10];
extern	uint32_t adc3_buffer[15];
extern	uint8_t 	countx1;
extern	uint8_t		countx2;
extern	uint8_t 	timer_saniye;
extern	uint8_t		saniye_dallanma_sayicisi;
extern 	uint8_t		timer_200ms_islemleri;
extern	uint8_t 	adc_saniye;
extern	float 	vdda;

float	vddax[10];
uint8_t	bakx=0;
extern	float	vtop,vort;
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

extern	float bat1,bat2,bat3,bat4,bat5,bat6,bat7,bat8,bat9,bat10,bat11,bat12,
		bat13,bat14,bat15,bat16,bat17,bat18,bat19,bat20;





void	adc_filtreleme	(void)
{
	bakx++;


	vtop+=vdda;
	bat1_top+=bat1;
	bat2_top+=bat2;
	bat3_top+=bat3;
	bat4_top+=bat4;
	bat5_top+=bat5;
	bat6_top+=bat6;
	bat7_top+=bat7;
	bat8_top+=bat8;
	bat9_top+=bat9;
	bat10_top+=bat10;
	/*bat11_top+=bat11;
	bat12_top+=bat12;
	bat13_top+=bat13;
	bat14_top+=bat14;
	bat15_top+=bat15;
	bat16_top+=bat16;
	bat17_top+=bat17;
	bat18_top+=bat18;
	bat19_top+=bat19;
	bat20_top+=bat20;
*/

	if(bakx>9)
	{
		bakx=0;
		vort=vtop/10;
		vtop=0;

		bat1_ort=bat1_top/10;
		bat1_top=0;

		bat2_ort=bat2_top/10;
		bat2_top=0;

		bat3_ort=bat3_top/10;
		bat3_top=0;

		bat4_ort=bat4_top/10;
		bat4_top=0;

		bat5_ort=bat5_top/10;
		bat5_top=0;

		bat6_ort=bat6_top/10;
		bat6_top=0;

		bat7_ort=bat7_top/10;
		bat7_top=0;

		bat8_ort=bat8_top/10;
		bat8_top=0;

		bat9_ort=bat9_top/10;
		bat9_top=0;

		bat10_ort=bat10_top/10;
		bat10_top=0;

		bat11_ort=bat11_top/10;
		bat11_top=0;

		bat12_ort=bat12_top/10;
		bat12_top=0;

		bat13_ort=bat13_top/10;
		bat13_top=0;

		bat14_ort=bat14_top/10;
		bat14_top=0;

		bat15_ort=bat15_top/10;
		bat15_top=0;

		bat16_ort=bat16_top/10;
		bat16_top=0;

		bat17_ort=bat17_top/10;
		bat17_top=0;

		bat18_ort=bat18_top/10;
		bat18_top=0;

		bat19_ort=bat19_top/10;
		bat19_top=0;

		bat20_ort=bat20_top/10;
		bat20_top=0;






	}



}
