#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "USART_interface.h"
#include "TIMERS_interface.h"

#include "KPD_interface.h"
#include "CLCD_interface.h"
#include "LDR_interface.h"
#include "DC_MOTOR_interface.h"
#include "LM35_interface.h"

#include <util/delay.h>

void APP_voidLoginSystem(void)
{
	uint8 Local_u8ID[4], Local_u8IDCheck[4]={1,2,3,4}, Local_u8Iterrator, Local_u8PressedKey=0xff, Local_u8IDFlag=0
			, Local_u8Pass[4], Local_u8PassCheck[4]={4,3,2,1}, Local_u8PassFlag=0, Local_u8Trials=1, Local_u8XPos=0;

	/*System starts*/
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("WELCOME TO MY");
	CLCD_voidGoToXY(0,1);
	CLCD_voidSendString("SEMI SMART HOME");
	_delay_ms(2000);

	/*Clear LCD*/
	CLCD_voidClear();

	/*Enter your ID*/
	CLCD_voidSendString("ENTER YOUR ID");
	CLCD_voidGoToXY(0,1);

	for(Local_u8Iterrator=0 ; Local_u8Iterrator<4 ; Local_u8Iterrator++)
	{
		do
		{
			Local_u8PressedKey = KPD_u8GetPressedKey();
		}while (Local_u8PressedKey == 0xff);

		if ((Local_u8PressedKey>=0)&&(Local_u8PressedKey<=9))
		{
			/*Display ID*/
			CLCD_voidSendNumber(Local_u8PressedKey);

			/*Collect ID*/
			Local_u8ID[Local_u8Iterrator] = Local_u8PressedKey;
			_delay_ms(300);
		}

		else
		{
			CLCD_voidClear();
			CLCD_voidSendString("INVALID INPUT");
			CLCD_voidGoToXY(0,1);
			CLCD_voidSendString("PLEASE TRY AGAIN");
			_delay_ms(2000);
			APP_voidLoginSystem();
		}
	}

	/*Check the ID*/
	for(Local_u8Iterrator=0 ; Local_u8Iterrator<4 ; Local_u8Iterrator++)
	{
		if (Local_u8ID[Local_u8Iterrator] == Local_u8IDCheck[Local_u8Iterrator])
		{
			Local_u8IDFlag = 1;
		}

		else
		{
			Local_u8IDFlag = 0;
			break;
		}
	}

	if (Local_u8IDFlag == 0)
	{
		CLCD_voidClear();
		CLCD_voidSendString("INCORRECT ID");
		APP_voidLoginSystem();
	}

	while (Local_u8Trials<=3)
	{
		CLCD_voidSendCommand(1);

		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("ENTER PASSWORD");

		/*display tries number*/
		CLCD_voidGoToXY(6,1);
		CLCD_voidSendNumber(4-Local_u8Trials);
		CLCD_voidGoToXY(8,1);
		CLCD_voidSendString("TRIES");
		CLCD_voidGoToXY(Local_u8XPos,1);

		Local_u8PressedKey = 0xff;

		/*Entering 4 digits password*/
		for(Local_u8Iterrator=0 ; Local_u8Iterrator<4 ; Local_u8Iterrator++)
		{
			do
			{
				Local_u8PressedKey = KPD_u8GetPressedKey();
			}while (Local_u8PressedKey == 0xff);

			if ((Local_u8PressedKey>=0)&&(Local_u8PressedKey<=9))
			{
				/*Displaying password with stars*/
				CLCD_voidGoToXY(Local_u8XPos,1);
				CLCD_voidSendNumber(Local_u8PressedKey);
				_delay_ms(650);
				CLCD_voidGoToXY(Local_u8XPos,1);
				CLCD_voidSendData('*');

				/*Collecting the password*/
				Local_u8Pass[Local_u8Iterrator] = Local_u8PressedKey;

				Local_u8XPos++;
			}

			else
			{
				CLCD_voidClear();
				CLCD_voidSendString("INVALID INPUT");
				CLCD_voidGoToXY(0,1);
				CLCD_voidSendString("PLEASE TRY AGAIN");
				_delay_ms(2000);
				APP_voidLoginSystem();
			}
		}

		/*password check*/

		for(Local_u8Iterrator=0 ; Local_u8Iterrator<4 ; Local_u8Iterrator++)
		{
			if (Local_u8Pass[Local_u8Iterrator] == Local_u8PassCheck[Local_u8Iterrator])
			{
				Local_u8PassFlag = 1;
			}

			else
			{
				Local_u8PassFlag = 0;
				break;
			}
		}

		/*if password is correct*/
		if (Local_u8PassFlag == 1)
		{
			/*Start the main code*/
			/*Clear LCD*/
			CLCD_voidSendCommand(1);

			/*Welcome Donia*/
			CLCD_voidSendString("WELCOME DONIA");
			_delay_ms(2000);

			/*To start send vocal command*/
			CLCD_voidSendCommand(1);
			CLCD_voidSendString("SEND VOCAL");
			CLCD_voidGoToXY(0,1);
			CLCD_voidSendString("COMMAND");
			break;
		}

		else if (Local_u8PassFlag == 0)
		{
			if (Local_u8Trials<3)
			{
				Local_u8Trials++;
				CLCD_voidSendCommand(1);
				CLCD_voidGoToXY(0,0);
				CLCD_voidSendString("WRONG PASSWORD");
				CLCD_voidGoToXY(0,1);
				CLCD_voidSendString("TRY AGAIN");
				Local_u8XPos=0;
				_delay_ms(2000);
			}

			else if (Local_u8Trials==3)
			{
				break;
			}
		}
	}

	if ((Local_u8Trials==3)&&(Local_u8PassFlag == 0))
	{
		/*Clear LCD*/

		CLCD_voidClear();

		/*display no more tries */
		CLCD_voidSendString("NO MORE TRIES");
		_delay_ms(2000);

		/*display system shutting down*/
		CLCD_voidSendCommand(1);
		CLCD_voidSendString("SHUTTING DOWN");
		CLCD_voidGoToXY(0,1);
		for(Local_u8Iterrator=3;Local_u8Iterrator>=1;Local_u8Iterrator--)
		{
			CLCD_voidSendNumber(Local_u8Iterrator);
			_delay_ms(250);
			CLCD_voidSendData('.');
			_delay_ms(250);
			CLCD_voidSendData('.');
			_delay_ms(250);
		}
		/*Clear LCD*/
		CLCD_voidClear();

		/*play buzzer sound*/
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);

		CLCD_voidSendString("RESTART SYSTEM");
	}
}


