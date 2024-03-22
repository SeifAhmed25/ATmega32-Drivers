/*
 * R503_ATmegaDriver.c
 *
 * Created: 3/22/2024 8:16:22 PM
 * Author : seif
 */ 

#include "UART_Interface.h"
#include "FingerPrint_Interface.h"
int main(void)
{ 
	UART_Init(); 
	FingerPS_handShake(); 
    /* Replace with your application code */
    while (1) 
    {
    }
}

