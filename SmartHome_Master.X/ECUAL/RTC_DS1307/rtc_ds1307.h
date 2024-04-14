/* 
 * File:   rtc_ds1307.h
 * Author: Mohamed Ashraf
 *
 * Created on October 13, 2023, 10:01 AM
 */

#ifndef RTC_DS1307_H
#define	RTC_DS1307_H

#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"

typedef struct{
    uint8_t _day;
    uint8_t _month;
    uint8_t _year;
    uint8_t _sec;
    uint8_t _min;
    uint8_t _hour;
}rtc_t;

void RTC_DS1307_print(i2c_address_t slave_address);

#endif	/* RTC_DS1307_H */

