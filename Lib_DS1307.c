#include "Lib_DS1307.h"
#include <string.h>
//-------------------------------------------------------------------------------------------------------//
char date_string[8][4] ={"   ","MON","TUE","WED","THU","FRI","SAT","SUN"};
char date_of_week[4];
//-------------------------------------------------------------------------------------------------------//
uint8_t Decima12BCD(uint8_t num) // doi thap phan sang BCD
{
	return (num/10)<<4|(num%10);
}
//-------------------------------------------------------------------------------------------------------//
uint8_t BCD2Decimal(uint8_t num)	//doi BCD sang thap phan
{
	return (num>>4)*10 +(num&0x0F);
}
//-------------------------------------------------------------------------------------------------------//
void rtc_write_time(DS1307_Name *settime)  // ghi thoi gian
{
		uint8_t data_write[7] ={Decima12BCD(settime->sec),Decima12BCD(settime->min),Decima12BCD(settime->hours),
		Decima12BCD(settime->date),Decima12BCD(settime->day),Decima12BCD(settime->month),Decima12BCD(settime->year)};
		HAL_I2C_Mem_Write(&hi2c1,ADDRESS_DS1307<<1,0x00,I2C_MEMADD_SIZE_8BIT ,data_write,7,100);
}
//-------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------//
void rtc_read_time(DS1307_Name *time) //doc thoi gian
{
	
	uint8_t data_read[7];
	HAL_I2C_Mem_Read(&hi2c1,ADDRESS_DS1307<<1,0x00,I2C_MEMADD_SIZE_8BIT ,data_read,7,100);
	time->year = BCD2Decimal(data_read[6]);
	time->month = BCD2Decimal(data_read[5]);
	time->day = BCD2Decimal(data_read[4]);
	time->date = BCD2Decimal(data_read[3]);
	time->hours = BCD2Decimal(data_read[2]);
	time->min = BCD2Decimal(data_read[1]);
	time->sec = BCD2Decimal(data_read[0]);
	strcpy(date_of_week ,date_string[time->date]);
}
//-------------------------------------------------------------------------------------------------------//

