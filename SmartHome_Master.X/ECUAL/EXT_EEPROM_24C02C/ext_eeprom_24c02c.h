/* 
 * File:   ext_eeprom_24c02c.h
 * Author: moham
 *
 * Created on October 13, 2023, 9:58 AM
 */

#ifndef EXT_EEPROM_24C02C_H
#define	EXT_EEPROM_24C02C_H

#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"

void EXT_EEPROM_24C02C_write(i2c_address_t slave_address,uint8_t location_address , uint8_t data);
uint8_t EXT_EEPROM_24C02C_read(i2c_address_t slave_address,uint8_t location_address );

#endif	/* EXT_EEPROM_24C02C_H */

