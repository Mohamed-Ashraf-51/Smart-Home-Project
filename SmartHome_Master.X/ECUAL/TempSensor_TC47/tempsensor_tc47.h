/* 
 * File:   tempsensor_tc47.h
 * Author: Mohamed Ashraf
 *
 * Created on October 13, 2023, 10:02 AM
 */

#ifndef TEMPSENSOR_TC47_H
#define	TEMPSENSOR_TC47_H

#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"

uint8_t TEMPSENSOR_TC47_Read(i2c_address_t slave_address);


#endif	/* TEMPSENSOR_TC47_H */

