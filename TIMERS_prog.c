#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "TIMERS_prv.h"

#include "TIMERS_cfg.h"
#include "TIMERS_interface.h"
#include "TIMERS_reg.h"

static void (*TIMER0_pvNotificationFunc)(void) = NULL;
void TIMER0_voidPWMInit(void)
{
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*set PRESCALER value*/
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= DIVISION_BY_64;

	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
}

void TIMER0_PWM(uint8 copy_u8PWMValue)
{
	OCR0 = copy_u8PWMValue;
}

void TIMER0_voidInit(void)
{
	/*Set waveform generation mode: CTC*/
	SET_BIT(TCCR0, TCCR0_WGM01);
	CLR_BIT(TCCR0, TCCR0_WGM00);

	/*output compare mode: OC0 disconnected*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);

	/*output compare value: 250*/
	OCR0 = 250u;

	/*output compare interrupt enable*/
	SET_BIT(TIMSK,TIMSK_OCIEO);

	/*PRE-scaler: division by 64*/
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= DIVISION_BY_64;
}

void TIMER1_voidInit(void)
{
	/*OC1A pin fast PWM, set on top clear on compare: non inverted*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

	/*waveform generation mode: fast PWM mode 14*/
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1A,TCCR1A_WGM10);

	/*PRE-scaler: division by 64*/
	TCCR1B &= PRESCALER_MASK;
	TCCR1B |= DIVISION_BY_64;

	/*Set top value*/
	ICR1 = Timer1TopVal;
}

void TIMER1_voidSetCompVal(uint16 Copy_u16Val)
{
    OCR1A = Copy_u16Val;
}

void Timer1_voidSetTimerVal(uint16 copy_u16Val)
{
	TCNT1 = copy_u16Val;
}

uint16 Timer1_u6GetTimerVal(void)
{
	return TCNT1;
}

uint8 TIMER0_u8SetCallBack(void(*copy_pvNotificationFunc)(void))
{
	uint8 Local_u8ErrorState = OK ;

	if(copy_pvNotificationFunc != NULL)
	{
		/*Make the notification function global so that it can be accessed by the ISR*/
		TIMER0_pvNotificationFunc = copy_pvNotificationFunc;
	}

	else
	{
		Local_u8ErrorState = NULL_PTR;
	}

	return Local_u8ErrorState;
}

/*Timer0 compare match ISR*/
void __vector_10(void)		__attribute__((signal));
void __vector_10(void)
{
	if (TIMER0_pvNotificationFunc != NULL)
	{
		TIMER0_pvNotificationFunc();
	}

	else
	{
		/*Do nothing*/
	}
}