void APP_voidTurnOnLights(void)
{
	DIO_u8SetPortValue(DIO_PORTC,DIO_PORT_HIGH);
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("LIGHT IS ON");
}


void APP_voidTurnOffLights(void)
{

	DIO_u8SetPortValue(DIO_PORTC,DIO_PORT_LOW);
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("LIGHT IS OFF");
}

void APP_voidControlLights(void)
{
	uint8 Local_u8LightLevel, Local_u8LedsNum;

	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("CONTROLLING");
	CLCD_voidGoToXY(0,1);
	CLCD_voidSendString("LIGHTS");

	Local_u8LightLevel = LDR_u8GetLightLevel(ADC_u8GetChannelReading(ADC7_SINGLE_ENDED));
	Local_u8LedsNum = Local_u8LightLevel/10;

	DIO_u8SetPortValue(DIO_PORTC,(0XFF>>(Local_u8LedsNum)));
}

void APP_voidOpenDoor(void)
{
	CLCD_voidSendString("DOOR IS OPENED");
	TIMER1_voidSetCompVal(450);
}

void APP_voidCloseDoor(void)
{
	CLCD_voidSendString("DOOR IS CLOSED");
	TIMER1_voidSetCompVal(100);
}

void APP_voidOpenFan(void)
{
	CLCD_voidSendString("FAN IS ON");
	DCMotor_voidRotateOneDirection (DCMOTOR_PORT, DCMOTOR_PIN1);
}

void APP_voidCloseFan(void)
{
	CLCD_voidSendString("FAN IS OFF");
	DCMotor_voidStop(DCMOTOR_PORT,DCMOTOR_PIN1,DCMOTOR_PIN2);
}

void APP_voidControlFanByTemp(void)
{
	uint8 Local_u8ChannelReading , Local_u8AnalogReading;

	Local_u8ChannelReading=ADC_u8GetChannelReading(ADC0_SINGLE_ENDED);

	Local_u8AnalogReading = LM35_u8GetTemp(Local_u8ChannelReading);

	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("Temp = ");
	CLCD_voidGoToXY(8,0);
	CLCD_voidSendNumber(Local_u8AnalogReading);
}


void APP_voidControlFanByHand(void)
{
	TIMER0_voidPWMInit();
	TIMER0_PWM(ADC_u8GetChannelReading(ADC0_SINGLE_ENDED));
	CLCD_voidSendString("CONTROLLING FAN");
}
