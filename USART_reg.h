#ifndef USART_REG_H
#define USART_REG_H

#define UDR				*((volatile uint8*)0x2C)	/*USART I/O data register*/
	
#define UCSRA			*((volatile uint8*)0x2B)	/*USART control and status register A*/
#define UCSRA_RXC		7u							/*receive complete flag*/
#define UCSRA_TXC		6u							/*transmit complete flag*/
#define UCSRA_UDRE		5u							/*data register empty flag*/
#define UCSRA_FE		4u							/*frame error bit*/
#define UCSRA_DOR		3u							/*data overrun bit*/
#define UCSRA_PE		2u							/*parity error bit*/
#define UCSRA_U2X		1u							/*double speed bit*/
#define UCSRA_MPCM		0u							/*multiprocessor communication mode*/
	
#define UCSRB			*((volatile uint8*)0x2A)	/*USART control and status register B*/
#define UCSRB_RXCIE		7u							/*RX complete interrupt enable*/
#define UCSRB_TXCIE		6u							/*TX complete interrupt enable*/
#define UCSRB_UDRIE		5u							/*data register empty interrupt enable*/
#define UCSRB_RXEN		4u							/*receiver enable*/
#define UCSRB_TXEN		3u							/*transmitter enable*/
#define UCSRB_UCSZ2		2u							/*character size bit 2*/
#define UCSRB_RXB8		1u							/*Receive data bit 8*/
#define UCSRB_TXB8		0u							/*Transmit data bit 8*/

#define UCSRC			*((volatile uint8*)0x40)	/*USART control and status register C*/
#define UCSRC_URSEL		7u							/*register select*/
#define UCSRC_UMSEL		6u							/*USART mode select*/
#define UCSRC_UPM1		5u							/*parity mode bit 1*/
#define UCSRC_UPM0		4u							/*parity mode bit 0*/
#define UCSRC_USBS		3u							/*stop bit select*/
#define UCSRC_UCSZ1		2u							/*character size bit 1*/
#define UCSRC_UCSZ0		1u							/*character size bit 0*/
#define UCSRC_UCPOL		0u							/*clock polarity bit*/

#define UBRRL			*((volatile uint8*)0x29)	/*USART baud rate low register*/
#define UBRRH			*((volatile uint8*)0x40)	/*USART baud rate high register*/

#endif
