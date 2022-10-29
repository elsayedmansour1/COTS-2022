#ifndef _TMR0_CONFIG_H
#define _TMR0_CONFIG_H

/***************************************************************************/
/*************************** Timer/Counter Control Register – TCCR0   ************************/
/*************************************************************************/
#define  FOC0       7					
#define  WGM00      6					
#define  COM01      5
#define  COM00      4					
#define  WGM01      3					
#define  CS02       2					
#define  CS01       1					
#define  CS00       0			

/***************************************************************************/
/*************************** Timer/Counter Interrupt Mask Register – TIMSK   ************************/
/*************************************************************************/

#define  OCIE2       7					
#define  TOIE2       6					
#define  TICIE1      5
#define  OCIE1A      4					
#define  OCIE1B      3					
#define  TOIE1       2					
#define  OCIE0       1					
#define  TOIE0       0

/***************************************************************************/
/*************************** Timer/Counter Interrupt Flag Register – TIFR   ************************/
/*************************************************************************/

#define TOV0	0
#define OCF0 	1

/***************************************************************************/
/*************************** TIMER 0 MODES  ************************/
/*************************************************************************/
 
#define  	Normal			0
#define  	PWM_Phase_Correct 		1
#define  	CTC			2
#define  	Fast_PWM			3

/***************************************************************************/
#define TIMER0_MODE		Fast_PWM
/*************************************************************************/

/***************************************************************************/
/*************************** TIMER 0 PRESCALER  ************************/
/*************************************************************************/

#define    TIMER0_NO_CLOCK_SOURCE    	 0		 
#define    TIMER0_NO_PRESCALER 	 1		 
#define    TIMER0_Prescaler_8		 2		 
#define    TIMER0_Prescaler_64	 3		 
#define    TIMER0_Prescaler_256	 4		 			 
#define    TIMER0_Prescaler_1024	 5		 
#define    TIMER0_FALLING_ADGE	 6
#define    TIMER0_RISING_ADGE		 7

/**************************************************************/
#define  	 TIMER0_Prescaler	TIMER0_Prescaler_8
/**************************************************************/

/***************************************************************************/
/*************************** TIMER0 OC0MODE  ************************/
/*************************************************************************/
 
#define  	OC0_disconnected		0
#define  	Toggle_OC0		1
#define  	Clear_OC0			2
#define  	Set_OC0			3
#define  	RESERVED			4

/***************************************************************************/
#define TIMER0_OC0_MODE		Clear_OC0
/*************************************************************************/

#endif
