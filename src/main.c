#include "Gpio.h"
#include "Uart.h"

#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "led_control.h"

#define SYSCTL_SYSDIV_10	0x04c00000

#define SYSCTL_RCGC2_GPIOA	0x00000001
#define SYSCTL_RCGC2_GPIOB	0x00000002
#define SYSCTL_RCGC2_GPIOC	0x00000004
#define SYSCTL_RCGC2_GPIOD	0x00000008
#define SYSCTL_RCGC2_GPIOE	0x00000010
#define SYSCTL_RCGC2_GPIOF	0x00000020

void Enable_IRQ(void);
void Clock_Setup(void);

void UART_Init(void);
void UART_Transmit(char sdata);
char UART_Recieve(void);

int main(void)
{
	uint8_t num = 0;
	char s_data, chr[26];

	Clock_Setup();
	Gpio_Init(Gpio_GetConfig());
	Gpio_RegisterWrite(&GPIO_PORTB_PCTL_R, 0x00000011);
	// GPIO_PORTB_PCTL_R = 0x00000011;
	
	//Uart_Init(Uart_GetConfig());
	UART_Init();
	Enable_IRQ();

	for(s_data='A'; s_data <= 'Z'; s_data++)
	{
		UART_Transmit(s_data);
		chr[num] = UART_Recieve();
		num++;
	}

//	if (chr[0] == 'A')	
//		Blue_LED();

	while(1);
}

void UART_Init(void)
{
	UART1_CTL_R &= 0xFFFFFFFE;
	UART1_IBRD_R = 0x8;
	UART1_FBRD_R = 0x2C;
	UART1_IM_R = (1UL<<4);
	UART1_ICR_R = (1UL<<4);
	UART1_ICR_R |= (1UL<<5);
	UART1_LCRH_R = 0x60;
	UART1_CC_R = 0x0;
	UART1_CTL_R |= 0x1;
}

void UART_Transmit(char sdata)
{
	while ((UART1_FR_R & 0x20) != 0);
	UART1_DR_R = sdata;
}

char UART_Recieve(void)
{
	uint32_t ret;
	char rdata;

	while ((UART1_FR_R & 0x10) != 0);
	ret = UART1_DR_R;
	if (ret & 0xF00) { GPIO_PORTF_DATA_R = 0xF; }
	else { rdata = (char)(UART1_DR_R & 0xFF); }
	return rdata;
}

void Enable_IRQ(void)
{
	__asm
	(
		"MOV R2, 0x0\n"
		"MSR BASEPRI, R2\n"
		"CPSIE I"
	);
}

void Clock_Setup(void)
{
	// volatile uint32_t RCC;
	// RCC = (SYSCTL_RCC_XTAL_16MHZ|SYSCTL_RCC_USESYSDIV|SYSCTL_SYSDIV_10);
	// SYSCTL_RCC_R = RCC;

	SYSCTL_RCGCUART_R = 0x02;
	
	SYSCTL_RCGCGPIO_R = (SYSCTL_RCGC2_GPIOA|
					  SYSCTL_RCGC2_GPIOB|
					  SYSCTL_RCGC2_GPIOC|
					  SYSCTL_RCGC2_GPIOD|
					  SYSCTL_RCGC2_GPIOE|
					  SYSCTL_RCGC2_GPIOF); 
}

void GPIOD_Handler(void)
{

}

void UART1_Handler(void)
{
	Red_LED();
}
