#include "led.h"
#include "stm32f4xx.h"
#include  "delay.h"



int main()
{
	delay_init(168);
	
	
	LED_Init();
	
	
	while (1)
	{
			GPIO_SetBits(GPIOF, GPIO_Pin_10);
			GPIO_SetBits(GPIOF, GPIO_Pin_9);
			delay_ms(500);
			GPIO_ResetBits(GPIOF, GPIO_Pin_10);
			GPIO_ResetBits(GPIOF, GPIO_Pin_9);
			delay_ms(500);
			

	}
	
	
	
	
}





