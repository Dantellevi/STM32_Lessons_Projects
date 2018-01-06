#include "main.h"

int main(void)
{
	port_ini();
	while(1)
	{
		
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1)
		{
		GPIO_SetBits(GPIOD,GPIO_Pin_0);
		delay(1000000);
		GPIO_ResetBits(GPIOD,GPIO_Pin_9);
		GPIO_SetBits(GPIOD,GPIO_Pin_1);
		delay(1000000);
		
		GPIO_ResetBits(GPIOD,GPIO_Pin_0);
		GPIO_SetBits(GPIOD,GPIO_Pin_2);
		delay(1000000);
		
		GPIO_ResetBits(GPIOD,GPIO_Pin_1);
		GPIO_SetBits(GPIOD,GPIO_Pin_3);
		delay(1000000);
		
		GPIO_ResetBits(GPIOD,GPIO_Pin_2);
		GPIO_SetBits(GPIOD,GPIO_Pin_4);
		delay(1000000);
		
		GPIO_ResetBits(GPIOD,GPIO_Pin_3);
		GPIO_SetBits(GPIOD,GPIO_Pin_5);
		delay(1000000);
		
		GPIO_ResetBits(GPIOD,GPIO_Pin_4);
		GPIO_SetBits(GPIOD,GPIO_Pin_6);
		delay(1000000);
		
		GPIO_ResetBits(GPIOD,GPIO_Pin_5);
		GPIO_SetBits(GPIOD,GPIO_Pin_7);
		delay(1000000);
		
		GPIO_ResetBits(GPIOD,GPIO_Pin_6);
		GPIO_SetBits(GPIOD,GPIO_Pin_8);
		delay(1000000);
		
		GPIO_ResetBits(GPIOD,GPIO_Pin_7);
		GPIO_SetBits(GPIOD,GPIO_Pin_9);
		delay(1000000);
		GPIO_ResetBits(GPIOD,GPIO_Pin_8);
		
		}
		else{
			
		GPIO_ResetBits(GPIOD,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|
	GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9);
			
			
		}
	

		
	}
}
