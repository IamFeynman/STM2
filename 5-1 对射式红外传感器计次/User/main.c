#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "CountSensor.h"


int main()
{
	OLED_Init();
	CountSensor_Init();
	OLED_ShowString(1,3,"Hellow World!");
	OLED_ShowString(2,1,"Count:");
	
	//OLED_Clear();//清屏
	while(1)
	{
		OLED_ShowNum(2,7,CountSensor_Get(),5);
	}
	
	
	
}
