#ifndef MAIN_H_
#define MAIN_H_

#include "stm32f4xx.h"
#include "ports.h"

void port_ini(void);
void delay(int n);

void port_ini(void)
{
	GPIO_InitTypeDef InitD;//инициализация светодиодов(тактирование)
	GPIO_InitTypeDef InitA;//инициализация кнопки(тактирование)
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);//включение тактирования порта
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);//включение тактирования порта

	//светодиоды 
	InitD.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|
	GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	
	InitD.GPIO_Mode=GPIO_Mode_OUT;
	InitD.GPIO_OType=GPIO_OType_PP;
	InitD.GPIO_PuPd=GPIO_PuPd_NOPULL;
	InitD.GPIO_Speed=GPIO_Speed_2MHz;
		GPIO_Init(GPIOD,&InitD);//инициализация ножек порта для светодиодов
	
	//кнопка
	InitA.GPIO_Pin=GPIO_Pin_0;
	
	InitA.GPIO_Mode=GPIO_Mode_IN;
	InitA.GPIO_OType=GPIO_OType_OD;
	InitA.GPIO_PuPd=GPIO_PuPd_NOPULL;
	InitA.GPIO_Speed=GPIO_Speed_2MHz;
	GPIO_Init(GPIOA,&InitA);//инициализация ножек порта для кнопки
	
	

	
	
}

void delay(int n)
{
	while(n>0) n--;
}

#endif /* MAIN_H_ */
