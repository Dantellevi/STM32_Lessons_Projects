#ifndef __ILI9341_H
#define __ILI9341_H
 
 //++++++++++++++++++++++++++++
 #include "main.h"
 #include <stdlib.h>
 #include "stm32f4xx_hal.h"
 #include "lcd.h"


#include <stdio.h>



//+++++++++++++++++++++++++++++

//=====================================
#define ADDR_CMD        *(uint8_t*)0x60000000
#define ADDR_DATA        *(uint8_t*)0x60010000


#define swap(a,b) {int16_t t=a;a=b;b=t;}
#define  RESET_ACTIVE   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
#define  RESET_IDLE   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
 
#define  BLACK 0x0000
#define  BLUE 0x001F
#define  RED 0x0F800
#define  GREEN 0x07E0
#define  CYAN 0x07FF
#define  MAGENTA 0xF81F
#define  YELLOW 0xFFE0
#define  WHITE 0xFFFF


#define  BLACK 0x0000
#define  BLUE 0x001F
#define  RED 0x0F800
#define  GREEN 0x07E0
#define  CYAN 0x07FF
#define  MAGENTA 0xF81F
#define  YELLOW 0xFFE0
#define  WHITE 0xFFFF


//=======================================
void TFT9341_ini(void);

void TFT9341_FillScreen(uint16_t color);

uint16_t TFT9341_RandColor(void);

void TFT9341_FillRectangle(uint16_t color, uint16_t x1, uint16_t y1,
                                                         uint16_t x2, uint16_t y2);

void TFT9341_DrawPixel(int x, int y, uint16_t color);


void TFT9341_DrawLine(uint16_t color, uint16_t x1, uint16_t y1,
                                                         uint16_t x2, uint16_t y2);

void TFT9341_DrawRect(uint16_t color, uint16_t x1, uint16_t y1,
                                                         uint16_t x2, uint16_t y2);

void TFT9341_DrawCircle(uint16_t x0, uint16_t y0, int r, uint16_t color);

void TFT9341_FontsIni(void);
//=======================================

#endif /* __ILI9341_H */
