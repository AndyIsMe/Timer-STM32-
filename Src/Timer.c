/*
 * Timer.c
 *
 *  Created on: Nov 21, 2017
 *      Author: TARUC
 */
#include "Timer.h"
#include "GPIO.h"

void initTimer8()
{

	//Enable Timer 8 --	Unreset , enable clock
	enableTimer8();

	//Configure the maximum counter value by setting ARR and the prescaler by setting PSC
	Timer8->ARR = 0xff;
	Timer8->PSC = 2;
	//Select the clock source (internal clock) -- Set SMCR:SMS[2:0] = 0
	//Timer8->SMCR |= sms <<(pin);
	Timer8->SMCR &= ~(TIM_CR1_SMS_MASK);
	//Enable Timer 8 -- Set CR1:CEN = 1
	//Timer8->CR1 &= 1<<4;
	Timer8->CR1 &= ~(TIM_CR1_EN);
	Timer8->CR1 |= TIM_CR1_EN;
}

void initTimer8wait500ms()
{

	//Enable Timer 8 --	Unreset , enable clock
	enableTimer8();

	//Configure the maximum counter value by setting ARR and the prescaler by setting PSC
	Timer8->ARR = 50000;
	Timer8->PSC = 18000;
	//Select the clock source (internal clock) -- Set SMCR:SMS[2:0] = 0
	//Timer8->SMCR |= sms <<(pin);
	Timer8->SMCR &= ~(TIM_CR1_SMS_MASK);
	//Enable Timer 8 -- Set CR1:CEN = 1
	//Timer8->CR1 &= 1<<4;
	//Timer8->CR1 &= ~(TIM_CR1_EN);
	Timer8->CR1 |= TIM_CR1_EN;
}

void initTimer8Channel1()
{
	//Configure timer 8 Channel 1 pin (PC6) -- Enable Port C , set pin as AltFunc3 Out-PP
	*rccAhb1Rst &= ~(1<<2);
	//Start clock of GPIOC
	*rccAhb1En |= 1<<2;
	gpioConfigAltFuncNum(GpioC,6,ALT_FUNC3);
	gpioConfig(GpioC,6, GPIO_MODE_AF , GPIO_PUSH_PULL , GPIO_NO_PULL , GPIO_VHI_SPEED);
	timeSelectChn1AsOC();
	Timer8->CCR1 |= CC1EN;
	Timer8->ARR = 5000;
	Timer8->PSC = 36;
}

/*
void initTimer8Channel3()
{
	//Configure timer 8 Channel 3 pin (PC8) -- Enable Port C , set pin as AltFunc3 In-
	*rccAhb1Rst &= ~(1<<2);
	//Start clock of GPIOC
	*rccAhb1En |= 1<<2;
	gpioConfigAltFuncNum(GpioC,6,ALT_FUNC3);
	gpioConfig(GpioC,6, GPIO_MODE_AF , GPIO_PUSH_PULL , GPIO_NO_PULL , GPIO_VHI_SPEED);
	timeSelectChn3AsOC();
	Timer8->CCR1 |= CC1EN;
	Timer8->ARR = 5000;
	Timer8->PSC = 36;

}*/
