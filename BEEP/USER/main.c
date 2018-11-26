#include "stm32f4xx.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"


int main()
{
	delay_init(168);
	
	
	LED_Init();
	BEEP_Init();
	
	
	while (1)
	{
			BEEP =1;
			LED = 1;
			delay_ms(500);
			BEEP =0;
			LED = 0	;
			delay_ms(500);
			

	}
	
	
	
	
}





