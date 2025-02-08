#ifndef _LIB_DS1307_
#define _LIB_DS1307_
//----------------------------------------Include-------------------------------//
#include "main.h"
//------------------------------------------------------------------------------//
#define ADDRESS_DS1307 0x68
//------------------------------------------------------------------------------//
extern I2C_HandleTypeDef hi2c1;
//--------------------------//
//--------------------------//
typedef struct
{
	uint8_t sec;
	uint8_t min;
	uint8_t hours;
	uint8_t date;
	uint8_t day;
	uint8_t month;
	uint8_t year;
	
}DS1307_Name;
//--------------------------//
void rtc_write_time(DS1307_Name *settime);
void rtc_read_time(DS1307_Name *time);
#endif
