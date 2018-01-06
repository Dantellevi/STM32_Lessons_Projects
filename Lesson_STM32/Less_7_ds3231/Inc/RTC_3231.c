#include "RTC_3231.h"

uint8_t RTC_convertFromDec(uint8_t data)
{
	uint8_t ch=((data>>4)*10+(0x0F&data));
	return ch;
}


uint8_t RTC_convertFromBinDec(uint8_t data)
{
	uint8_t ch=(((data/10)<<4)|(data%10));
	return ch;
}
