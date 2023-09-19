#include "STD_TYPES.h"

#include "PORT_interface.h"
#include "ADC_interface.h"
#include "USART_interface.h"
#include "TIMERS_interface.h"

#include "CLCD_interface.h"

#include "APP.h"

#include <util/delay.h>

void main (void)
{
	uint8 Local_u8VocalCommand=0u;

	PORT_voidInit();

	USART_voidInit();

	ADC_voidInit();

	CLCD_voidInit();

	TIMER1_voidInit();

	APP_voidLoginSystem();

	while (1)
	{
		/*waiting for vocal command*/
		Local_u8VocalCommand = USART_u8Receive();

		CLCD_voidClear();
		switch (Local_u8VocalCommand)
		{
		case '1':
			APP_voidTurnOnLights();
			break;

		case '2':
			APP_voidTurnOffLights();
			break;

		case '3':
			APP_voidControlLights();
			break;

		case '4':
			APP_voidOpenDoor();
			break;

		case '5':
			APP_voidCloseDoor();
			break;

		case '6':
			APP_voidOpenFan();
			break;

		case '7':
			APP_voidCloseFan();
			break;

		case '8':
			APP_voidControlFanByTemp();
			break;

		default:
			break;
		}
	}
}


