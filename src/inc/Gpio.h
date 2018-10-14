/**	@file gpio.h
*		@brief	The interface definition for the gpio.
*
*		This is the header file for the definition of the interface for
*		a digital input/output peripheral on a standard microcontroller.
*/
#ifndef GPIO_H_
#define GPIO_H_

/*************************************************************************
*	Includes
*************************************************************************/
#include <stdint.h>
#include "Gpio_cfg.h"
#include "inc/tm4c123gh6pm.h"

void Gpio_Init(GpioConfig_t * Config);
GpioPinState_t Gpio_ChannelRead(GpioChannel_t Channel);
void Gpio_ChannelWrite(GpioChannel_t, GpioPinState_t State);
void Gpio_ChannelToggle(GpioChannel_t);
void Gpio_RegisterWrite(uint32_t, uint32_t);

#endif
/***End of File**********************************************************/

