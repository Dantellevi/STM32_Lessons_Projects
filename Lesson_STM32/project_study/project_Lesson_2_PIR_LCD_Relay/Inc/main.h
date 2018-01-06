
#ifndef __MAIN_H
#define __MAIN_H
 
 #include "lcd.h"
 
 
 #define PIR_input HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8);
 
 #define Out_relay_ON HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_SET);
 #define Out_relay_OFF HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

