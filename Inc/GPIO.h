/*
 * GPIO.h
 *
 *  Created on: Oct 27, 2017
 *      Author: Andy
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

#define SET_PIN(gpio,pinNum)	gpio->BSRR = (1 << pinNum)
#define RESET_PIN(gpio,pinNum)	gpio->BSRR = (1 << 16 + pinNum)
#define LOCK_PIN(gpio,pinNum)	GpioG->lock |= (1<<16)
#define GPIOA_BASE_ADDR	0x40020000
#define GPIOB_BASE_ADDR	0x40020400
#define GPIOC_BASE_ADDR	0x40020800
#define GPIOD_BASE_ADDR	0x40020C00
#define GPIOE_BASE_ADDR	0x40021000
#define GPIOF_BASE_ADDR	0x40021400
#define GPIOG_BASE_ADDR	0x40021800
#define GPIOH_BASE_ADDR	0x40021C00
#define GPIOI_BASE_ADDR	0x40022000
#define GPIO_OSPEED_OFF	0x8
#define GPIO_MODE_OFF	0x0
#define GPIO_PUPD_OFF	0xc
#define GPIO_OTYPE_OFF	0x4
#define GPIO_OD_OFF	0x14
#define GpioA 			((GpioReg *)(GPIOA_BASE_ADDR))
#define GpioB 			((GpioReg *)(GPIOB_BASE_ADDR))
#define GpioC 			((GpioReg *)(GPIOC_BASE_ADDR))
#define GpioD 			((GpioReg *)(GPIOD_BASE_ADDR))
#define GpioE 			((GpioReg *)(GPIOE_BASE_ADDR))
#define GpioF 			((GpioReg *)(GPIOF_BASE_ADDR))
#define GpioG 			((GpioReg *)(GPIOG_BASE_ADDR))
#define GpioH 			((GpioReg *)(GPIOH_BASE_ADDR))
#define GpioI 			((GpioReg *)(GPIOI_BASE_ADDR))

typedef struct GpioReg GpioReg;
struct GpioReg {
	volatile uint32_t mode;		//0h
	volatile uint32_t outType;	//4h
	volatile uint32_t outSpeed;	//8h
	volatile uint32_t pullType;	//ch
	volatile uint32_t inData;	//10h
	volatile uint32_t outData;	//14h
	volatile uint32_t bitData;	//18h
	volatile uint32_t lock;		//1ch
	volatile uint32_t altFuncLow;//20h
	volatile uint32_t altFuncHi; //24h
	volatile uint32_t BSRR;
};

//Alternate Function
#define ALT_FUNC0		0
#define ALT_FUNC1		1
#define ALT_FUNC2		2
#define ALT_FUNC3		3
#define ALT_FUNC4		4
#define ALT_FUNC5		5
#define ALT_FUNC6		6
#define ALT_FUNC7		7
#define ALT_FUNC8		8
#define ALT_FUNC9		9
#define ALT_FUNC10		10
#define ALT_FUNC11		11
#define ALT_FUNC12		12
#define ALT_FUNC13		13
#define ALT_FUNC14		14
#define ALT_FUNC15		15


//Pin Mode
#define GPIO_MODE_IN 	0
#define GPIO_MODE_OUT 	1
#define GPIO_MODE_AF 	2
#define GPIO_MODE_ANA 	3

//Pin output Drive Type
#define GPIO_PUSH_PULL 		0
#define GPIO_OPEN_DRAIN 	1
#define GPIO_NO_DRIVE		2

//Pin output Speed
#define GPIO_LOW_SPEED 		0
#define GPIO_MED_SPEED 		1
#define GPIO_HI_SPEED 		2
#define GPIO_VHI_SPEED 		3

//Pin Pull Type
#define GPIO_NO_PULL 	0
#define GPIO_PULL_UP 	1
#define GPIO_PULL_DOWN 	2

void gpioConfig(GpioReg *gpio , int pin , int Mode , int outdriveType , int pullType , int Speed);
void gpioWrite(GpioReg *gpio, int pin , int state);

void gpioConfigAltFuncNum(GpioReg *gpio,int pin,int AF);
void gpioGConfig(int pin , int Mode , int outdriveType , int pullType , int Speed);
void gpioGWrite(GpioReg *gpio,int pinNum , int state);
int gpioRead(GpioReg *gpio,int pin);
void GpioLock(GpioReg *gpio,int pin);
#endif /* GPIO_H_ */
