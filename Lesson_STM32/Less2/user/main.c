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
		GPIOD->ODR = (1<<PORTD12)|(1<<PORTD13);//������������� 12,13 ��� ���� � 1
		delay(2000000);
		GPIOD->ODR = (1<<PORTD13)|(1<<PORTD14);//������������� 13,14 ��� ���� � 1
		delay(2000000);
		GPIOD->ODR = (1<<PORTD14)|(1<<PORTD15);//������������� 14,15 ���  ���� � 1
		delay(2000000);
		GPIOD->ODR = (1<<PORTD12)|(1<<PORTD15);//������������� 12,15 ��� ���� � 1
		delay(2000000);
		GPIOD->ODR = (1<<PORTD0);//������������� 0 ��� ���� � 1
		delay(2000000);
	}
}
