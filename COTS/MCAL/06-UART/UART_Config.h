#ifndef _UART_CONFIGURATION_H_
#define _UART_CONFIGURATION_H_


/*USART Control and Status
Register A – UCSRA*/
#define RXC     7
#define TXC     6
#define UDRE    5
#define FE      4
#define DOR     3
#define PE      2
#define U2X     1
#define MPCM    0
/*USART Control and Status
Register B  UCSRB*/
#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define RXB8    1
#define TXB8    0
/*USART Control and Status
Register C  UCSRC*/
#define URSEL   7
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0
/**********************************************************************************************/
#define Recive_Complete     SET_BIT( UCSRA , RXC );
#define Trasmit_Complete    SET_BIT( UCSRA , TXC );
/*********************************************************************************************/
#define Receiver_Enable     SET_BIT( UCSRB , RXEN );
#define Transmitter_Enable  SET_BIT( UCSRB , TXEN );
/*********************************************************************************************/
#define Five_Bit            	CLR_BIT( UCSRB , UCSZ2 );\
								CLR_BIT( Temporary_REG , UCSZ1 );\
								CLR_BIT( Temporary_REG , UCSZ0 );
			
#define Six_Bit            	    CLR_BIT( UCSRB , UCSZ2 );\
								CLR_BIT( Temporary_REG , UCSZ1 );\
								SET_BIT( Temporary_REG , UCSZ0 );
			
#define Seven_Bit           	CLR_BIT( UCSRB , UCSZ2 );\
								SET_BIT( Temporary_REG , UCSZ1 );\
								CLR_BIT( Temporary_REG , UCSZ0 );
			
#define Eight_Bit           	CLR_BIT( UCSRB , UCSZ2 );\
								SET_BIT( Temporary_REG , UCSZ1 );\
								SET_BIT( Temporary_REG , UCSZ0 );
			
#define Nine_Bit              SET_BIT( UCSRB , UCSZ2 );\
							  SET_BIT( Temporary_REG , UCSZ1 );\
							  SET_BIT( Temporary_REG , UCSZ0 );
/******************************************************************************/

#endif
