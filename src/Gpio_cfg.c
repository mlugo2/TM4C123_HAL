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
	/* Channel		Port										Both												*/
	/* Function		Ctrl	Direction	Digital		Sense		Edges		Event			Clear		Mask		*/
	/* 0:GPIO		0:OFF	0:INPUT		0:DISABLE	0:EDGE		0:EVENT		0:FALLING		0:NOFX		0:MASK		*/
	/* 1:PERIPH		1:ON	1:OUTPUT	1:ENABLE	1:LEVEL		1:BOTH		1:RISING		1:CLEAR		1:UNMASK	*/
	{	PORTA_0,	
		GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
	{	PORTA_1,	
		GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
	{	PORTA_2,	
		GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
	{	PORTA_3,	
		GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
	{	PORTA_4,	
		GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
	{	PORTA_5,	
		GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
	{	PORTA_6,	
		GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
	{	PORTA_7,	
		GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},

	{	PORTB_0,	
    	GPIO,		OFF,	OUTPUT,		ENABLE,		EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTB_1,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTB_2,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTB_3,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTB_4,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTB_5,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTB_6,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTB_7,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},

	{	PORTC_0,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTC_1,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTC_2,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTC_3,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTC_4,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTC_5,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTC_6,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTC_7,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},

	{	PORTD_0,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTD_1,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTD_2,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTD_3,	
    	GPIO,		OFF,	INPUT,		ENABLE,		LEVEL,		EVENT, 		RISING,			CLEAR, 		UNMASK},
    {	PORTD_4,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTD_5,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTD_6,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTD_7,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},

	{	PORTE_0,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTE_1,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTE_2,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTE_3,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTE_4,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTE_5,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTE_6,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTE_7,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},

	{	PORTF_0,	                                                                                         	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTF_1,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},	
    {	PORTF_2,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTF_3,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTF_4,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTF_5,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTF_6,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
    {	PORTF_7,	
    	GPIO,		OFF,	INPUT,		DISABLE,	EDGE,		EVENT, 		FALLING,		NOFX, 		MASK},
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

