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
void StoreAckBytes (u8);
u8 FingerPS_CheckAck ();
int main(void)
{  
	UART_Init(); 
	UART_receiveByteAsynchCallBack(StoreAckBytes);   
	sei ();
	FingerPS_AuraLedConfig(); 
	H_Lcd_Void_LCDGoTo(0,0);
	H_Lcd_Void_LCDWriteString((u8*)"PUT A FINGER TO SCAN");
	_delay_ms(4000); /*Delay to get the finger scan*/
	/*********************************************		IMAGE GENERATION	******************************************/
	FingerPS_genImg(); 
	_delay_ms(20); 
	while (FingerPS_CheckAck() == false); /*WAIT FOR ACK*/
	H_Lcd_Void_LCDGoTo(1,0); 
	H_Lcd_Void_LCDWriteString((u8*)"IMAGE GENERATED"); 
	/*********************************************		CHARACTER FILE GENERATION	**********************************/
    FingerPS_convertImg1CharFile();
	_delay_ms(20); 
	while (FingerPS_CheckAck() == false); /*WAIT FOR ACK*/
	H_Lcd_Void_LCDGoTo(2,0);
	H_Lcd_Void_LCDWriteString((u8*)"CHAR1 FILE GENERATED"); 
	FingerPS_convertImg2CharFile();
	_delay_ms(20); 
	while (FingerPS_CheckAck() == false); /*WAIT FOR ACK*/
	H_Lcd_Void_LCDGoTo(3,0);
	H_Lcd_Void_LCDWriteString((u8*)"CHAR2 FILE GENERATED");  
	/********************************************		Generate Tempelate			**********************************/ 
	H_Lcd_Void_LCDClear();
	FingerPS_genTemplate();
	_delay_ms(20);
	while (FingerPS_CheckAck() == false); /*WAIT FOR ACK*/
	H_Lcd_Void_LCDGoTo(0,0);
	H_Lcd_Void_LCDWriteString((u8*)"TEMP GENERATED"); 
	/*******************************************		Tempelate Storing			***********************************/ 
	FingerPS_strTemplate();
	while (FingerPS_CheckAck() == false); /*WAIT FOR ACK*/
	H_Lcd_Void_LCDGoTo(0,0);
	H_Lcd_Void_LCDWriteString((u8*)"TEMP STORED"); 
    while (1) 
    { 
		/*Do nothing*/
    }
} 

