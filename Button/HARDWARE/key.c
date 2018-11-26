#include "stm32f4xx.h"
#include "key.h"
#include "delay.h"

void KEY_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure; 

	// key 0 1 2
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 |  GPIO_Pin_3 | GPIO_Pin_4;  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;  
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;   
	GPIO_Init(GPIOE, &GPIO_InitStructure); 
	
	
	//key up
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;  
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;   
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
		
}


u8 key_scan(void)
{
	static u8 status_pre = 0; 
	u8 status_now = 0; 
	u8 status_now2 = 0; 
	
	delay_ms(25);
	
	
	/*
	status_now = KEY0 | (((KEY1?1:0)<<1) & 2) |  (((KEY2?1:0)<<2) & 4) |  ( ((KEY_UP?1:0)<<3) & 8) ;
	
	delay_ms(10);
	status_now2 = KEY0 | (((KEY1?1:0)<<1) & 2) |  (((KEY2?1:0)<<2) & 4) |  ( ((KEY_UP?1:0)<<3) & 8) ;
	*/
	
	status_now = (~KEY0 & 1) | ((~KEY1<<1) & 2)  |  (((~KEY2)<<2) & 4) |  ( ((KEY_UP)<<3) & 8);
	
	delay_ms(10);
	status_now2 = (~KEY0 & 1)  | ((  (~KEY1)  <<1) & 2)  |  (((~KEY2)<<2) & 4) |  ( ((KEY_UP)<<3) & 8);

	
	
	//Ã«´Ì
	if (status_now != status_now2)
	{
		return 0;
	}
	
	if (status_now == status_pre)
	{
		return 0;
	}
	else
	{
		status_pre = status_now;
		return  status_now;
	}		
}
