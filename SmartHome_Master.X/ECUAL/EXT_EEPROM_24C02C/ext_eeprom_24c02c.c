/* 
 * File:   ext_eeprom_24c02c.c
 * Author: Mohamed Ashraf Helmey
 *
 * Created on October 13, 2023, 9:58 AM
 */

#include "ext_eeprom_24c02c.h"  

void EXT_EEPROM_24C02C_write(i2c_address_t slave_address,uint8_t location_address , uint8_t data){
    I2C_Write1ByteRegister (slave_address,location_address,data);
}
uint8_t EXT_EEPROM_24C02C_read(i2c_address_t slave_address,uint8_t location_address ){
    uint8_t data =0;
    data  = I2C_Read1ByteRegister(slave_address,location_address);
    
    return data;
}
