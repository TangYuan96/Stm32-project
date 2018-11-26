#include "beep.h"
#include "sys.h"

void BEEP_Init()
{
	GPIO_InitTypeDef  GPIO_InitStructure1;   
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
 
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_8;  
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_OUT;   
	GPIO_InitStructure1.GPIO_OType = GPIO_OType_PP;  
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_100MHz;  
	GPIO_InitStructure1.GPIO_PuPd = GPIO_PuPd_UP;   
	GPIO_Init(GPIOF, &GPIO_InitStructure1); 
	PFout(8) = 1;
	
}

