


#include "FingerPrint_Interface.h"


// Function to send a command to the fingerprint sensor
void FingerP_send(u8 Package_ID,u16 length){

	UART_sendByte(HEADER_HIGH_BYTE);
	UART_sendByte(HEADER_LOW_BYTE);

	UART_sendByte(ADDRESS_FOURTH_BYTE);
	UART_sendByte(ADDRESS_THIRD_BYTE);
	UART_sendByte(ADDRESS_SECOND_BYTE);
	UART_sendByte(ADDRESS_FIRST_BYTE);

	UART_sendByte(Package_ID);
/*SHIFT RIGHT BYTE*/
	UART_sendByte(length>>ONE_BYTE_SHIFT);
	UART_sendByte(length>>NO_BYTE_SHIFT);
}

void FingerPS_handShake(void){

	FingerP_send(PCK_ID_COMMAND_PACK,LENGTH_3BYTE);
	UART_sendByte(HAND_SHAKE);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_3BYTE+HAND_SHAKE)>>ONE_BYTE_SHIFT);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_3BYTE+HAND_SHAKE)>>NO_BYTE_SHIFT);
}
