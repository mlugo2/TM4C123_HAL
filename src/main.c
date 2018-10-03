#include "Gpio.h"
#include "Uart.h"

#define SYSCTL_SYSDIV_10		0x04c00000

#define SYSCTL_RCGC2_GPIOA	0x00000001
#define SYSCTL_RCGC2_GPIOB	0x00000002
#define SYSCTL_RCGC2_GPIOC	0x00000004
#define SYSCTL_RCGC2_GPIOD	0x00000008
#define SYSCTL_RCGC2_GPIOE	0x00000010
#define SYSCTL_RCGC2_GPIOF	0x00000020

extern GpioConfig_t GpioConfig[];
extern UartConfig_t UartConfig[];

void Enable_IRQ(void)
{
	__asm 
	(
		"MOV R2, 0x0\n"
		"MSR BASEPRI, R2\n"
		"CPSIE I"
	);
}

int main(void)
{
	volatile uint32_t RCC;
	RCC = (SYSCTL_RCC_XTAL_16MHZ|SYSCTL_RCC_USESYSDIV|SYSCTL_SYSDIV_10);
	SYSCTL_RCC_R = RCC;
	
	SYSCTL_RCGC2_R = (SYSCTL_RCGC2_GPIOA|SYSCTL_RCGC2_GPIOB|SYSCTL_RCGC2_GPIOC|SYSCTL_RCGC2_GPIOD|SYSCTL_RCGC2_GPIOE|SYSCTL_RCGC2_GPIOF);

	// Configure GPIO
	Gpio_Init(GpioConfig);
	Uart_Init(UartConfig);
	
	// enable interrupt PD3 in NVIC and set priority to 3
	NVIC_PRI0_R = 0x60000000;
	NVIC_EN0_R = 0x8;
	
	Enable_IRQ();
	
	while(1) { GPIO_PORTB_DATA_R = 0x0;	}
}

void GPIOD_Handler(void)
{
	GPIO_PORTB_DATA_R = 0x1;
}

