#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "ADC_interface.h"
#include "ADC_reg.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"

void ADC_voidInit(void)
{
	/*1- Reference selection AVCC pin*/
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);

	/*2- activate left adjust result for 8 bit resolution*/
	SET_BIT(ADMUX, ADMUX_ADLAR);

	/*3- check on prescaler configuration setting*/
	ADCSRA &= PRESCALER_MASK;			/*clear the prescaler bits*/
	ADCSRA |= ADC_u8PRESCALER;

	/*4- Enable ADC*/
	SET_BIT(ADCSRA, ADCSRA_ADEN);
}


uint8 ADC_u8GetChannelReading (ADC_Channel_t copy_u8Channel)
{
	/*1- set the required channel*/
	ADMUX &= CHANNEL_SELECTION_MASK;			/*clear the channel selection bits*/
	ADMUX |= copy_u8Channel;

	/*2- start conversion*/
	SET_BIT(ADCSRA, ADCSRA_ADSC);

	/*3- polling until the conversion is done*/
	while ((GET_BIT(ADCSRA, ADCSRA_ADIF)==0))
	{

	}

	/*4- clear the conversion complete flag*/
	SET_BIT(ADCSRA, ADCSRA_ADIF);

	/*5- read the data*/
	return ADCH;
}
