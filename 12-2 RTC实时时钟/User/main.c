#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "MyRTC.h"

int main()
{
	OLED_Init();
	MyRTC_Init();
	
	OLED_ShowString(1,1,"Date:xxxx-xx-xx");
	OLED_ShowString(2,1,"Time:xx:xx:xx");
	OLED_ShowString(3,1,"CNT:");
	OLED_ShowString(4,1,"DIV:");
	while(1)
	{
		MyRTC_ReadTime();
		
		OLED_ShowNum(1,6,RTC_Time[0],4);
		OLED_ShowNum(1,11,RTC_Time[1],2);
		OLED_ShowNum(1,14,RTC_Time[2],2);
		OLED_ShowNum(2,6,RTC_Time[3],2);
		OLED_ShowNum(2,9,RTC_Time[4],2);
		OLED_ShowNum(2,12,RTC_Time[5],2);

		OLED_ShowNum(3,5,RTC_GetCounter(),10);
		OLED_ShowNum(4,5,RTC_GetDivider(),10);
	}
	
	
	
}
