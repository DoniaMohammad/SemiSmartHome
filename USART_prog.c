#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_reg.h"
#include "USART_cfg.h"
#include "USART_prv.h"
#include "USART_interface.h"

void USART_voidInit (void)
{
	uint8 Local_u8UCSRCValue = 0 ;

	/*Set bit 7 for UCSRC select*/
	SET_BIT(Local_u8UCSRCValue,UCSRC_URSEL);

	/*Asynchronous, default*/
	CLR_BIT(UCSRC,UCSRC_UMSEL);

	/*No parity, default*/
	CLR_BIT(UCSRC,UCSRC_UPM0);
	CLR_BIT(UCSRC,UCSRC_UPM1);

	/*1 stop bit, default*/
	CLR_BIT(UCSRC,UCSRC_USBS);

	/*character size 8 bits, default*/
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);

	UCSRC = Local_u8UCSRCValue;

	/*baud rate 9600 bps at 16 MHZ system frequency*/
	UBRRL = 103u;

	/*Receiver enable*/
	SET_BIT(UCSRB,UCSRB_RXEN);

	/*Transmitter enable*/
	SET_BIT(UCSRB,UCSRB_TXEN);
}

void USART_voidSend (uint8 copy_u8Data)
{
	while (GET_BIT(UCSRA,UCSRA_UDRE)==0); /*wait until transmit buffer is empty and ready*/

	UDR = copy_u8Data;
}

uint8 USART_u8Receive (void)
{
	while (GET_BIT(UCSRA,UCSRA_RXC)==0); /*wait until data is received*/

	return UDR;
}
