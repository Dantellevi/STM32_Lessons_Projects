
#ifndef __MAIN_H
#define __MAIN_H
 

void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)

#include "stm32f3xx_hal.h"
#include "lsd303dlh.h"
#include <stdint.h>
#define LD_PORT GPIOE
#define LD3 GPIO_PIN_9 //RED1
#define LD4 GPIO_PIN_8 //BLUE1
#define LD5 GPIO_PIN_10 //ORANGE1
#define LD6 GPIO_PIN_15 //GREEN1
#define LD7 GPIO_PIN_11 //GREEN2
#define LD8 GPIO_PIN_14 //ORANGE2
#define LD9 GPIO_PIN_12 //BLUE2
#define LD10 GPIO_PIN_13 //RED2
#define LD3_ON HAL_GPIO_WritePin(LD_PORT, LD3, GPIO_PIN_SET) //RED1
#define LD4_ON HAL_GPIO_WritePin(LD_PORT, LD4, GPIO_PIN_SET) //BLUE1
#define LD5_ON HAL_GPIO_WritePin(LD_PORT, LD5, GPIO_PIN_SET) //ORANGE1
#define LD6_ON HAL_GPIO_WritePin(LD_PORT, LD6, GPIO_PIN_SET) //GREEN1
#define LD7_ON HAL_GPIO_WritePin(LD_PORT, LD7, GPIO_PIN_SET) //GREEN2
#define LD8_ON HAL_GPIO_WritePin(LD_PORT, LD8, GPIO_PIN_SET) //ORANGE2
#define LD9_ON HAL_GPIO_WritePin(LD_PORT, LD9, GPIO_PIN_SET) //BLUE2
#define LD10_ON HAL_GPIO_WritePin(LD_PORT, LD10, GPIO_PIN_SET) //RED2
#define LD3_OFF HAL_GPIO_WritePin(LD_PORT, LD3, GPIO_PIN_RESET) //RED1
#define LD4_OFF HAL_GPIO_WritePin(LD_PORT, LD4, GPIO_PIN_RESET) //BLUE1
#define LD5_OFF HAL_GPIO_WritePin(LD_PORT, LD5, GPIO_PIN_RESET) //ORANGE1
#define LD6_OFF HAL_GPIO_WritePin(LD_PORT, LD6, GPIO_PIN_RESET) //GREEN1
#define LD7_OFF HAL_GPIO_WritePin(LD_PORT, LD7, GPIO_PIN_RESET) //GREEN2
#define LD8_OFF HAL_GPIO_WritePin(LD_PORT, LD8, GPIO_PIN_RESET) //ORANGE2
#define LD9_OFF HAL_GPIO_WritePin(LD_PORT, LD9, GPIO_PIN_RESET) //BLUE2
#define LD10_OFF HAL_GPIO_WritePin(LD_PORT, LD10, GPIO_PIN_RESET) //RED2


#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


