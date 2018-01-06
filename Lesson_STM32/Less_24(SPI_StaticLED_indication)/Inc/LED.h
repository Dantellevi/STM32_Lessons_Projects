#ifndef __LED_H
#define __LED_H


#include "stm32f4xx_hal.h"
#include <stdint.h>
#include "main.h"




#define SA_SET  data[0]=portseg|=0x01;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()
#define SA_RESET  data[0]=portseg&=~0x01;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()

#define SB_SET data[0]=portseg|=0x02;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()
#define SB_RESET data[0]=portseg&=~0x02;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()

#define SC_SET data[0]=portseg|=0x04;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()
#define SC_RESET data[0]=portseg&=~0x04;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()

#define SD_SET data[0]=portseg|=0x08;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()
#define SD_RESET data[0]=portseg&=~0x08;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()

#define SE_SET data[0]=portseg|=0x10;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()
#define SE_RESET data[0]=portseg&=~0x10;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()

#define SF_SET data[0]=portseg|=0x20;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()
#define SF_RESET data[0]=portseg&=~0x20;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()

#define SG_SET data[0]=portseg|=0x40;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()
#define SG_RESET data[0]=portseg&=~0x40;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()


#define SDP_SET data[0]=portseg|=0x80;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()
#define SDP_RESET data[0]=portseg&=~0x80;HAL_SPI_Transmit(&hspi3,(uint8_t*)data,1,5000);cs_strob()


void segchar (uint8_t seg);


#endif /* __LED_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

