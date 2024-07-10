#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "Timer.h"

uint16_t Num;

int main()
{
	OLED_Init();
	Timer_Init();
	OLED_ShowString(1,3,"Hello World!");
	OLED_ShowString(2,1,"Num:");
	//OLED_Clear();//清屏
	while(1)
	{
		OLED_ShowNum(2,5,Num,5);
	}
	
	
	
}
