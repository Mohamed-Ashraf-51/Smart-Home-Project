/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K20
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "ECUAL/EXT_EEPROM_24C02C/ext_eeprom_24c02c.h"
#include "ECUAL/RTC_DS1307/rtc_ds1307.h"
#include "ECUAL/TempSensor_TC47/tempsensor_tc47.h"

#define EEPROM1_SLAVE_ADDRESS    0x51
#define TC47_SLAVE_ADDRESS       0x4F
#define RTC_SLAVE_ADDRESS        0x68
#define MCU2_SLAVE_ADDRESS       0x60
/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    uint8_t TempSensor_Val = 0;
    uint8_t Temp_Set_Value =25;
    EXT_EEPROM_24C02C_write(EEPROM1_SLAVE_ADDRESS,0x00,Temp_Set_Value);
    /*I will put keypad and attach all columns with one interrupt pin If I pressed 
     *       I will go to handler and check each row then take the value and put it in EEPROM
              */
    while (1)
    {
        RTC_DS1307_print(RTC_SLAVE_ADDRESS);
        TempSensor_Val = TEMPSENSOR_TC47_Read(TC47_SLAVE_ADDRESS);
        Temp_Set_Value = EXT_EEPROM_24C02C_read(EEPROM1_SLAVE_ADDRESS,0x00);
        if(TempSensor_Val >Temp_Set_Value){
            I2C_Write1ByteRegister(MCU2_SLAVE_ADDRESS,0x00,'o');
            
        }
        else{
            I2C_Write1ByteRegister(MCU2_SLAVE_ADDRESS,0x00,'c');
        }
        
        __delay_ms(1000);
    }
}
/**
 End of File
*/