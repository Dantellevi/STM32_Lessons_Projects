#include "lcd.h"
//------------------------------------------

uint8_t buf[1]={0};
 extern I2C_HandleTypeDef hi2c1;
char str1[100];
uint8_t portlcd;//ячейка для хранения данных порта микросхемы расширения

__STATIC_INLINE void DelayMicro(__IO uint32_t micros)
{
	micros*=(SystemCoreClock/1000000)/5;
}

//------------------------------------------

void LCD_WriteByteI2C(uint8_t data)
{
	buf[0]=data;
	HAL_I2C_Master_Transmit(&hi2c1,(uint16_t)0x4E,buf,1,1000);
	
}
//---------------------------------



//---------------------------------

//---------------------------------
void sendhalfbyte(uint8_t c)
{
	c<<=4;
	e_set();//включаем линию Е
	DelayMicro(50);
	LCD_WriteByteI2C(portlcd|c);
	e_reset();
	DelayMicro(50);
}

void sendbyte(uint8_t c,uint8_t mode)
{
	if(mode==0) rs_reset();
	else rs_set();
	
	uint8_t hc=0;
	hc=c>>4;
	sendhalfbyte(hc);
	sendhalfbyte(c);
	
}

//---------------------------------
void LCD_clear(void)
{
	sendbyte(0x01,0);//убираем мусор 
	HAL_Delay(2);
	
}

//---------------------------------
void LCD_printchar(char ch)
{
	sendbyte(ch,1);
	
	
	
}

//---------------------------------
void LCD_GOTOXY(uint8_t x, uint8_t y)
{
	switch(y)
	{
		case 0:
			sendbyte(x|0x80,0);
			HAL_Delay(1);
			break;
		
		case 1:
			sendbyte((0x40+x)|0x80,0);
			HAL_Delay(1);
			break;
		
		case 2:
			sendbyte((0x14+x)|0x80,0);
			HAL_Delay(1);
			break;
		
		case 3:
			sendbyte((0x54+x)|0x80,0);
			HAL_Delay(1);
			break;
		
		
		
		
	}
	
	
	
}
//---------------------------------
void LCD_printstring(char* str)
{
	uint8_t i=0;
	while(str[i]!=0)
	{
		sendbyte(str[i],1);
	
		i++;
	}
	
	
	
}

//---------------------------------



void LCD_ini(void)
{
	HAL_Delay(15);
	sendhalfbyte(0x03);
	HAL_Delay(4);

	sendhalfbyte(0x03);
	DelayMicro(100);
	
	sendhalfbyte(0x03);
	HAL_Delay(1);
	sendhalfbyte(0x02);
	HAL_Delay(1);
	sendbyte(0x28,0); //4бит-режим (DL=0) и 2 линии (N=1)
	HAL_Delay(1);
	
		
	sendbyte(0x0C,0);//включаем изображение на дисплее (D=1), курсоры никакие не включаем (C=0, B=0)
	HAL_Delay(1);
	
	sendbyte(0x01,0);//убираем мусор
	HAL_Delay(2);
	
	sendbyte(0x06,0);//курсор (хоть он у нас и невидимый) будет двигаться влево
	HAL_Delay(1);
	setled();////подсветка
	setwrite();//запись
	
}





