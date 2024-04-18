/*
 * UART_Config.h
 *
 *  Created on: Mar 19, 2024
 *      Author: tarek
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
#define F_CPU 16000000UL
/*******DEFINING BAUD RATE	 ********/ 
#define BAUDRATE 9600
/*******CLK SOURCE MHZ_8 OR MHZ_16***/ 
#define CLK_SOURCE MHZ_8
/*******STOPBIT_MODE 1 OR 2  ********/
#define STOPBIT_MODE 1 
/*******PARITY_MODE DISABLE OR ENABLE_E OR ENABLE_O**/ 
#define PARITY_MODE DISABLED
/******* RECIEVING USING INTERRUPT MODE**/ 
/******* ENABLE - DISABLE ***************/
#define UART_INT_MODE ENABLE 

#endif /* UART_CONFIG_H_ */
