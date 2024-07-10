#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main()
{
	
	//GPIO初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//APB2时钟调用函数
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//查找索引
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;//GPIO_Pin索引选择member项，GPIO_Pin_All是16个引脚全选
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
		
	
	while(1)
	{
		//GPIO_Write(GPIOB,0x0800);
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
		Delay_ms(100);
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
		Delay_ms(100);
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
		Delay_ms(100);
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
		Delay_ms(700);
		
	}
	
	
	
}
