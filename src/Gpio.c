/**	@file gpio.c
*		@brief	The implementation for the gpio.
*/

/*************************************************************************
*	Includes
*************************************************************************/
#include "Gpio.h"

/*************************************************************************
*	Module Variable Definitions
*************************************************************************/

/**
*	Defines a table of pointers to the Port Data Register
*/
uint32_t volatile * const portData[NUM_OF_PORTS] = 
{
	(uint32_t*)&GPIO_PORTA_DATA_R,
	(uint32_t*)&GPIO_PORTB_DATA_R,
	(uint32_t*)&GPIO_PORTC_DATA_R,
	(uint32_t*)&GPIO_PORTD_DATA_R,
	(uint32_t*)&GPIO_PORTE_DATA_R,
	(uint32_t*)&GPIO_PORTF_DATA_R
};

uint32_t volatile * const portDir[NUM_OF_PORTS] = 
{
	(uint32_t*)&GPIO_PORTA_DIR_R,
	(uint32_t*)&GPIO_PORTB_DIR_R,
	(uint32_t*)&GPIO_PORTC_DIR_R,
	(uint32_t*)&GPIO_PORTD_DIR_R,
	(uint32_t*)&GPIO_PORTE_DIR_R,
	(uint32_t*)&GPIO_PORTF_DIR_R
};

uint32_t volatile * const portDen[NUM_OF_PORTS] = 
{
	(uint32_t*)&GPIO_PORTA_DEN_R,
	(uint32_t*)&GPIO_PORTB_DEN_R,
	(uint32_t*)&GPIO_PORTC_DEN_R,
	(uint32_t*)&GPIO_PORTD_DEN_R,
	(uint32_t*)&GPIO_PORTE_DEN_R,
	(uint32_t*)&GPIO_PORTF_DEN_R
};

uint32_t volatile * const portIS[NUM_OF_PORTS] = 
{
	(uint32_t*)&GPIO_PORTA_IS_R,
	(uint32_t*)&GPIO_PORTB_IS_R,
	(uint32_t*)&GPIO_PORTC_IS_R,
	(uint32_t*)&GPIO_PORTD_IS_R,
	(uint32_t*)&GPIO_PORTE_IS_R,
	(uint32_t*)&GPIO_PORTF_IS_R
};

uint32_t volatile * const portIBE[NUM_OF_PORTS] = 
{
	(uint32_t*)&GPIO_PORTA_IBE_R,
	(uint32_t*)&GPIO_PORTB_IBE_R,
	(uint32_t*)&GPIO_PORTC_IBE_R,
	(uint32_t*)&GPIO_PORTD_IBE_R,
	(uint32_t*)&GPIO_PORTE_IBE_R,
	(uint32_t*)&GPIO_PORTF_IBE_R
};

uint32_t volatile * const portIEV[NUM_OF_PORTS] = 
{
	(uint32_t*)&GPIO_PORTA_IEV_R,
	(uint32_t*)&GPIO_PORTB_IEV_R,
	(uint32_t*)&GPIO_PORTC_IEV_R,
	(uint32_t*)&GPIO_PORTD_IEV_R,
	(uint32_t*)&GPIO_PORTE_IEV_R,
	(uint32_t*)&GPIO_PORTF_IEV_R
};

uint32_t volatile * const portICR[NUM_OF_PORTS] = 
{
	(uint32_t*)&GPIO_PORTA_ICR_R,
	(uint32_t*)&GPIO_PORTB_ICR_R,
	(uint32_t*)&GPIO_PORTC_ICR_R,
	(uint32_t*)&GPIO_PORTD_ICR_R,
	(uint32_t*)&GPIO_PORTE_ICR_R,
	(uint32_t*)&GPIO_PORTF_ICR_R
};

uint32_t volatile * const portIM[NUM_OF_PORTS] = 
{
	(uint32_t*)&GPIO_PORTA_IM_R,
	(uint32_t*)&GPIO_PORTB_IM_R,
	(uint32_t*)&GPIO_PORTC_IM_R,
	(uint32_t*)&GPIO_PORTD_IM_R,
	(uint32_t*)&GPIO_PORTE_IM_R,
	(uint32_t*)&GPIO_PORTF_IM_R
};

/*************************************************************************
*	Function Definitions
*************************************************************************/

/*************************************************************************
*	Function : Gpio_Init()
*//**
*	\b Description:
*	This function is used to initialize the Gpio based on the configuration
*	table defined in gpio_cfg module.
*
*	PRE-CONDITION: Configuration table needs to be populated.
*	PRE-CONDITION: NUM_OF_CHANNELS_PER_PORT > 0 <br>
*	PRE-CONDITION: NUM_OF_PORTS > 0 <br>
*	PRE-CONDITION: The MCU clocks must be configured and enabled.
*
*	POST-CONDITION: The GPIO peripheral is set up with the configuration
* 	settings.
*
*	@param	Config is a pointer to the configuration table that
*			contains the initialization for the peripheral.
*
*	@return	void.
*
*	\b Example:
*	@code
*		const GpioConfig_t *GpioConfig = Gpio_GetConfig();
*
*		Gpio_Init(GpioConfig);
*	@endcode
*
*************************************************************************/

