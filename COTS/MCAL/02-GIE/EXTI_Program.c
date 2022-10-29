#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_config.h"
#include "DIO_Interface.h"
#include "EXTI_Config.h"
#include "EXTI_Register.h"
void (*PTFunc)(void)='\0';
void EXTI2_SetCallBack(void (*LOC_Ptr)(void))
{
	PTFunc=LOC_Ptr;
}


void EX_INT0_INIT(void)
{
	/*ENABLE EXTERNAL ENTERRUPT 0*/
	SET_BIT(GICR ,INT0);
	/*CHOOSE MODE*/
	#if   MODE_INT0==Falling_Adge
	CLR_BIT(MCUCR ,ISC00);
	SET_BIT(MCUCR ,ISC01);
	#elif MODE_INT0==Rising_Adge
	SET_BIT(MCUCR ,ISC00);
	SET_BIT(MCUCR ,ISC01);
	#elif MODE_INT0==Low_Level
	CLR_BIT(MCUCR ,ISC00);
	CLR_BIT(MCUCR ,ISC01);
	#elif MODE_INT0==Any_Change
	SET_BIT(MCUCR ,ISC00);
	CLR_BIT(MCUCR ,ISC01);
	#endif
}
void EX_INT1_INIT(void)
{
	/*ENABLE EXTERNAL ENTERRUPT 1*/
	SET_BIT(GICR ,INT1);
	/*CHOOSE MODE*/
	#if   MODE_INT1==Falling_Adge
	CLR_BIT(MCUCR ,ISC10);
	SET_BIT(MCUCR ,ISC11);
	#elif MODE_INT1==Rising_Adge
	SET_BIT(MCUCR ,ISC10);
	SET_BIT(MCUCR ,ISC11);
	#elif MODE_INT1==Low_Level
	CLR_BIT(MCUCR ,ISC10);
	CLR_BIT(MCUCR ,ISC11);
	#elif MODE_INT1==Any_Change
	SET_BIT(MCUCR ,ISC10);
	CLR_BIT(MCUCR ,ISC11);

	#endif	
}
void EX_INT2_INIT(void)
{
	/*ENABLE EXTERNAL ENTERRUPT 2*/
	SET_BIT(GICR ,INT2);
	/*CHOOSE MODE*/
	#if   MODE_INT2==Falling_Adge
	CLR_BIT(MCUCSR ,ISC2);
	#elif MODE_INT2==Rising_Adge
	SET_BIT(MCUCSR ,ISC2);

	#endif
}
void __vector_1()__attribute__((signal));
void __vector_1()
{
MDIO_voidSetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_OUTPUT);
MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
}
void __vector_2()__attribute__((signal));
void __vector_2()
{

}
void __vector_3()__attribute__((signal));
void __vector_3()
{
if(PTFunc!='\0')
{
	PTFunc();
}
}
