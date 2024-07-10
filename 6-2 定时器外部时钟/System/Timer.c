#include "stm32f10x.h"                  // Device header

extern uint16_t Num;

void Timer_Init(void)
{
	//开启时钟APB1
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	//选择时基单元的时钟
	TIM_ETRClockMode2Config(TIM2,TIM_ExtTRGPSC_OFF,TIM_ExtTRGPolarity_NonInverted,0x04);//ETR外部时钟模式2
		
	//配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1 ;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period =10-1 ;//自动重装
	TIM_TimeBaseInitStructure.TIM_Prescaler = 1-1;//预分频
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
	
	//对射式红外传感器
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
}

uint16_t Timer_GetCounter(void)
{
	return TIM_GetCounter(TIM2);
}

void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)
	{
		Num++;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
	
	
}


