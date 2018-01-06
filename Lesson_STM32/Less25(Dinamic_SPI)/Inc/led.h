#ifndef LED_H_
#define LED_H_

#include "stm32f4xx_hal.h"
#include "main.h"
#include <stdlib.h>
#include <stdio.h>


#define SA_SET aTxBuffer[0]=portseg&=~0x01;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SA_RESET aTxBuffer[0]=portseg|=0x01;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SB_SET aTxBuffer[0]=portseg&=~0x02;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SB_RESET aTxBuffer[0]=portseg|=0x02;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SC_SET aTxBuffer[0]=portseg&=~0x04;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SC_RESET aTxBuffer[0]=portseg|=0x04;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SD_SET aTxBuffer[0]=portseg&=~0x08;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SD_RESET aTxBuffer[0]=portseg|=0x08;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SE_SET aTxBuffer[0]=portseg&=~0x10;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SE_RESET aTxBuffer[0]=portseg|=0x10;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SF_SET aTxBuffer[0]=portseg&=~0x20;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SF_RESET aTxBuffer[0]=portseg|=0x20;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SG_SET aTxBuffer[0]=portseg&=~0x40;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SG_RESET aTxBuffer[0]=portseg|=0x40;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SH_SET aTxBuffer[0]=portseg&=~0x80;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()
#define SH_RESET aTxBuffer[0]=portseg|=0x80;HAL_SPI_Transmit(&hspi3,(uint8_t*)aTxBuffer,1,5000);cs_strob()

void segchar (uint8_t seg);
void ledprint(uint16_t number);


#endif /* LED_H_ */
