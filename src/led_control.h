#ifndef LED_CONTROL_H
#define LED_CONTROL_H

void Red_LED(void)
{
	GPIO_PORTF_DATA_R = 0x2;
}

void Blue_LED(void)
{
	GPIO_PORTF_DATA_R = 0x4;
}

void Green_LED(void)
{
	GPIO_PORTF_DATA_R = 0x8;
}

#endif
