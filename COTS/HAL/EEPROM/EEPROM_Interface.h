/*
 * EEPROM_Interface.h
 *
 *  Created on: Nov 3, 2022
 *      Author: elsay
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidInit(void);
void EEPRoM_voidWriteData(u8 Copy_u8Data,u16 Copy_u16Address);
void EEPRoM_voidReadData(u8 *Copy_u8Data,u16 Copy_u16Address);

#endif /* EEPROM_INTERFACE_H_ */
