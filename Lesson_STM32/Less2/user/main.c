#include "main.h"

int main(void)
{
	port_ini();
	while(1)
	{
		//1100
		//0110
		//0011
		//1001
		GPIOD->ODR = (1<<PORTD12)|(1<<PORTD13);//устанавливаем 12,13 пин порт в 1
		delay(2000000);
		GPIOD->ODR = (1<<PORTD13)|(1<<PORTD14);//устанавливаем 13,14 пин порт в 1
		delay(2000000);
		GPIOD->ODR = (1<<PORTD14)|(1<<PORTD15);//устанавливаем 14,15 пин  порт в 1
		delay(2000000);
		GPIOD->ODR = (1<<PORTD12)|(1<<PORTD15);//устанавливаем 12,15 пин порт в 1
		delay(2000000);
		GPIOD->ODR = (1<<PORTD0);//устанавливаем 0 пин порт в 1
		delay(2000000);
	}
}
