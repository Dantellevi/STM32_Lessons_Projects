#include "LED.h"
extern uint8_t data[1];
extern SPI_HandleTypeDef hspi3;
/* USER CODE BEGIN Includes */
#define cs_set() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET)
#define cs_reset() HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET)
#define cs_strob() cs_reset();cs_set()
/* USER CODE END Includes */


uint8_t portseg=0;


void segchar (uint8_t seg)
{
	
	switch(seg)
	{
		case 1:
		SA_RESET;
		SB_SET;
		SC_SET;
		SD_RESET;
		SE_RESET;
		SF_RESET;
		SG_RESET;
		SDP_RESET;		
		break;
		
		case 2:
		SA_SET;
		SB_SET;
		SC_RESET;
		SD_SET;
		SE_SET;
		SF_RESET;
		SG_SET;
		SDP_RESET;	
		
		break;
		
		case 3:
			
		SA_SET;
		SB_SET;
		SC_SET;
		SD_SET;
		SE_RESET;
		SF_RESET;
		SG_SET;
		SDP_RESET;
		
		
		break;
		
		case 4:
			
		SA_RESET;
		SB_SET;
		SC_SET;
		SD_RESET;
		SE_RESET;
		SF_SET;
		SG_SET;
		SDP_RESET;
		
		
		break;
		
		case 5:
			
		SA_SET;
		SB_RESET;
		SC_SET;
		SD_SET;
		SE_RESET;
		SF_SET;
		SG_SET;
		SDP_RESET;
		
		break;
		
		case 6:
			
		SA_SET;
		SB_RESET;
		SC_SET;
		SD_SET;
		SE_SET;
		SF_SET;
		SG_SET;
		SDP_RESET;
		
		break;
		
		case 7:
			
		SA_SET;
		SB_SET;
		SC_SET;
		SD_RESET;
		SE_RESET;
		SF_RESET;
		SG_RESET;
		SDP_RESET;
		
		break;
		
		case 8:
		SA_SET;
		SB_SET;
		SC_SET;
		SD_SET;
		SE_SET;
		SF_SET;
		SG_SET;
		SDP_RESET;	
		
		
		break;
		
		case 9:
		SA_SET;
		SB_SET;
		SC_SET;
		SD_SET;
		SE_RESET;
		SF_SET;
		SG_SET;
		SDP_RESET;	
		
		break;
		
		case 0:
			SA_SET;
		SB_SET;
		SC_SET;
		SD_SET;
		SE_SET;
		SF_SET;
		SG_RESET;
		SDP_RESET;	
		
		
		
		
		
		
		
	}
}
