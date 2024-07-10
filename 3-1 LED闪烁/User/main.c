#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main()
{
	
	//GPIO初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);//APB2时钟调用函数
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//查找索引
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;//选择member那一项
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOG,&GPIO_InitStructure);
	
	//GPIO_ResetBits(GPIOA,GPIO_Pin_0);//给低电平
	//GPIO_SetBits(GPIOA,GPIO_Pin_0);//给高电平
	GPIO_WriteBit(GPIOG,GPIO_Pin_8,Bit_RESET);//最后一个参数可以是Bit_RESET或者Bit_SET，分别给低、高电平，与上两行函数相同
	
	
	while(1)
	{
		//GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		GPIO_WriteBit(GPIOG,GPIO_Pin_8,Bit_RESET);//点亮LED
		Delay_ms(500);//500ms Delay函数
		//GPIO_SetBits(GPIOA,GPIO_Pin_0);
		GPIO_WriteBit(GPIOG,GPIO_Pin_8,Bit_SET);//熄灭LED
		Delay_ms(500);
		
	}
	
	
	
}
