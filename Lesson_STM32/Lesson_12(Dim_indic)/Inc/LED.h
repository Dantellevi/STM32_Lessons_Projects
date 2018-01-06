#ifndef __LED_H
#define __LED_H


#include "stm32f4xx_hal.h"
#include <stdint.h>
#include "main.h"


#define SA GPIO_PIN_7
#define SB GPIO_PIN_8
#define SC GPIO_PIN_9
#define SD GPIO_PIN_10
#define SE GPIO_PIN_11
#define SF GPIO_PIN_12
#define SG GPIO_PIN_13
#define SDP GPIO_PIN_14

#define SA_SET HAL_GPIO_WritePin(GPIOE,SA,GPIO_PIN_SET);
#define SA_RESET HAL_GPIO_WritePin(GPIOE,SA,GPIO_PIN_RESET);

#define SB_SET HAL_GPIO_WritePin(GPIOE,SB,GPIO_PIN_SET);
#define SB_RESET HAL_GPIO_WritePin(GPIOE,SB,GPIO_PIN_RESET);

#define SC_SET HAL_GPIO_WritePin(GPIOE,SC,GPIO_PIN_SET);
#define SC_RESET HAL_GPIO_WritePin(GPIOE,SC,GPIO_PIN_RESET);

#define SD_SET HAL_GPIO_WritePin(GPIOE,SD,GPIO_PIN_SET);
#define SD_RESET HAL_GPIO_WritePin(GPIOE,SD,GPIO_PIN_RESET);

#define SE_SET HAL_GPIO_WritePin(GPIOE,SE,GPIO_PIN_SET);
#define SE_RESET HAL_GPIO_WritePin(GPIOE,SE,GPIO_PIN_RESET);

#define SF_SET HAL_GPIO_WritePin(GPIOE,SF,GPIO_PIN_SET);
#define SF_RESET HAL_GPIO_WritePin(GPIOE,SF,GPIO_PIN_RESET);

#define SG_SET HAL_GPIO_WritePin(GPIOE,SG,GPIO_PIN_SET);
#define SG_RESET HAL_GPIO_WritePin(GPIOE,SG,GPIO_PIN_RESET);


#define SDP_SET HAL_GPIO_WritePin(GPIOE,SDP,GPIO_PIN_SET);
#define SDP_RESET HAL_GPIO_WritePin(GPIOE,SDP,GPIO_PIN_RESET);


void segchar (uint8_t seg);
void ledprint(uint16_t number);

#endif /* __LED_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

