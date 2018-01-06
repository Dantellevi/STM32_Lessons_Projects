#ifndef MAIN_H_
#define MAIN_H_

#include "stm32f4xx.h"
#include "ports.h"

void port_ini(void);
void delay(int n);

void port_ini(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; //������� ������������ �����
	GPIOD->MODER = 0x55000001; //������� ����� 12-15 �� �����
	GPIOD->OTYPER = 0; //������� ������������� ������������� �� ���� ����
	GPIOD->OSPEEDR = 0; //��������� �������� LOW �� ��� ����� �����
}

void delay(int n)
{
	while(n>0) n--;
}

#endif /* MAIN_H_ */