void Gpio_Init(GpioConfig_t * Config)
{
	uint8_t i = 0;				// Loop counter variable
	uint8_t port_num = 0;		// Port nubmer
	uint8_t pin_num = 0;		// Pin number

	// Loop through all pins, set the data register bit and data-direction
	// register bit according to the gpio config table values
	for (i = 0; i < NUM_DIGITAL_PINS; i++)
	{
		port_num = Config[i].Channel / NUM_OF_CHANNELS_PER_PORT;
		pin_num = Config[i].Channel % NUM_OF_CHANNELS_PER_PORT;

		// Set the Data-Direction register bit for this channel
		if (Config[i].Direction == OUTPUT)
		{
			*portDir[port_num] |= (1UL<<(pin_num));
		}
		else
		{
			*portDir[port_num] &= ~(1UL<<(pin_num));
		}

		// Set Digital Enable register bit for this channel
		if (Config[i].Digital == ENABLE)
		{
			*portDen[port_num] |= (1UL<<(pin_num));
		}
		else
		{
			*portDen[port_num] &= ~(1UL<<(pin_num));
		}

		// Set Interrupt Sense register bit for this channel
		if (Config[i].Sense == LEVEL)
		{
			*portIS[port_num] |= (1UL<<(pin_num));
		}
		else 
		{
			*portIS[port_num] &= ~(1UL<<(pin_num));
		}

		// Set Interrupt Both Enable register bit for this channel
		if (Config[i].BothEdges == BOTH)
		{
			*portIBE[port_num] |= (1UL<<(pin_num));
		}
		else
		{
			*portIBE[port_num] &= ~(1UL<<(pin_num));
		}

		// Set Interrupt Event register bit for this channel
		if (Config[i].Event == DETECT_HI)
		{
			*portIEV[port_num] |= (1UL<<(pin_num));
		}
		else
		{
			*portIEV[port_num] &= ~(1UL<<(pin_num));
		}

		// Set Interrupt Clear register bit for this channel
		if (Config[i].Clear == CLEAR_ISR)
		{
			*portICR[port_num] |= (1UL<<(pin_num));
		}
		else
		{
			*portICR[port_num] &= ~(1UL<<(pin_num));
		}

		// Set Interrupt Mask register bit for this channel
		if (Config[i].Mask == UNMASK)
		{
			*portIM[port_num] |= (1UL<<(pin_num));
		}
		else
		{
			*portIM[port_num] &= ~(1UL<<(pin_num));
		}
	} // end of for loop
}

/*************************************************************************
*	Function : Gpio_ChannelRead()
*//**
*	\b Description:
*	This function is used to read the state of a gpio channel (pin)
*
*	PRE-CONDITION: The channel is configured as INPUT <br>
*	PRE-CONDITION: The channel is configured as GPIO <br>
*	PRE-CONDITION: The channel is within the maximum GpioChannel_t
*	definition. <br>
*
*	POST-CONDITION: The channel state is returned.
*
* 	@param	Channel is the GpioChannel_t that represents a pin
*
*	@return	The state of the channel as HIGH or LOW
*
*	\b Example:
*	@code
*		uint8_t pin = Gpio_ReadChannel(PORT1_0);
*	@endcode
*
*************************************************************************/
GpioPinState_t Gpio_ChannelRead(GpioChannel_t Channel)
{
	/* Read the port associated with the desired pin */
	GpioPinState_t PortState = (GpioPinState_t) *portData[Channel/NUM_OF_CHANNELS_PER_PORT];

	/* Determine the port bit associated with this channel */
	GpioPinState_t PinMask = (GpioPinState_t)(1UL<<(Channel%NUM_OF_CHANNELS_PER_PORT));

	/* Mask the port state with the pin and return the GpioPinState */
	return (( PortState & PinMask) ? GPIO_HIGH : GPIO_LOW);
}

/*************************************************************************
*	Function : Gpio_ChannelWrite()
*//**
*	\b Description:
*	This function is used to write the state of a channel (pin) as either
*	logic high or low through the use of the GpioChannel_t enum to select
*	the channel and the GpioPinState_t to define the desired state.
*
*	PRE-CONDITION: The channel is configured as OUTPUT <br>
*	PRE-CONDITION: The channel is configured as GPIO <br>
*	PRE-CONDITION: The channel is within the maximum GpioChannel_t
*	definition. <br>
*
*	POST-CONDITION: The channel state will be State
*
* 	@param	Channel is the pin to write using GpioChannel_t
*			enum definition.
*
* 	@param	State is HIGH or LOW as defined in the GpioPinState_t
*			enum.
*
*	@return	void.
*
*	\b Example:
*	@code
*		Gpio_WriteChannel(PORT1_0, LOW);
*		Gpio_WriteChannel(PORT1_0, HIGH);
*	@endcode
*
*************************************************************************/
void Gpio_ChannelWrite(GpioChannel_t Channel, GpioPinState_t State)
{
	if (State == GPIO_HIGH)
	{
		*portData[Channel/NUM_OF_CHANNELS_PER_PORT] |= (1UL<<(Channel%NUM_OF_CHANNELS_PER_PORT));
	}
	else
	{
		*portData[Channel/NUM_OF_CHANNELS_PER_PORT] &= ~(1UL<<(Channel%NUM_OF_CHANNELS_PER_PORT));
	}
}

/*************************************************************************
*	Function : Gpio_ChannelToggle()
*//**
*	\b Description:
*	This function is used to toggle the current state of a channel (pin).
*
*	PRE-CONDITION: The channel is configured as OUTPUT <br>
*	PRE-CONDITION: The channel is configured as GPIO <br>
*	PRE-CONDITION: The channel is within the maximum GpioChannel_t
*	definition. <br>
*
*	POST-CONDITION:
*
* @param	Channel is the pin to write using GpioChannel_t
*			that is to be modified.
*
*	@return	void.
*
*	\b Example:
*	@code
*		Gpio_ChannelToggle(PORT1_1);
*	@endcode
*
*************************************************************************/
void Gpio_ChannelToggle(GpioChannel_t Channel)
{
	
}
