#include "stm32f10x.h"                  // Device header
#include <time.h>

uint16_t RTC_Time[]={2023,8,15,19,3,0};

void MyRTC_SetTime(void);

void MyRTC_Init(void)
{	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);
	
	PWR_BackupAccessCmd(ENABLE);
	
	if(BKP_ReadBackupRegister(BKP_DR1) != 0x4545)//使用BKP实现断电继续及时
	{
		RCC_LSEConfig(RCC_LSE_ON);
		while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) != SET);
		
		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
		RCC_RTCCLKCmd(ENABLE);
		
		RTC_WaitForSynchro();
		RTC_WaitForLastTask();
		
		RTC_SetPrescaler(32768 - 1);
		RTC_WaitForLastTask();

		MyRTC_SetTime();
		
		BKP_WriteBackupRegister(BKP_DR1,0x4545);
	}
	else
	{
		RTC_WaitForSynchro();
		RTC_WaitForLastTask();
	}
	
}

void MyRTC_SetTime(void)
{
	time_t time_cnt;
	struct tm time_date;
	time_date.tm_year = RTC_Time[0]-1900;
	time_date.tm_mon= RTC_Time[1]-1;
	time_date.tm_mday = RTC_Time[2];
	time_date.tm_hour = RTC_Time[3];
	time_date.tm_min = RTC_Time[4];
	time_date.tm_sec = RTC_Time[5];
	
	time_cnt = mktime(&time_date) - 8*60*60;
	
	RTC_SetCounter(time_cnt);
	RTC_WaitForLastTask();
}

void MyRTC_ReadTime(void)
{
	time_t time_cnt;
	struct tm time_date;
	
	time_cnt = RTC_GetCounter() + 8*60*60;
	
	time_date = *localtime(&time_cnt);
	RTC_Time[0] = time_date.tm_year + 1900;
	RTC_Time[1] = time_date.tm_mon + 1;
	RTC_Time[2] = time_date.tm_mday;
	RTC_Time[3] = time_date.tm_hour;
	RTC_Time[4] = time_date.tm_min;
	RTC_Time[5] = time_date.tm_sec;
	
}
