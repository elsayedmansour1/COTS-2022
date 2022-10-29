#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "avr/delay.h"

#include "LCD_Interface.h"
#include "LCD_Register.h"




void LCD_VidInit(void)
{
	_delay_ms(50);

	  /*set direction*/
	DIO_VidSetPinDirection(LCD_CTRL_PORT,RS,OUTPUT);
	DIO_VidSetPinDirection(LCD_CTRL_PORT,RW,OUTPUT);
	DIO_VidSetPinDirection(LCD_CTRL_PORT,EN,OUTPUT);
	DIO_VidSetPortDirection(LCD_DATA_PORT,0XFF);



		LCD_VidWriteCommend(0B00111000);//function set
		_delay_ms(1);
		LCD_VidWriteCommend(0B00001100);//screen on
	    _delay_ms(1);
	    LCD_VidWriteCommend(0B00000001);//clear display
	    _delay_ms(2);
		LCD_VidWriteCommend(0B00000010);//Return Home


}
void LCD_VidWriteCommend(u8 LCD_u8Commend)
{

	DIO_VidSetPinValue(LCD_CTRL_PORT,RS,0);  //RS=0
	DIO_VidSetPinValue(LCD_CTRL_PORT,RW,0);  //RW=0
	DIO_VidSetPortValue(LCD_DATA_PORT,LCD_u8Commend); //write commend

		DIO_VidSetPinValue(LCD_CTRL_PORT,EN,1);  //EN=1
		_delay_ms(2);
		DIO_VidSetPinValue(LCD_CTRL_PORT,EN,0);  //EN=0
		_delay_ms(1);     //wait lcd to write letter

}
void LCD_VidWriteData(u8 LCD_u8Data)
{

	DIO_VidSetPinValue(LCD_CTRL_PORT,RS,1);  //RS=1
	DIO_VidSetPinValue(LCD_CTRL_PORT,RW,0);  //RW=0
	DIO_VidSetPortValue(LCD_DATA_PORT,LCD_u8Data); //write commend

		DIO_VidSetPinValue(LCD_CTRL_PORT,EN,1);  //EN=1
		_delay_ms(2);
		DIO_VidSetPinValue(LCD_CTRL_PORT,EN,0);  //EN=0
		_delay_ms(1);     //wait lcd to write letter
}
void LCD_VoidClearDisplay(void)
{

	LCD_VidWriteCommend(0x01);
	_delay_ms(20);
}
void LCD_DisplayCharacter(u8 Copy_u8Data)
{
	LCD_VidWriteData(Copy_u8Data);
}
void LCD_DisplayString(u8* PCopy_u8String)
{

	u8 Loc_u8Count=0;
	while(PCopy_u8String[Loc_u8Count]!=NULL)
	{
		LCD_DisplayCharacter(PCopy_u8String[Loc_u8Count]);
		Loc_u8Count++;
	}


}
void LCD_VidWriteNumber(u32 LOC_u32num)
{ 	u32 revrese=0;
u8 y;
u8 counter=0;
if(LOC_u32num==0)
{
	LCD_DisplayCharacter(48);
}
while(LOC_u32num>0)
{
	revrese=(revrese*10)+(LOC_u32num)%10;
	if(revrese==0)
	{
		 y=0;
		 counter++;
	}
	LOC_u32num=LOC_u32num/10;
}
while(revrese>0)
{
	u8 res=revrese%10;
	LCD_DisplayCharacter(res+48);
	revrese=revrese/10;
}
if(y==0)
{
	for(u8 i=0;i<counter;i++)
	{
		LCD_DisplayCharacter(48);
	}
}
}
void LCD_SetPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber)
{
	if((Copy_u8LineNumber<=1)&&(Copy_u8PositionNumber<= 15))
	{

		switch(Copy_u8LineNumber)
				{

				case LCD_u8_LINE0 : LCD_VidWriteCommend(0x80 + Copy_u8PositionNumber);break;

				case LCD_u8_LINE1 : LCD_VidWriteCommend(0xC0 + Copy_u8PositionNumber);break;
				}

	}


}
