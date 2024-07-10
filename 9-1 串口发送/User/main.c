#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "Serial.h"

int main()
{
	OLED_Init();
	Serial_Init();

	//char str[] = "Hello";
	//Serial_SendString(str);
	//Serial_SendNumber(12345,5);
	//printf("Num = %d\r\n",666);
	
	//char string[100];
	//sprintf(string,"Num = %d\r\n",686);
	//Serial_SendString(string);
	Serial_Printf("你好，世界！\r\n");
	while(1)
	{
		
	}
	
	
	
}
