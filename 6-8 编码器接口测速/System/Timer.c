#include "stm32f10x.h"                  // Device header

void Timer_Init(void)
{
	//开启时钟APB1
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	//选择时基单元的时钟
	TIM_InternalClockConfig(TIM2);//使用内部时钟
	
	//配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1 ;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period =10000-1 ;//自动重装
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200-1;//预分频
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter =0 ;
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	
	//使能更新中断
	TIM_ClearFlag(TIM2,TIM_IT_Update);//清除挂起标志，避免定义完就进入中断
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	
	//配置NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	
	NVIC_Init(&NVIC_InitStructure);
	
	//启动定时器
	TIM_Cmd(TIM2,ENABLE);
	
}

/*void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)
	{
		Num++;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}*/


