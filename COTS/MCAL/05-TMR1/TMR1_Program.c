#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GIE_config.h"
#include "TMR1_Config.h"
#include "TMR1_Register.h"

/****** Global Pointer To Function *********/
static void (*GPFunc_OF)(void)=NULL;
static void (*GPFunc_OCA)(void)=NULL;
static void (*GPFunc_IC)(void)=NULL;

void TMR1_OF_SetCallBack(void(*LocPFunc)(void))
{
	GPFunc_OF=LocPFunc;
}
void TMR1_OCA_SetCallBack(void(*LocPFunc)(void))
{
	GPFunc_OCA=LocPFunc;
}
void TMR1_IC_SetCallBack(void(*LocPFunc)(void))
{
	GPFunc_IC=LocPFunc;
}

ISR(__vector_9)
{
	if(GPFunc_OF!=NULL)
	{
		GPFunc_OF();
	}
	
}
ISR(__vector_7)
{
	if(GPFunc_OCA!=NULL)
	{
		GPFunc_OCA();
	}

}
ISR(__vector_6)
{
	if(GPFunc_IC!=NULL)
	{
		GPFunc_IC();
	}

}
void TMR1_INIT(void)
{
	/*********************TIMER 1 MODE*************************/
	#if	TIMER1_MODE==Normal	
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif     TIMER1_MODE==CTC
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif     TIMER1_MODE==Fast_PWM_ICR
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	#endif

	/*********************TIMER 1 PRESCALER*************************/
	#if	TIMER1_Prescaler==TIMER1_NO_CLOCK_SOURCE	
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
    #elif	TIMER1_Prescaler==TIMER1_NO_PRESCALER
		SET_BIT(TCCR1B,CS10);
		CLR_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
    #elif 	TIMER1_Prescaler==TIMER1_Prescaler_8
		CLR_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
    #elif 	TIMER1_Prescaler==TIMER1_Prescaler_64
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
	#elif 	TIMER1_Prescaler==TIMER1_Prescaler_256
		CLR_BIT(TCCR1B,CS10);
		CLR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
	#elif 	TIMER1_Prescaler==TIMER1_Prescaler_1024
		SET_BIT(TCCR1B,CS10);
		CLR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
	#elif 	TIMER1_Prescaler==TIMER1_FALLING_ADGE
		CLR_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
	#elif 	TIMER1_Prescaler==TIMER1_RISING_ADGE
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
          #endif
	/*********************TIMER1 OC1 MODE*************************/
	#if	TIMER1_OC1_MODE==OC1_A_B_disconnected
		CLR_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1A1);
		CLR_BIT(TCCR1A,COM1B1);
	#elif 	TIMER1_OC1_MODE==Toggle_OC1A_Discon_OC1B
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1A1);
		CLR_BIT(TCCR1A,COM1B1);
	#elif 	TIMER1_OC1_MODE==RESERVED
		CLR_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1A1);
		SET_BIT(TCCR1A,COM1B1);
	#elif 	TIMER1_OC1_MODE==Clear_OC1_A_B_NON_INVERTED
		CLR_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1A1);
		SET_BIT(TCCR1A,COM1B1);
	#elif 	TIMER1_OC1_MODE==Set_OC1_A_B_INVERTED
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1A1);
		SET_BIT(TCCR1A,COM1B1);
	#endif
}	
void TMR1_OverFlow_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void TMR1_OCAM_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void TMR1_OCBM_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void TMR1_IC_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void TMR1_Timer_Counter(u16 Value_of_TCNT1)
{
	TCNT1=Value_of_TCNT1;
}
void TMR1_Output_Compare_Register_1A(u16 Value_of_OCR1A)
{
	OCR1A=Value_of_OCR1A;
}

void TMR1_Output_Compare_Register_1B(u16 Value_of_OCR1B)
{
	OCR1B=Value_of_OCR1B;
}
void TMR1_voidSetTopOVF(u16 Copy_u16_ICR1A)
{
	ICR1A=Copy_u16_ICR1A;
}
void TMR1_IC_SelectEdgeTrig(u8 copy_u8Edge)
{
	switch(copy_u8Edge)
	{
		case rising_edge :SET_BIT(TCCR1B,ICES1);	break;
		case Falling_edge:CLR_BIT(TCCR1B,ICES1);	break;
		default://do nothing
			break;

	}
}
u16 TMR1_IC_GetICR_Value(void)
{
	return ICR1A;
}
