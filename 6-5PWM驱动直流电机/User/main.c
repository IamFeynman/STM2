#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "PWM.h"
#include "Motor.h"
#include "Key.h"

int8_t Speed;
uint8_t KeyNum;

int main()
{
	OLED_Init();
	Motor_Init();
	Key_Init();
	OLED_ShowString(1,1,"Speed:");
	while(1)
	{
		KeyNum = Key_GetNum();
		if(KeyNum == 1)
		{
			Speed += 20;
			if(Speed > 100)
				Speed = -100;
		}
		Motor_SetSpeed(Speed);
		OLED_ShowSignedNum(1,7,Speed,4);
		
	}
	
	
	
}
