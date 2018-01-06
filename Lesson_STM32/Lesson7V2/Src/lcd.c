#include "lcd.h"
//------------------------------------------
void delay(void)
{
	uint16_t i;
	for(i=0;i<1000;i++)
	{
		
	}
}

//------------------------------------------

void LCD_WriteData(uint8_t data)
{
	//++++++++++++++++++++++++++++
	if(((data>>3)&0x01)==1)
	{
		d7_set();
	}
	else
	{
		d7_reset();
		
		
	}
	//++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++
	if(((data>>2)&0x01)==1)
	{
		d6_set();
	}
	else
	{
		d6_reset();
		
		
	}
	//++++++++++++++++++++++++++++	
	//++++++++++++++++++++++++++++
	if(((data>>1)&0x01)==1)
	{
		d5_set();
	}
	else
	{
		d5_reset();
		
		
	}
	//++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++
	if((data&0x01)==1)
	{
		d4_set();
	}
	else
	{
		d4_reset();
		
		
	}
	//++++++++++++++++++++++++++++	
	
	
}
//---------------------------------

void LCD_Command(uint8_t data)
{
	rs0;
	LCD_WriteData(data>>4);
	e1;
	delay();
	e0;
	LCD_WriteData(data);
	e1;
	delay();
	e0;
	
}

//---------------------------------

//---------------------------------

void LCD_Data(uint8_t data)
{
	rs1;
	LCD_WriteData(data>>4);
	e1;
	delay();
	e0;
	LCD_WriteData(data);
	e1;
	delay();
	e0;
	
}

//---------------------------------
void LCD_clear(void)
{
	LCD_Command(0x01);//убираем мусор 
	HAL_Delay(2);
	
}

//---------------------------------
void LCD_printchar(char ch)
{
	LCD_Data((uint8_t)ch);//убираем мусор 
	delay();
	
	
}

//---------------------------------
void LCD_GOTOXY(uint8_t x, uint8_t y)
{
	switch(y)
	{
		case 0:
			LCD_Command(x|0x80);
			HAL_Delay(1);
			break;
		
		case 1:
			LCD_Command((0x40+x)|0x80);
			HAL_Delay(1);
			break;
		
		case 2:
			LCD_Command((0x14+x)|0x80);
			HAL_Delay(1);
			break;
		
		case 3:
			LCD_Command((0x54+x)|0x80);
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
		LCD_Data(str[i]);
		delay();
		i++;
	}
	
	
	
}

//---------------------------------



void LCD_ini(void)
{
	HAL_Delay(40);
	rs0;
	LCD_WriteData(3);
	e1;
	delay();
	e0;
	HAL_Delay(1);
	
	HAL_Delay(40);
	rs0;
	LCD_WriteData(3);
	e1;
	delay();
	e0;
	HAL_Delay(1);
	
	HAL_Delay(40);
	rs0;
	LCD_WriteData(3);
	e1;
	delay();
	e0;
	HAL_Delay(1);
	LCD_Command(0x28);//режим 4бита 
	HAL_Delay(1);
	LCD_Command(0x28);//режим 4бита 
	HAL_Delay(1);
	LCD_Command(0x0F);//включаем дисплей 
	HAL_Delay(1);
	LCD_Command(0x01);//убираем мусор 
	HAL_Delay(2);
	LCD_Command(0x06);//пишем влево
	HAL_Delay(2);
	LCD_Command(0x02);//возвращаем курсор
	HAL_Delay(2);
	
	
}





