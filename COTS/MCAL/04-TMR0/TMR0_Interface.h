#ifndef _TMR0_INTERFACE_H
#define _TMR0_INTERFACE_H

void TMR0_OF_SetCallBack(void(*LocPFunc)(void));
void TMR0_OCM_SetCallBack(void(*LocPFunc)(void));

void TMR0_INIT(void);
void TMR0_OverFlow_Interrupt_Enable(void);
void TMR0_OCM_Interrupt_Enable(void);
void TMR0_Timer_Counter(u8 Value_of_TCNT0);
void TMR0_Output_Compare(u8 Value_of_OCR0);
void TMR0_Set_Duty_Cycle(u8 Duty_Cycle );












#endif
