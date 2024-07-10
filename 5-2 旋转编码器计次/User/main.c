#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "Encoder.h"

int16_t Num;

int main()
{
	OLED_Init();
	OLED_ShowString(1,3,"Hello World!");
	OLED_ShowString(2,1,"Num:");
	Encoder_Init();
	
	//OLED_Clear();//清屏
	while(1)
	{
		Num +=Encoder_Get();
		OLED_ShowSignedNum(2,5,Num,5);
		
	}
	
	
	
}
