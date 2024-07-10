#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//复用推挽输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);//初始化GPIOA外设
	
	
	//选择时基单元的时钟
	TIM_InternalClockConfig(TIM2);//使用内部时钟
	
	//配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1 ;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period =100-1 ;			//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 36-1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter =0 ;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse =  50;						//CCR
	TIM_OC3Init(TIM2,&TIM_OCInitStructure);
	
	
	//启动定时器
	TIM_Cmd(TIM2,ENABLE);
}
/**
  * @brief  配置PWM通道x的寄存器值，也就是调整CCR值来控制PWM波占空比
  * @param uint16_t Compare
  * @retval 无
  */

void PWM_SetCompare3(uint16_t Compare)//调整CCR值
{
	TIM_SetCompare3(TIM2,Compare);
}

	
