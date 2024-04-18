/*
 * SPI_Config.h
 *
 * Created: 3/28/2024 6:49:51 PM
 *  Author: seif
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_ 

#define ENABLED 0
#define DISABLED 1
#define SPI_DOUBLE_SPEED DISABLED
#define F_OSC_4	0
#define	F_OSC_16 1	
#define F_OSC_64 2 
#define F_OSC_128 3
#define SPI_CLK F_OSC_16 
#define SS PB4_PIN 
#define MOSI PB5_PIN 
#define MISO PB6_PIN 
#define SCK PB7_PIN 

#endif /* SPI_CONFIG_H_ */