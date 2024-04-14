/* 
 * File:   rtc_ds1307.c
 * Author: Mohamed Ashraf
 *
 * Created on October 13, 2023, 10:01 AM
 */
#include "rtc_ds1307.h"

static void RTC_DS1307_receive_values(i2c_address_t slave_address);
static void BCD_UART_Print(uint8_t data);
static rtc_t rtc_received;
void RTC_DS1307_print(i2c_address_t slave_address){
    RTC_DS1307_receive_values(slave_address);
    EUSART_Write_String("Date: ");
    BCD_UART_Print(rtc_received._day) ;
    EUSART_Write(':');
    BCD_UART_Print(rtc_received._month) ;
    EUSART_Write(':');
    BCD_UART_Print(rtc_received._year);
    EUSART_Write_String("\r");
    EUSART_Write_String("Time: ");
    BCD_UART_Print(rtc_received._hour);
    EUSART_Write(':');
    BCD_UART_Print(rtc_received._min);
    EUSART_Write(':');
    BCD_UART_Print(rtc_received._sec);
    EUSART_Write_String("\r");
}
static void RTC_DS1307_receive_values(i2c_address_t slave_address){
    rtc_received._sec   = I2C_Read1ByteRegister(slave_address ,0x00);
    __delay_us(100);
    rtc_received._min   = I2C_Read1ByteRegister(slave_address ,0x01);
    __delay_us(100);
    rtc_received._hour  = I2C_Read1ByteRegister(slave_address ,0x02);
    __delay_us(100);
    rtc_received._day   = I2C_Read1ByteRegister(slave_address ,0x04);
    __delay_us(100);
    rtc_received._month = I2C_Read1ByteRegister(slave_address ,0x05);
    __delay_us(100);
    rtc_received._year  = I2C_Read1ByteRegister(slave_address ,0x06);
    __delay_us(100);
}
static void BCD_UART_Print(uint8_t data){
    EUSART_Write((data>>4)+'0');
    EUSART_Write((data&0x0F)+ '0');
}