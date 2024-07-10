#include "stm32f10x.h"                  // Device header

uint16_t CountSensor_Count=0;

void CountSensor_Init(void)
{	//GPIO、AFIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//开启GPIO时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//开启AFIO时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//浮空输入/上拉输入/下拉输入都可以，这里选择上拉输入
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
	//外部中断EXTI的配置
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line=EXTI_Line14;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发、上升沿触发三种方法都可以
	
	EXTI_Init(&EXTI_InitStructure);
	//NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStructure);
	
}
uint16_t CountSensor_Get(void)
{
	return CountSensor_Count;
	
}

void EXTI15_10_IRQHandler(void)//Interrupt
{
	if(EXTI_GetFlagStatus(EXTI_Line14)==SET)//检验状态，是否中断进入Line14
	{
		CountSensor_Count++;
		EXTI_ClearITPendingBit(EXTI_Line14);//清除中断标志位
	}
	
	
}



