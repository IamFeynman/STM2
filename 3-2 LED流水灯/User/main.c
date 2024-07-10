#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main()
{
	
	//GPIO初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//APB2时钟调用函数
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//查找索引
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_All;//GPIO_Pin索引选择member项，GPIO_Pin_All是16个引脚全选
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//GPIO_ResetBits(GPIOA,GPIO_Pin_0);//给低电平
	//GPIO_SetBits(GPIOA,GPIO_Pin_0);//给高电平
	//GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);//最后一个参数可以是Bit_RESET或者Bit_SET，分别给低、高电平，与上两行函数相同
	
	
	while(1)
	{
		GPIO_Write(GPIOA,~0x0001);//0000 0000 0000 0001 由于是低电平点亮，再取反
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0002);//0000 0000 0000 0010
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0004);//0000 0000 0000 0100
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0008);//0000 0000 0000 1000
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0010);//0000 0000 0001 0000
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0020);//0000 0000 0010 0000
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0040);//0000 0000 0100 0000
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0080);//0000 0000 1000 0000
		Delay_ms(500);
		
		
		
	}
	
	
	
}
