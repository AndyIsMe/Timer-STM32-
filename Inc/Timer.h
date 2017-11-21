/*
 * Timer.h
 *
 *  Created on: Nov 21, 2017
 *      Author: TARUC
 */

#ifndef TIMER_H_
#define TIMER_H_
#include <stdint.h>
#include "Rcc.h"

#define TIMER1_BASE_ADDR	0x40010000
#define TIMER8_BASE_ADDR	0x40010400
#define Timer8 			((TimerReg *)(TIMER8_BASE_ADDR))
#define Timer1 			((TimerReg *)(TIMER1_BASE_ADDR))
#define TIM_CR1_EN					1
#define TIM_CR1_SMS_MASK			0x7
#define TIM_UIF						1
#define CC1EN						1
#define TIM_SEL_OC					0

//Channel 1 Mode
#define TIM_SEL_OC							0
#define TIM_SEL_IC_TI1						1
#define TIM_SEL_IC_TI2						2
#define TIM_SEL_IC_TRC						3

typedef struct TimerReg TimerReg;
struct TimerReg {
	volatile uint32_t CR1;		//0h
	volatile uint32_t CR2;		//4h
	volatile uint32_t SMCR;		//8h
	volatile uint32_t DIER;		//ch
	volatile uint32_t SR;		//10h
	volatile uint32_t EGR;		//14h
	volatile uint32_t CCMR1;	//18h
	volatile uint32_t CCMR2;	//1ch
	volatile uint32_t CCER;		//20h
	volatile uint32_t CNT;		//24h
	volatile uint32_t PSC;		//28h
	volatile uint32_t ARR;		//2ch
	volatile uint32_t RCR;		//30h
	volatile uint32_t CCR1;		//34h
	volatile uint32_t CCR2;		//38h
	volatile uint32_t CCR3;		//3ch
	volatile uint32_t CCR4;		//40h
	volatile uint32_t BDTR;		//44h
	volatile uint32_t DCR;		//48h
	volatile uint32_t DMAR;		//4ch

};

/**
 * Select 'mode' for channel
 *
 *
 */
#define timeSelectChn1AsOC()												\
	do{																		\
		Timer8->CCMR1 &= ~(TIM_SEL_OC);										\
	}while(0)

#define timeSelectChn3AsOC()												\
	do{																		\
		Timer8->CCMR2 &= ~(TIM_SEL_OC);										\
	}while(0)

#define enableTimer8()	do{								\
							Rcc->APB2RSTR &= ~(1<<1);	\
							Rcc->APB2ENR |= 1<<1;		\
							} while(0)
void initTimer8();
void initTimer8wait500ms();
void initTimer8Channel1();

#endif /* TIMER_H_ */
