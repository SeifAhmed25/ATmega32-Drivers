/*
 * SPI_Prog.c
 *
 * Created: 3/28/2024 6:49:11 PM
 *  Author: seif
 */ 
#include "SPI_Interface.h"
#include "SPI_Private.h"
void M_Void_SPI_MasterInit(void){
	u8 SPCR_RegValue = 0;
 	/* Enable SPI, Master*/
 	SPCR_RegValue |= (1<<SPE_BIT)|(1<<MSTR_BIT); 
 	/* CLK SELECT*/ 
 	#if SPI_CLK == F_OSC_4 
 		CLR_BIT (SPCR_RegValue, SPR1_BIT); 
 		CLR_BIT (SPCR_RegValue, SPR0_BIT);
 	#elif SPI_CLK == F_OSC_16 
 		CLR_BIT (SPCR_RegValue, SPR1_BIT); 
 		SET_BIT (SPCR_RegValue, SPR0_BIT);
 	#elif SPI_CLK == F_OSC_64
 		SET_BIT (SPCR_RegValue, SPR1_BIT);
 		CLR_BIT (SPCR_RegValue, SPR0_BIT);
 	#elif SPI_CLK == F_OSC_128
 		SET_BIT (SPCR_RegValue, SPR1_BIT);
 		SET_BIT (SPCR_RegValue, SPR0_BIT);
 	#endif   
	 /*Double Speed*/
 	#if SPI_DOUBLE_SPEED == ENABLED 
 		SET_BIT(SPSR_REG,SPI2X_BIT); 
 	#elif SPI_DOUBLE_SPEED == DISABLED
 		CLR_BIT(SPSR_REG,SPI2X_BIT); 
 	#endif 
	 SPCR_REG = SPCR_RegValue;
} 
u8 M_U8_SPI_TransmitRecieve(u8 Data){
	/*Put Data in the SPDR Register*/
	SPDR_REG = Data; 
	/*Wait for Transmit to complete*/
	while (!GET_BIT(SPSR_REG, SPIF_BIT)); 
	return SPDR_REG;	
}
void M_Void_SPI_SlaveInit(void){
	/* Enable SPI */
	SPCR_REG = (1<<SPE_BIT);
}