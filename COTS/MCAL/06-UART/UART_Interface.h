#ifndef _UART_INTERFACE_H_
#define _UART_INTERFACE_H_


void UART_INIT(void);
void UART_VoidSendChar(u8 u8Data);
u8 UART_VoidGetChar(void);


u8* UART_VoidGetString(void);


















#endif
