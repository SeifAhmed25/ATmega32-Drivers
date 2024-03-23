/*
 * FingerPrint_Interface.h
 *
 *  Created on: Mar 22, 2024
 *      Author: tarek
 */

#ifndef FINGERPRINT_INTERFACE_H_
#define FINGERPRINT_INTERFACE_H_

#include "FingerPrint_Config.h"
#include "UART_Interface.h"

void FingerP_send(u8,u16);
void FingerPS_handShake(void);
void FingerPS_genImg(void);
void FingerPS_convertImg2CharFile(void);
void FingerPS_AuraLedConfig(void); 
void FingerPS_genTemplate(void);
void FingerPS_strTemplate(void);
void FingerPS_searchFinger(void);
void FingerPS_emptyLibrary(void);
void FingerPS_deleteFinger(void);
void FingerPS_LoadCharFile(void);
void FingerPS_calcCheckSum(void);
void FingerPS_match(void);
#endif /* FINGERPRINT_INTERFACE_H_ */
