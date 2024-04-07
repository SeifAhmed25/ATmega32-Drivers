/*
 * R503_ATmegaDriver.c
 *
 * Created: 3/22/2024 8:16:22 PM
 * Author : seif
 */ 

#include "UART_Interface.h"
#include "LCD_Interface.h"
#include "FingerPrint_Interface.h"
#include "util\delay.h" 

int main(void)
{  
	H_Lcd_Void_LCDInit();
	UART_Init(); 
	UART_receiveByteAsynchCallBack(StoreAckBytes);   
	u8 FingerPrintAddress = 10;  
	sei ();
	/*******************************************		Starting with an AURA Wink (;				********************/
	FingerPS_AuraLedConfig(); 
	H_Lcd_Void_LCDGoTo(0,0);
	H_Lcd_Void_LCDWriteString((u8*)"PUT  FINGER TO SCAN");
	_delay_ms(4000); /*Delay to get the finger scan*/ 
	/******************************************		Here we are Setting a New Finger Print		********************/ 
	FingerPS_SetNewFingerPrint (FingerPrintAddress); 
	H_Lcd_Void_LCDClear(); 
	H_Lcd_Void_LCDWriteString((u8*)"NEW FINGER SAVED");
	_delay_ms(3000); 
	/******************************************		Check a One to One Match					********************/ 
	H_Lcd_Void_LCDClear(); 
	H_Lcd_Void_LCDWriteString((u8*)"PUT FING TO CH MATCH");
	if (FingerPS_CheckOneToOneMatch(FingerPrintAddress) == MATCHED){ 
			H_Lcd_Void_LCDClear();
			H_Lcd_Void_LCDWriteString((u8*)"MATCHED"); 
		}
	else {
			H_Lcd_Void_LCDClear();
			H_Lcd_Void_LCDWriteString((u8*)"NOT MATCHED");		
	}
	while (1) 
    { 
		/*Do nothing*/
    }
} 

