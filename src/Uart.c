#include "Uart.h"

uint32_t volatile * const portUartControl[NUM_OF_UART_MODULES] =
{
	(uint32_t*)&UART0_CTL_R,
	(uint32_t*)&UART1_CTL_R,
	(uint32_t*)&UART2_CTL_R,
	(uint32_t*)&UART3_CTL_R,
	(uint32_t*)&UART4_CTL_R,
	(uint32_t*)&UART5_CTL_R,
	(uint32_t*)&UART6_CTL_R,
	(uint32_t*)&UART7_CTL_R,
};

uint32_t volatile * const integerBRD[NUM_OF_UART_MODULES] = 
{
	(uint32_t*)&UART0_IBRD_R,
	(uint32_t*)&UART1_IBRD_R,
	(uint32_t*)&UART2_IBRD_R,
	(uint32_t*)&UART3_IBRD_R,
	(uint32_t*)&UART4_IBRD_R,
	(uint32_t*)&UART5_IBRD_R,
	(uint32_t*)&UART6_IBRD_R,
	(uint32_t*)&UART7_IBRD_R,
};

uint32_t volatile * const fractorialBRD[NUM_OF_UART_MODULES] = 
{
	(uint32_t*)&UART0_FBRD_R,	
	(uint32_t*)&UART1_FBRD_R,
	(uint32_t*)&UART2_FBRD_R,
	(uint32_t*)&UART3_FBRD_R,
	(uint32_t*)&UART4_FBRD_R,
	(uint32_t*)&UART5_FBRD_R,
	(uint32_t*)&UART6_FBRD_R,
	(uint32_t*)&UART7_FBRD_R,
};

uint32_t volatile * const lineControl[NUM_OF_UART_MODULES] =
{
	(uint32_t*)&UART0_LCRH_R,
	(uint32_t*)&UART1_LCRH_R,
	(uint32_t*)&UART2_LCRH_R,
	(uint32_t*)&UART3_LCRH_R,
	(uint32_t*)&UART4_LCRH_R,
	(uint32_t*)&UART5_LCRH_R,
	(uint32_t*)&UART6_LCRH_R,
	(uint32_t*)&UART0_LCRH_R,
};

uint32_t volatile * const clockConfig[NUM_OF_UART_MODULES] =
{
	(uint32_t*)&UART0_CC_R,
	(uint32_t*)&UART1_CC_R,
	(uint32_t*)&UART2_CC_R,
	(uint32_t*)&UART3_CC_R,
	(uint32_t*)&UART4_CC_R,
	(uint32_t*)&UART5_CC_R,
	(uint32_t*)&UART6_CC_R,
	(uint32_t*)&UART7_CC_R,
};

void Uart_Init(UartConfig_t * Config)
{
	
	uint8_t i;						// Index

	for (i = 0; i < NUM_OF_UART_MODULES; i++)
	{
		// Check for master, Uart module will not be configured if not enabled
		if (Config[i].Master == UART_DISABLE)
			continue;

		// Disable UART[i] before configuring
		*portUartControl[i] &= (0UL<<0);

		// Set the integer baud rate
		*integerBRD[i] = Config[i].IntegerBRD;

		// Set the fractorial baud rate
		*fractorialBRD[i] = Config[i].FractorialBRD;

		// Set the word lenth of data
		if (Config[i].WordLen == FIVE_BITS)
		{
			*lineControl[i] &= (0UL<<6);
			*lineControl[i] &= (0UL<<5);
		}
		else if (Config[i].WordLen == SIX_BITS)
		{
			*lineControl[i] &= (0UL<<6);
			*lineControl[i] |= (1UL<<5);
		}
		else if (Config[i].WordLen == SEVEN_BITS)
		{
			*lineControl[i] |= (1UL<<6);
			*lineControl[i] &= (0UL<<5);
		}
		else 
		{
			*lineControl[i] |= (1UL<<6);
			*lineControl[i] |= (1UL<<5);
		}

		// Set the number of stop bits
		if (Config[i].StopSel == ONE_STOPBIT)
		{
			*lineControl[i] &= (0UL<<3);
		}
		else
		{
			*lineControl[i] |= (1UL<<3);
		}

		// Set the parity configuration
		if (Config[i].Parity == PAR_ENABLE)
		{
			*lineControl[i] |= (1UL<<1);
		}
		else
		{
			*lineControl[i] &= ~(1UL<<1);
		}

		// Set Clock configuration
		*clockConfig[i] &= 0xFFFFFFF0;
		if (Config[i].Clock == PIOSC)
		{
			*clockConfig[i] |= 0x5;
		}

		// Enable uart
		*portUartControl[i] |= (1UL<<0);
	}
}

