/*
 * SPI_Interface.h
 *
 * Created: 3/28/2024 6:49:36 PM
 *  Author: seif
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "SPI_Config.h"
void M_Void_SPI_MasterInit(void); 
u8 M_U8_SPI_TransmitRecieve(u8); 
void M_Void_SPI_SlaveInit(void); 

#endif /* SPI_INTERFACE_H_ */