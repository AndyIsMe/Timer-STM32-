/*
 * Rcc.c
 *
 *  Created on: Oct 27, 2017
 *      Author: Andy
 */

#include "Rcc.h"

uint32_t *rccAhb1Rst = (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1RST_OFF);
uint32_t *rccAhb1En = (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1EN_OFF);

void enableGpioA(void){
	//Unreset GPIOG
	*rccAhb1Rst &= ~1;
	//Start clock of GPIOA
	*rccAhb1En |= 1;
}

void enableGpioB(void){
	//Unreset GPIOG
	*rccAhb1Rst &= ~(1<<1);
	//Start clock of GPIOG
	*rccAhb1En |= 1<<1;
}

void enableGpioG(void){
	//Unreset GPIOG
	*rccAhb1Rst &= ~(1<<6);
	//Start clock of GPIOG
	*rccAhb1En |= 1<<6;
}

void enableRng(void){
	//Unreset RNG
	Rcc-> AHB2RSTR &= ~(1 << 6);
	//Start clock of RNG
	Rcc-> AHB2ENR |= 1 << 6;
}
