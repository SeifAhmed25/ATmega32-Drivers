


#include "FingerPrint_Interface.h"
u16 NextPage = 0x0000 ;
u8 AckPack [12] = {0}; 
/* A FUNCTION TO SEND THE WHOLE A FRAME AS FOLLOWS
 * 2 BYTE HEADER
 * 8 BYTE ADDRESS
 * 1 BYTE PACKAGE ID 
 * 2 PACKAGE LENGTH  */
void FingerP_send(u8 Package_ID,u16 length){
/*SEND 2BYTE HEADER*/
	UART_sendByte(HEADER_HIGH_BYTE);
	UART_sendByte(HEADER_LOW_BYTE);
/*SEND 8 BYTE ADDRESS*/
	UART_sendByte(ADDRESS_FOURTH_BYTE);
	UART_sendByte(ADDRESS_THIRD_BYTE);
	UART_sendByte(ADDRESS_SECOND_BYTE);
	UART_sendByte(ADDRESS_FIRST_BYTE); 
/*SEND 1 BYTE PACKAGE ID */
	UART_sendByte(Package_ID);
/*SEND 2 BYTE PACKAGE LENGTH*/
	UART_sendByte(length>>ONE_BYTE_SHIFT);
	UART_sendByte(length>>NO_BYTE_SHIFT); 
}
/* A FUNCTION TO SEND A HANDSHAKE */
void FingerPS_handShake(void){
	FingerP_send(PCK_ID_COMMAND_PACK,LENGTH_3BYTE);
	UART_sendByte(HAND_SHAKE);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_3BYTE+HAND_SHAKE)>>ONE_BYTE_SHIFT);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_3BYTE+HAND_SHAKE)>>NO_BYTE_SHIFT);
} 
void FingerPS_AuraLedConfig (void){
	FingerP_send(PCK_ID_COMMAND_PACK,LENGTH_7BYTE);
	UART_sendByte(AURA_LED_CONFIG);
	UART_sendByte(FLASHING_LIGHT);
	UART_sendByte(MEDIUM_SPEED);
	UART_sendByte(COLOR_INDEX_RED);
	UART_sendByte(LIGHT_COUNT);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_7BYTE+AURA_LED_CONFIG+FLASHING_LIGHT+MEDIUM_SPEED+COLOR_INDEX_RED+LIGHT_COUNT)>>ONE_BYTE_SHIFT);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_7BYTE+AURA_LED_CONFIG+FLASHING_LIGHT+MEDIUM_SPEED+COLOR_INDEX_RED+LIGHT_COUNT)>>NO_BYTE_SHIFT);
}
/* Detecting finger and store the detected finger image in ImageBuffer while
 * returning successful confirmation*/
void FingerPS_genImg(){
	FingerP_send(PCK_ID_COMMAND_PACK,LENGTH_3BYTE);
	UART_sendByte(COLLECT_FINGER_IMAGE);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_3BYTE+COLLECT_FINGER_IMAGE)>>ONE_BYTE_SHIFT);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_3BYTE+COLLECT_FINGER_IMAGE)>>NO_BYTE_SHIFT);
} 
/* Generate character file from the original finger image in ImageBuffer and
 * store the file in CharBuffer1 or CharBuffer2 
 * BufferID of CharBuffer1 and CharBuffer2 are 0x01 and 0x02 */
void FingerPS_convertImg2CharFile(){
	/*CharBuffer1*/
	FingerP_send(PCK_ID_COMMAND_PACK,LENGTH_4BYTE);
	UART_sendByte(CONVERT_IMG_TO_CHAR);
	UART_sendByte(CHAR_BUFFER_1);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_4BYTE+CHAR_BUFFER_1+CONVERT_IMG_TO_CHAR)>>ONE_BYTE_SHIFT);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_4BYTE+CHAR_BUFFER_1+CONVERT_IMG_TO_CHAR)>>NO_BYTE_SHIFT);
	/*CharBuffer2*/
	FingerP_send(PCK_ID_COMMAND_PACK,LENGTH_4BYTE);
	UART_sendByte(CONVERT_IMG_TO_CHAR);
	UART_sendByte(CHAR_BUFFER_2);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_4BYTE+CHAR_BUFFER_2+CONVERT_IMG_TO_CHAR)>>ONE_BYTE_SHIFT);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_4BYTE+CHAR_BUFFER_2+CONVERT_IMG_TO_CHAR)>>NO_BYTE_SHIFT);
} 
/* Combine information of character files from CharBuffer1 and CharBuffer2 and
 * generate a template which is stored back in both CharBuffer1 and CharBuffer2*/
void FingerPS_genTemplate(){
	FingerP_send(PCK_ID_COMMAND_PACK,LENGTH_3BYTE);
	UART_sendByte(GEN_TEMPLATE);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_3BYTE+GEN_TEMPLATE)>>ONE_BYTE_SHIFT);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_3BYTE+GEN_TEMPLATE)>>NO_BYTE_SHIFT);
} 
/* Store the template of specified buffer (Buffer1/Buffer2)
 * at the designated location of Flash library
 * PageID?Flash location of the Template				
 */
void FingerPS_strTemplate(){
	FingerP_send(PCK_ID_COMMAND_PACK,LENGTH_6BYTE);
	UART_sendByte(STR_TEMPLATE);
	UART_sendByte(CHAR_BUFFER_1);
	UART_sendByte((FIRST_PAGE_ID+NextPage)>>ONE_BYTE_SHIFT);
	UART_sendByte((FIRST_PAGE_ID+NextPage)>>NO_BYTE_SHIFT);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_6BYTE+STR_TEMPLATE+CHAR_BUFFER_1+(FIRST_PAGE_ID+NextPage))>>ONE_BYTE_SHIFT);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_6BYTE+STR_TEMPLATE+CHAR_BUFFER_1+(FIRST_PAGE_ID+NextPage))>>NO_BYTE_SHIFT);
	NextPage++;
} 

/* Search the whole finger library for the template that matches the one in CharBuffer1 or CharBuffer2, 
   We need to call two function [FingerPS_genImg() and FingerPS_convertImg2CharFile()]
   Input Parameter: BufferID, StartPage (searching start address), PageNum?searching numbers*/
void FingerPS_searchFinger(){
	FingerP_send(PCK_ID_COMMAND_PACK,LENGTH_8BYTE);
	UART_sendByte(SEARCH_FINGER);
	UART_sendByte(CHAR_BUFFER_1);
	UART_sendByte(FIRST_PAGE_ID>>ONE_BYTE_SHIFT);
	UART_sendByte(FIRST_PAGE_ID>>NO_BYTE_SHIFT);
	
	UART_sendByte(NUM_OF_PAGES_TO_SEARCH>>ONE_BYTE_SHIFT);
	UART_sendByte(NUM_OF_PAGES_TO_SEARCH>>NO_BYTE_SHIFT);
	
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_8BYTE+SEARCH_FINGER+CHAR_BUFFER_1+FIRST_PAGE_ID+NUM_OF_PAGES_TO_SEARCH)>>ONE_BYTE_SHIFT);
	UART_sendByte((PCK_ID_COMMAND_PACK+LENGTH_8BYTE+SEARCH_FINGER+CHAR_BUFFER_1+FIRST_PAGE_ID+NUM_OF_PAGES_TO_SEARCH)>>NO_BYTE_SHIFT);
} 


