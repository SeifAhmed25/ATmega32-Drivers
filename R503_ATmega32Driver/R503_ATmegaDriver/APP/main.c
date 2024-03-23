/*
 * R503_ATmegaDriver.c
 *
 * Created: 3/22/2024 8:16:22 PM
 * Author : seif
 */ 

#include "UART_Interface.h"
#include "FingerPrint_Interface.h"
#include "util\delay.h" 
void StoreAckBytes (u8);
int main(void)
{  
	UART_Init(); 
	UART_receiveByteAsynchCallBack(StoreAckBytes);   
	sei ();
	FingerPS_AuraLedConfig(); 
    /* Replace with your application code */
    while (1) 
    { 
		/**/
    }
} 
void StoreAckBytes (u8 RecivedByte){
	static u8 i = 0; 
	AckPack [i] = RecivedByte; 
	if (i==11){
		i = 0; 
	} 
	else i++; 
}

