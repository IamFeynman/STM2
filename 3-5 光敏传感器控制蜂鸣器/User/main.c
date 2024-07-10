#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "Buzzer.h"
#include "Light Sensor.h"

int main()
{
	Buzzer_Init();
	LightSensor_Init();
	while(1)
	{
		if(LightSensor_Get()==1)//遮光
			Buzzer_ON();
		else//不遮光
			Buzzer_OFF();
		
	}
	
	
	
}
