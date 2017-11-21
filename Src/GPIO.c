/*
 * GPIO.c
 *
 *  Created on: Oct 27, 2017
 *      Author: Andy
 */

#include "GPIO.h"

void gpioConfig(GpioReg *gpio,int pin , int Mode , int outdriveType , int pullType , int Speed){
	gpio->mode &= ~(3<<(pin * 2));			//Clear pin mode to 0 first
	gpio->mode |= Mode <<(pin * 2);			//Set the pin mode

	gpio->outSpeed &= ~(3<<(pin *2));			//Clear pin speed to 0 first
	gpio->outSpeed |= Speed << (pin * 2);		//Set the pin speed

	gpio->pullType &= ~(3<<(pin *2));			//Clear pin pulltype to 0 first
	gpio->pullType |= pullType << (pin * 2);	//Set the pin pulltype

	gpio->outType &= ~(1<<pin);					//Clear pin outdriveType to 0 first
	gpio->outType |= outdriveType << pin;		//Set the pin outdriveType
}

void gpioWrite(GpioReg *gpio,int pin , int state){
	if(state == 1){
	gpio->outData |= 1 << pin;
}	else{
	gpio->outData &= ~(1<<pin);
}
}

int gpioRead(GpioReg *gpio,int pin ){
	return gpio->inData & (1 << pin);

}

void gpioGConfig(int pin , int Mode , int outdriveType , int pullType , int Speed){
	GpioG->mode &= ~(3<<(pin * 2));				//Clear pin mode to 0 first
	GpioG->mode |= Mode <<(pin * 2);			//Set the pin mode

	GpioG->outSpeed &= ~(3<<(pin *2));			//Clear pin speed to 0 first
	GpioG->outSpeed |= Speed << (pin * 2);		//Set the pin speed

	GpioG->pullType &= ~(3<<(pin *2));			//Clear pin pulltype to 0 first
	GpioG->pullType |= pullType << (pin * 2);	//Set the pin pulltype

	GpioG->outType &= ~(1<<pin);				//Clear pin outdriveType to 0 first
	GpioG->outType |= outdriveType << pin;		//Set the pin outdriveType
}

void gpioGWrite(GpioReg *gpio,int pinNum , int state){
	if(state == 1){
	RESET_PIN(gpio,pinNum);
}	else{
	SET_PIN(gpio,pinNum);
}
}
 void GpioLock(GpioReg *gpio,int pin){
	 int LockPattern;
	  gpio->lock = (1 << 16)|(1<<pin);
	  gpio->lock = (0 << 16)|(1<<pin);
	  gpio->lock = (1 << 16)|(1<<pin);

	  LockPattern = gpio->lock;
 }

 void gpioConfigAltFuncNum(GpioReg *gpio,int pin,int AF){
	 if(pin<7)
		 gpio->altFuncLow =  AF << (pin*4);
	 else
		 gpio->altFuncHi = AF << (pin*4);
 }

