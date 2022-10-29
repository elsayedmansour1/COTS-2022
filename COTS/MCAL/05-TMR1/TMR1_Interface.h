#ifndef _TIMRER1_INTERFACE_H
#define _TIMRER1_INTERFACE_H

void TMR1_OF_SetCallBack(void(*LocPFunc)(void));
void TMR1_OCA_SetCallBack(void(*LocPFunc)(void));
void TMR1_IC_SetCallBack(void(*LocPFunc)(void));

void TMR1_INIT(void);

void TMR1_Timer_Counter(u16 Value_of_TCNT1);
void TMR1_Output_Compare_Register_1A(u16 Value_of_OCR1A);
void TMR1_Output_Compare_Register_1B(u16 Value_of_OCR1B);
void TMR1_voidSetTopOVF(u16 Copy_u16_ICR1A);
void TMR1_OverFlow_Interrupt_Enable(void);
void TMR1_OCAM_Interrupt_Enable(void);
void TMR1_OCBM_Interrupt_Enable(void);
void TMR1_IC_Interrupt_Enable(void);
void TMR1_IC_SelectEdgeTrig(u8 copy_u8Edge);
u16 TMR1_IC_GetICR_Value(void);











#endif
