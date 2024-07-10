#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"

uint8_t Key_Num=0;

int main()
{
	LED_Init();
	Key_Init();
	while(1)
	{
		Key_Num=Key_GetNum();
		if(Key_Num==1)
		{
			LED1_turn();
		}
		if(Key_Num==2)
		{
			LED2_turn();
		}
		
	}
	
	
	
}
