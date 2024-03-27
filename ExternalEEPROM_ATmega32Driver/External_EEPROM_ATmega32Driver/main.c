/*
 * External_EEPROM_ATmega32Driver.c
 *
 * Created: 3/27/2024 3:41:45 PM
 * Author : seif
 */ 
#include "EEPROM_Interfac.h" 
#include "LCD_Interface.h"

int main(void)
{	M_Void_I2C_Init(); 
	H_Lcd_Void_LCDInit(); 
	/*EEPROM TEST*/
	u8 start_address = 0x1A;
	u8 i,WriteArr [20] = "EEPROM TEST";  
	for (i = 0; i < 11; i++){
		H_Void_EEPROMWrite(start_address + i, WriteArr[i]);
		 _delay_ms(10); 
	}  
	for (i=0; i < 11 ; i++){ 
		H_Lcd_Void_LCDWriteCharacter(H_Void_EEPROMRead(start_address+i)); 
		_delay_ms(10); 
	}
    while (1) 
    {
		/*DO NOTHING*/
    }
}

