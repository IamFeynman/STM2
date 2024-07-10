#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "PWM.h"
#include "Servo.h"
#include "Key.h"


uint8_t Key_Num;
float Angle;

int main()
{
	OLED_Init();
	Servo_Init();
	Key_Init();
	OLED_ShowString(1,1,"Angle:");
	while(1)
	{
		Key_Num=Key_GetNum();
		if(Key_Num==1)
		{
			Angle += 30;
			if(Angle > 180)
				Angle=0;
		}
		Servo_SetAngle(Angle);
		OLED_ShowNum(1,7,(uint32_t)Angle,3);
	}
	
	
	
}
