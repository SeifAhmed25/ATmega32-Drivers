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
	sei ();
	FingerPS_AuraLedConfig(); 
	H_Lcd_Void_LCDGoTo(0,0);
	H_Lcd_Void_LCDWriteString((u8*)"PUT A FINGER TO SCAN");
	_delay_ms(4000); /*Delay to get the finger scan*/
	/*********************************************		FIRST IMAGE GENERATION	******************************************/
	RepeatGenImag1:
	FingerPS_genImg(); 
	_delay_ms(100); 
	if (FingerPS_CheckAck() == false) goto RepeatGenImag1; /*WAIT FOR ACK*/
	H_Lcd_Void_LCDGoTo(1,0);
	H_Lcd_Void_LCDWriteString((u8*)"FIRST IMAGE GEN"); 
	/*********************************************	FIRST CHARACTER FILE GENERATION	**************************************/
	RepeatConvertFile1:
	FingerPS_convertImg1CharFile();
	_delay_ms(100); 
	if (FingerPS_CheckAck() == false) goto RepeatConvertFile1; /*WAIT FOR ACK*/
	H_Lcd_Void_LCDGoTo(2,0);
	H_Lcd_Void_LCDWriteString((u8*)"CHAR1 FILE GEN"); 
	/*********************************************		SECOND IMAGE GENERATION		**************************************/
	RepeatGenImag2:
	FingerPS_genImg(); 
	_delay_ms(100);
	if (FingerPS_CheckAck() == false) goto RepeatGenImag2;/*WAIT FOR ACK*/
	H_Lcd_Void_LCDGoTo(3,0); 
	H_Lcd_Void_LCDWriteString((u8*)"SECONED IMAGE GEN");
	/*********************************************		SECONED CHAR FILE GENERATED		**********************************/
	RepeatConvertFile2:
	FingerPS_convertImg2CharFile();
	_delay_ms(100);
	if (FingerPS_CheckAck() == false) goto RepeatConvertFile2;/*WAIT FOR ACK*/ 
	H_Lcd_Void_LCDClear();
	H_Lcd_Void_LCDGoTo(0,0);
	H_Lcd_Void_LCDWriteString((u8*)"CHAR2 FILE GEN"); 
	/********************************************		Generate Tempelate			**********************************/ 
	FingerPS_genTemplate(); 
	_delay_ms(500);
	if (FingerPS_CheckAck() == false) goto RepeatGenImag1;/*WAIT FOR ACK*/ 
	H_Lcd_Void_LCDGoTo(1,0);
	H_Lcd_Void_LCDWriteString((u8*)"TEMP GEN"); 
	/*******************************************		Tempelate Storing			***********************************/ 
 	RepeatStrTemp:
 	FingerPS_strTemplate();
 	_delay_ms(100);
 	if (FingerPS_CheckAck() == false) goto RepeatStrTemp;/*WAIT FOR ACK*/
 	H_Lcd_Void_LCDGoTo(2,0);
 	H_Lcd_Void_LCDWriteString((u8*)"TEMP STORED");  
 	_delay_ms(2000); 
	/*******************************************		Generate Image to check one to one match	********************/
	RepeatCheckImagGen:
	FingerPS_genImg();
	_delay_ms(100);
	if (FingerPS_CheckAck() == false) goto RepeatCheckImagGen; /*WAIT FOR ACK*/
	H_Lcd_Void_LCDGoTo(3,0);
	H_Lcd_Void_LCDWriteString((u8*)"Check IMAGE GEN"); 
 	/******************************************			Generate char from Check Image	****************************************/	
	RepeatCharCheckFileGen:
	FingerPS_convertImg1CharFile(); 
	_delay_ms(100);
	if (FingerPS_CheckAck() == false) goto RepeatCharCheckFileGen; /*WAIT FOR ACK*/
	H_Lcd_Void_LCDClear();
	H_Lcd_Void_LCDGoTo(0,0);
	H_Lcd_Void_LCDWriteString((u8*)"CHAR1 FILE GEN");
 	/******************************************			Load Char in char file 2	***********************************/
    RepeatLoadCharFile:
	FingerPS_LoadCharFile(); 
	_delay_ms(100); 
	if (FingerPS_CheckAck() == false) goto RepeatLoadCharFile; /*Wait for ACK*/
	H_Lcd_Void_LCDGoTo(1,0);
	H_Lcd_Void_LCDWriteString((u8*)"CHAR FILE LOADED"); 
	/******************************************			CHECK MATCH				****************************************/
	FingerPS_match();
	_delay_ms(100);
	if (AckPack[9] == 0x00){
	H_Lcd_Void_LCDGoTo(2,0);
	H_Lcd_Void_LCDWriteString((u8*)"MATCHED");
	}
	else {
	H_Lcd_Void_LCDGoTo(2,0);
	H_Lcd_Void_LCDWriteString((u8*)"NOT MATCHED");
	}
	while (1) 
    { 
		/*Do nothing*/
    }
} 

