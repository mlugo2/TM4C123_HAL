/**	@file	gpio_cfg.h
*		@brief	This module contains interface definitions for the
*		Gpio configuration. This is the header file for the definition of the
*		interface for retrieving the digital input/output configuration table.
*/

#ifndef GPIO_CFG_H
#define GPIO_CFG_H

/*************************************************************************
*	Includes
*************************************************************************/

/*************************************************************************
*	Preprocessor Constants
*************************************************************************/

/**
*	Defines the number of pins on each processor port
*/
#define NUM_OF_CHANNELS_PER_PORT	8u

/**
*	Defines the number of ports on the processor.
*/
#define NUM_OF_PORTS	6u

/**
*	Defines the total number of digital pins
*/
#define NUM_DIGITAL_PINS	48u

/*************************************************************************
*	Typedefs
*************************************************************************/

/**
*	Defines the possible states for a digital output pin.
*/
typedef enum
{
	GPIO_LOW,							/**< Defines digital state ground 		*/
	GPIO_HIGH,							/**< Defines digital state power  		*/
	GPIO_PIN_STATE_MAX					/**< Defines the maximum digital state	*/
} GpioPinState_t;

/**
*	Defines an enumerated list of all the channels (pins) on the MCU
*	device. The last element is used to specify the maximum number of
*	enumerated labels.
*/
typedef enum
{
	PORTA_0,							/**< PORTA_0 */
	PORTA_1,							/**< PORTA_1 */
	PORTA_2,							/**< PORTA_2 */
	PORTA_3,							/**< PORTA_3 */
	PORTA_4,							/**< PORTA_4 */
	PORTA_5,							/**< PORTA_5 */
	PORTA_6,							/**< PORTA_6 */
	PORTA_7,							/**< PORTA_7 */

	PORTB_0,							/**< PORTB_0 */
	PORTB_1,							/**< PORTB_1 */
	PORTB_2,							/**< PORTB_2 */
	PORTB_3,							/**< PORTB_3 */
	PORTB_4,							/**< PORTB_4 */
	PORTB_5,							/**< PORTB_5 */
	PORTB_6,							/**< PORTB_6 */
	PORTB_7,							/**< PORTB_7 */

	PORTC_0,							/**< PORTC_0 */
	PORTC_1,							/**< PORTC_1 */
	PORTC_2,							/**< PORTC_2 */
	PORTC_3,							/**< PORTC_3 */
	PORTC_4,							/**< PORTC_4 */
	PORTC_5,							/**< PORTC_5 */
	PORTC_6,							/**< PORTC_6 */
	PORTC_7,							/**< PORTC_7 */

	PORTD_0,							/**< PORTD_0 */
	PORTD_1,							/**< PORTD_1 */
	PORTD_2,							/**< PORTD_2 */
	PORTD_3,							/**< PORTD_3 */
	PORTD_4,							/**< PORTD_4 */
	PORTD_5,							/**< PORTD_5 */
	PORTD_6,							/**< PORTD_6 */
	PORTD_7,							/**< PORTD_7 */

	PORTE_0,							/**< PORTE_0 */
	PORTE_1,							/**< PORTE_1 */
	PORTE_2,							/**< PORTE_2 */
	PORTE_3,							/**< PORTE_3 */
	PORTE_4,							/**< PORTE_4 */
	PORTE_5,							/**< PORTE_5 */
	PORTE_6,							/**< PORTE_6 */
	PORTE_7,							/**< PORTE_7 */

	PORTF_0,							/**< PORTF_0 */
	PORTF_1,							/**< PORTF_1 */
	PORTF_2,							/**< PORTF_2 */
	PORTF_3,							/**< PORTF_3 */
	PORTF_4,							/**< PORTF_4 */
	PORTF_5,							/**< PORTF_5 */
	PORTF_6,							/**< PORTF_6 */
	PORTF_7,							/**< PORTF_7 */
	GPIO_MAX_PIN_NUM					/**< MAX CHANNELS */
} GpioChannel_t;

/**
*	Defines the possible alternative function modes for each pin
*/
typedef enum
{
	GPIO,								/**< Pin works in GPIO mode */
	PERIPH,								/**< Pin controlled by certain peripheral */
	MAX_FUNCTION						/**< MAX FUNCTIONS AVAILABLE */
} GpioFunction_t;

/**
*	Defines the possible directions of a pin (input/output).
*/
typedef enum
{
	INPUT,								/**< Pin is configured for input */
	OUTPUT,								/**< Pin is configured for output */
	MAX_DIRECTION
} GpioDirection_t;

/**
*	Defines the possible digital function modes
*/
typedef enum
{
	DISABLE,							/**< Pin could be configured as analog */
	ENABLE,								/**< Pin is configured to work digitally */
	MAX_DIGITAL_FUNCT
} GpioDigitalEn_t;

/**
*	Defines the possible trigger modes of an interrupt
*/
typedef enum
{
	EDGE,								/**< Falling/Rising edges are triggers for interrupt */
	LEVEL,								/**< Stable signal triggers the interrupt */
	MAX_TRIGGER_MODES
} GpioSense_t;

/**
*	Defines the possible edge modes
*/
typedef enum
{
	EVENT,								/**< Interrupt controlled by Event register */
	BOTH,								/**< Interrupt triggered by both edges */
	MAX_BOTH_EDGES_MODES
} GpioBothEdges_t;

/**
*	Defines the possible event detections
*/
typedef enum
{
	FALLING,							/**< Detects falling edges */
	RISING,								/**< Detects rising edges */
	MAX_EVENT_MODE
} GpioEvent_t;

/**
*	Defines the possible clearing options
*/
typedef enum
{
	NOFX,								/**< Does nothing.. */
	CLEAR,								/**< Clears corresponding ISR pins */
	MAX_NUM
} GpioClear_t;

/** 
*	Defines the possible masking states
*/
typedef enum
{
	MASK,								/**< Interrupt is disabled */
	UNMASK,								/**< Interrupt is enabled */
	MAX_MASK_STATE
} GpioMask_t;

/**
*	Defines the digital input/output configuration table's elements
*	that are used by Gpio_Init to configure the Gpio peripheral.
*/
typedef struct
{
	GpioChannel_t Channel;				/**< The I/O pin			*/
	GpioFunction_t Function;			/**< GPIO or PERIPH mode	*/
	GpioDirection_t Direction;			/**< INPUT or OUTPUT		*/
	GpioDigitalEn_t Digital;			/**< DISABLE or ENABLE		*/
	GpioSense_t Sense;					/**< EDGE or LEVEL			*/
	GpioBothEdges_t BothEdges;			/**< EVENT OR BOTH 			*/
	GpioEvent_t Event;					/**< FALLING or RISING		*/
	GpioClear_t Clear;					/**< NOFX or CLEAR			*/
	GpioMask_t Mask;					/**< MASK or UNMASK 		*/
} GpioConfig_t;

/*************************************************************************
*	Fucntion Prototypes
*************************************************************************/
GpioConfig_t * Gpio_GetConfig(void);

#endif
/***End of File**********************************************************/

