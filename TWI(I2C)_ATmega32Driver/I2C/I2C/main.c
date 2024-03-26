/*
 * I2C.c
 *
 * Created: 3/25/2024 10:01:08 PM
 * Author : seif
 */ 
#include "I2C_Interface.h" 
int main(void)
{	/*TESTING DRIVER USING THE I2C DEBUGGER IN PROTUESS*/
	M_Void_I2C_Init(); 
	M_U8_I2C_Start();								
	M_U8_I2C_SendSlaveAddressWithWrite(0xA0); 
	M_U8_I2C_Write(0x00);					
	M_Void_I2C_STOP();						
    while (1) 
    { 
		/**/
    }
}

