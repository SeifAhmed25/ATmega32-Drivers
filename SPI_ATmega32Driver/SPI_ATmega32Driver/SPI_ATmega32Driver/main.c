/*
 * SPI_ATmega32Driver.c
 *
 * Created: 3/28/2024 6:48:01 PM
 * Author : seif
 */ 
#include "DIO_Interface.h"
#include "SPI_Interface.h" 
#define F_CPU 16000000UL 
#include "util\delay.h"

int main(void)
{	
	M_DIO_Void_SetPinDirection(SS,INPUT);
	M_DIO_Void_SetPinValue(SS,HIGH);
	M_DIO_Void_SetPinDirection(MISO,INPUT);
	M_DIO_Void_SetPinDirection(MOSI,OUTPUT);
	M_DIO_Void_SetPinDirection(SCK,OUTPUT);	
	/*Initiate SPI in Master Mode*/  
	M_Void_SPI_MasterInit();
    while (1) 
    {
			M_U8_SPI_TransmitRecieve('A');
			_delay_ms(500);
    }
}

