/*
 * SPI_Private.h
 *
 * Created: 3/28/2024 6:50:11 PM
 *  Author: seif
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR_REG *(volatile u8*)(0x2D)
/*SPI Interrupt Enable Pin*/
#define SPIE_BIT 7 
/*SPI ENABLE PIN*/
#define SPE_BIT 6
/*Data Order 
  1 LSB First 
  0 MSB First*/
#define DORD_BIT 5 
/*Master/Slave Select 
  1 Master SPI Mode 
  0 Slave  SPI Mode */ 
#define MSTR_BIT 4 
/*Clock Polarity
  0 Leading on Rising, Trailing on Falling
  1	Leading on Falling, Trailing on Rising*/
#define CPOL_BIT 3 
/*Clock Phase
  Sample on Leading, Setup on Trailing
  Sample on Trailing, Setup on Leading*/
#define CPHA_BIT 2 
/*Clock Rate Select
  */
#define SPR1_BIT 1 
#define SPR0_BIT 0
/*SPI Status Register*/
#define SPSR_REG *(volatile u8*)(0x2E)
/*SPI Interrupt Flag*/
#define SPIF_BIT 7   
#define WCOL_BIT 6 
/*SPI Double Speed Bit*/
#define SPI2X_BIT 0

#define SPDR_REG *(volatile u8*)(0x2F) 

 


#endif /* SPI_PRIVATE_H_ */