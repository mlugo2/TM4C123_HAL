/**	@file Uart_cfg.h
*	@brief This module contains interface definitions for the Uart
*	configuration. This is the header file for the definition of the interface
*	for retrieving the UART configuration table.
*/
#ifndef UART_CFG_H
#define UART_CFG_H

/******************************************************************************
*	Includes
******************************************************************************/
#include <stdint.h>

/******************************************************************************
*	Preprocessor Constants
******************************************************************************/

/**
*	Defines the number of UART modules on the MCU
*/
#define NUM_OF_UART_MODULES		8u


/******************************************************************************
*	Typedefs
******************************************************************************/

/**
*	Defines whether the Uart module will be configured
*/
typedef enum
{
	UART_ENABLE,
	UART_DISABLE,
	UART_MASTER_MAX
} UartMaster_t;

typedef enum
{
	UART0,
	UART1,
	UART2,
	UART3,
	UART4,
	UART5,
	UART6,
	UART7,
	MAX_UART_MODULES
} UartModule_t;

/**
*	Defines the possible states of control states for each module
*/
typedef enum
{
	CTL_DISABLE,
	CTL_ENABLE,
	MAX_CONTROL_STATE
} UartControl_t;

/**
*	Defines the possible states for data length
*/
typedef enum
{
	FIVE_BITS,
	SIX_BITS,
	SEVEN_BITS,
	EIGHT_BITS,
	MAX_WORD_STATE
} UartWordLength_t;

/**
*	Defines the possible states for stop bit configuration
*/
typedef enum
{
	ONE_STOPBIT,
	TWO_STOPBIT,
	MAX_STOP_STATE
} UartStopBitSelect_t;

/**
*	Defines the possible states for parity bit config
*/
typedef enum
{
	PAR_DISABLE,
	PAR_ENABLE,
	MAX_PARITY_STATE
} UartParity_t;

/**
*	Defines the possible states for clock configuration
*/
typedef enum
{
	SYS_CLOCK,
	PIOSC,
	MAX_CLOCK_STATE
} UartClockConfig_t;

typedef struct
{
	UartModule_t Module;
	UartMaster_t Master;
	UartControl_t Control;
	uint32_t IntegerBRD;
	uint32_t FractionalBRD;
	UartWordLength_t WordLen;
	UartStopBitSelect_t StopSel;
	UartParity_t Parity;
	UartClockConfig_t Clock;
} UartConfig_t;

/******************************************************************************
*	Function Prototypes
******************************************************************************/
UartConfig_t * Uart_GetConfig(void);

#endif
/***End of File***************************************************************/

