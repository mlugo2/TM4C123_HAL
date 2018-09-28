/** @file gpio_cfg.c
*		@brief This module contains the implementation for the digital
*		input/output peripheral configuration.
*/

/*************************************************************************
*	Includes
*************************************************************************/
#include "Gpio_cfg.h"

/*************************************************************************
*	Module Variable Definitions
*************************************************************************/

/**
*	The following array contains the configuration data for each digital
*	input/output peripheral channel (pin). Each row represents a single
*	pin. Each column is representing a member of the GpioConfig_t struct.
*	This table is read in by Gpio_init, where each channel is then set up
*	based on this table.
*/
GpioConfig_t GpioConfig[] = 
{
	/* 																							Both						*/
	/* Channel		Funct		Dir			Digital		Sense		Edges		Event			Clear			Mask		*/
	/* 				0:GPIO		0:INPUT		0:DISABLE	0:EDGE		0:EVENT		0:DETECT_LO		0:NO_EFFECT		0:MASK		*/
	/*				1:PERIPH	1:OUTPUT	1:ENABLE	1:LEVEL		1:BOTH		1:DETECT_HI		1:CLEAR_ISR		1:UNMASK	*/
	{	PORTA_0,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTA_1,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTA_2,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTA_3,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTA_4,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTA_5,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTA_6,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTA_7,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},

	{	PORTB_0,	GPIO,		OUTPUT,		ENABLE,		EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTB_1,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTB_2,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTB_3,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTB_4,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTB_5,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTB_6,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTB_7,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	
	{	PORTC_0,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTC_1,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTC_2,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTC_3,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTC_4,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTC_5,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTC_6,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTC_7,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	
	/* 																							Both						*/
	/* Channel		Funct		Dir			Digital		Sense		Edges		Event			Clear			Mask		*/
	/* 				0:GPIO		0:INPUT		0:DISABLE	0:EDGE		0:EVENT		0:DETECT_LO		0:NO_EFFECT		0:MASK		*/
	/*				1:PERIPH	1:OUTPUT	1:ENABLE	1:LEVEL		1:BOTH		1:DETECT_HI		1:CLEAR_ISR		1:UNMASK	*/
	{	PORTD_0,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTD_1,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTD_2,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTD_3,	GPIO,		INPUT,		ENABLE,		LEVEL,		EVENT, 		DETECT_HI,		CLEAR_ISR, 		UNMASK},
	{	PORTD_4,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTD_5,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTD_6,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTD_7,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	
	{	PORTE_0,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTE_1,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTE_2,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTE_3,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTE_4,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTE_5,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTE_6,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTE_7,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	
	{	PORTF_0,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTF_1,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTF_2,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTF_3,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTF_4,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTF_5,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTF_6,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
	{	PORTF_7,	GPIO,		INPUT,		DISABLE,	EDGE,		EVENT, 		DETECT_LO,		NO_EFFECT, 		MASK},
};

/*************************************************************************
*	Function Definitions
*************************************************************************/

/*************************************************************************
*	Function : Gpio_GetConfig()
*//**
*	\b Description:
*	This function is used to retrieve the configuration table
*
*	PRE-CONDITION: Configuration table needs to be populated.
*
*	POST-CONDITION: A constant pointer to the first memeber of the
*	configuration table will be returned.
*
*	@return		A pointer to the configuration table.
*
*	\b Example:
*	@code
*	const GpioConfig_t *GpioConfig = Gpio_GetConfig();
*
*	Gpio_Init(GpioConfig);
*	@endcode
*
*************************************************************************/
GpioConfig_t * Gpio_GetConfig(void)
{
	return GpioConfig;
}

/*** END OF FUNCTIONS ***************************************************/

