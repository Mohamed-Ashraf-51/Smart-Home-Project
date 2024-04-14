/* 
 * File:   tempsensor_tc47.h
 * Author: Mohamed Ashraf
 *
 * Created on October 13, 2023, 10:02 AM
 */
#include "tempsensor_tc47.h"

uint8_t TEMPSENSOR_TC47_Read(i2c_address_t slave_address){
    uint8_t value = 0;
    value = I2C_Read1ByteRegister(slave_address,0x00);
    __delay_us(100);
    
    return value;
}
