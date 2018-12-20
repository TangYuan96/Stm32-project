#include "exti.h"
#include "delay.h" 
#include "led.h" 
#include "key.h"
#include "beep.h"


void EXTIX_Init(void)
{
	EXTI_InitTypeDef EXTI_InitStruc;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	KEY_Init();
	SYSCFG_EXTILineConfig( EXTI_PortSourceGPIOA, EXTI_PinSource0);
	
	
	EXTI_InitStruc.EXTI_Line = EXTI_Line0;
	EXTI_InitStruc.EXTI_LineCmd=ENABLE;
	EXTI_InitStruc.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStruc.EXTI_Trigger=EXTI_Trigger_Rising;
	
  EXTI_Init(&EXTI_InitStruc);
	
	
	NVIC_InitStruct.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_Init(&NVIC_InitStruct);  
}



void EXTI0_IRQHandler(void)
{
	delay_ms(100);	
	if (PAin(0) == 1)
	{
		PFout(9) = ~PFout(9);
		PFout(10) = ~PFout(10);
	}
	 EXTI_ClearITPendingBit(EXTI_Line0);

}








