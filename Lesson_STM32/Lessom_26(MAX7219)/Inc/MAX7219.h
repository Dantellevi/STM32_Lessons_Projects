
#ifndef __MAX7219_H
#define __MAX7219_H

#include "main.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void Send7319(uint8_t rg,uint8_t dt );
void Clear_7319(void);
void Number_7319(volatile long n);
void Init_7319(void);	
void Number_Float_7219 (float n);
#endif /* __MAX7219_H */

