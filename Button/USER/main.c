#include "stm32f4xx.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"


int main()
{
	
	u8 key_status =0;
	delay_init(168);
	
	
	LED_Init();
	BEEP_Init();
	KEY_Init();
	
	while (1)
	{
		key_status = key_scan();
		
		
		if (key_status)
		{
			if ((key_status & 1) == 1)
			{
				LED0 = 0;
			}		
			if (( (key_status & 02) & 2) == 2)
			{
				LED1 = 0;
				//BEEP = 1;
			}			
			if ((key_status & 4) == 4)
			{
				LED0 = 0;
				LED1 = 0;
			}		
			if ((key_status & 8) == 8)
			{
				BEEP = 1;
			}
			
			delay_ms(400);
			

		}
		

		LED0 = 1;
		LED1 = 1;
		BEEP = 0;

	}
	
	
	
	
}





