/*
 * TWI_Register.h
 *
 *  Created on: Oct 29, 2022
 *      Author: elsay
 */

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define TWCR  	*((volatile u8*)0x56)
#define TWBR	*((volatile u8*)0x20)
#define TWSR	*((volatile u8*)0x21)
#define TWAR	*((volatile u8*)0x22)
#define TWDR	*((volatile u8*)0x23)

#endif /* TWI_REGISTER_H_ */
