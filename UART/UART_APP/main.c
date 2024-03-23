/*
 * UART_APP.c
 *
 * Created: 3/19/2024 12:48:34 PM
 * Author : seif
 */ 
#include "avr\interrupt.h"
#include "UART_Interface.h" 
#include "LCD_Interface.h"
#include "util/delay.h" 

int main(void)
{	
	u8 str [] = "UART TERMINAL TEST"; 
	H_Lcd_Void_LCDInit();
	UART_Init();  
	UART_sendString(str);
    while (1) 
    {
		/**/
    }
} 


