#include "stm32f10x.h"                  // Device header
#include "Delay.h"
/**
  * @brief  按键初始化
  * @retval 初始化GPIOB口，按键位置位于B1和B11
  */
void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//初始化时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
}
/**
  * @brief  读取按键数值
* @retval 如果B1按键按下，按键数值为1，如果B11按键按下，按键数值为2，如果都未按下，按键数值为0
  */
uint8_t Key_GetNum(void)
{
	uint8_t Key_Num=0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
	{
		Delay_ms(20);//延时20ms用于按键消抖
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0);//如果不松手，就一直在while循环里
		Delay_ms(20);//延时20ms
		Key_Num=1;
	}
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0);
		Delay_ms(20);
		Key_Num=2;
	}
	return Key_Num;
}

