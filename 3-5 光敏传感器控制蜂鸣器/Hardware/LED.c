#include "stm32f10x.h"                  // Device header

/**
  * @brief  LED初始化
  * @retval 初始化GPIOA口，初始化后LED1-2不亮
  */
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2;//选中GPIOA_1和2口
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);//初始化GPIOA外设
	
	GPIO_SetBits(GPIOA,GPIO_Pin_1 | GPIO_Pin_2);
	
}
/**
  * @brief  LED1点亮
* @retval GPIO_ResetBits();复位函数使LED1点亮
  */
void LED1_ON(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}
void LED1_OFF(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
}
/**
  * @brief  LED1状态转换
  * @retval 按键按下后，LED状态取反（由暗到亮，由亮到暗）
  */
void LED1_turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_1);
	}
	else{
		GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	}
	
}
void LED2_ON(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}
void LED2_OFF(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
}

void LED2_turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2)==0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_2);
	}
	else{
		GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	}
	
}