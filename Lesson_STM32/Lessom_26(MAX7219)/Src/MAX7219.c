#include "MAX7219.h"
#include <stdio.h>
#include <stdlib.h>


uint8_t aTxBuf[1]={0};
extern SPI_HandleTypeDef hspi3;


char dg=8;


#define cs_set() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET)
#define cs_reset() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET)
#define cs_strob() cs_reset();cs_set()


void Send7319(uint8_t rg,uint8_t dt )
{
	cs_set();
	aTxBuf[0]=rg;
	HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuf,1,5000);
	aTxBuf[0]=dt;
	HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuf,1,5000);
	cs_reset();
}


void Clear_7319(void)
{
	uint8_t i=dg;
	do{
		Send7319(i,0xF);//пустой символ выводим!!!
	}while(--i);
}

void Number_7319(volatile long n)
{
	uint8_t ng=0;//переменная для минуса
	if(n<0)
	{
		ng=1;
		n*=-1;
		
	}
	uint8_t i=0;
	do{
		Send7319(++i,n%10);//символ цифры
		n/=10;
		
	}while(n);
	
	if(ng)
	{
		Send7319(i+1,0x0A);//символ
	}
}

void Init_7319(void)
{
	 Send7319(0x09,0xFF);//включим режим декодирования
        Send7319(0x0B,dg-1);//кол-во используемых разрядов
        Send7319(0x0A,0x02);//интенсивность свечения
        Send7319(0x0C,0x01);//включим индикатор
         Clear_7319();
}

void Number_Float_7219 (float n)
{
 uint8_t ng=0;//переменная для минуса
 if(n<0)
 {
  ng=1;
  n*=-1;
 };
        int celaya = (int) n;   // выделяем целу часть из числа;
        int drobnaya = (int) ((n-celaya)*100); //выделяем дробную часть из числа
        // здесь два дробных разряда: *100, если надо три: *1000 и тд, или переменной. 
         uint8_t i=0;

        do //вывод дробной части
 {
  Send7319(++i,drobnaya%10);//символ цифры
  drobnaya/=10;
 } while(drobnaya);
        // вывод точки - добавить старший разряд D7=1-засвечивает точку(+128 к значению в регистр).
        Send7319(++i,celaya%10+128);//символ цифры с точкой
 celaya/=10;

        do //вывод целой части со второго слева символа
 {
  Send7319(++i,celaya%10);//символ цифры
  celaya/=10;
        } while(celaya);
 if(ng)
 {
  Send7319(i+1,0x0A);//символ -
 }
}

