
#ifndef LCD_H
#define LCD_H
 //-----------------------------
#include "stm32f4xx.h"
//-------------------------------
#define d4_set() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
#define d5_set() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
#define d6_set() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
#define d7_set() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);


#define d4_reset() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
#define d5_reset() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
#define d6_reset() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
#define d7_reset() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);


#define e1 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);//установка Е в 1
#define e0 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);//установка Е в 0

#define rs1 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);//установка rs в 1
#define rs0 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);//установка rs в 0
//------------------------------------------
void LCD_ini(void);
//------------------------------------------
void LCD_clear(void);
//------------------------------------------
void LCD_printchar(char ch);
//------------------------------------------
void LCD_printstring(char* str);
//------------------------------------------
void LCD_GOTOXY(uint8_t x, uint8_t y);
//------------------------------------------




#endif /* LCD_H */


