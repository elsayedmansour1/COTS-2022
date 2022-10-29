/*
 * LCD_Interface.h
 *
 *  Created on: Aug 21, 2020
 *      Author: ELSAYED
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define HCLCD_FUNCTION_SET 		0b00101000
#define	HCLCD_DISPLAY_ON_OFF  	0b00001100
#define DISPLAY_CLEAR			0b00000001
#define HCLCD_ENTRY_MODE_SET	0b00000110

/* LCD HW Pins */
#define RS PIN0
#define RW PIN1
#define EN PIN2
#define LCD_CTRL_PORT DIO_PORTC

/*LCD DATA PINS*/
#define LCD_DATA_PORT DIO_PORTA

/*LCD LINE NUMBER*/
#define LCD_u8_LINE0	0
#define LCD_u8_LINE1	1

 /* functions  */
void LCD_VidPulseEnable(void);

void LCD_VidInit(void);

void LCD_VidWriteCommend(u8 LOC_u8command);

void LCD_VoidClearDisplay(void);
void LCD_DisplayCharacter(u8 Copy_u8Data);
void LCD_DisplayString(u8* PCopy_u8String);
void LCD_VidWriteNumber(u32 LOC_u32num);
void LCD_SetPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber);
#endif /* LCD_INTERFACE_H_ */
