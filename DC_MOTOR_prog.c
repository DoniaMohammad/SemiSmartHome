#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DC_MOTOR_cfg.h"
#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_prv.h"

void DCMotor_voidRotateOneDirection (DIO_Port_t copy_DCmotor_PORT, DIO_Pin_t copy_DCmotor_PIN1)
{
	DIO_u8SetPinValue(DCMOTOR_PORT,DCMOTOR_PIN1,DIO_PIN_HIGH);
}

void DCMotor_voidRotateCW (DIO_Port_t copy_DCmotor_PORT, DIO_Pin_t copy_DCmotor_PIN1, DIO_Pin_t copy_DCmotor_PIN2)
{
	DIO_u8SetPinValue(copy_DCmotor_PORT,copy_DCmotor_PIN1,DIO_PIN_LOW);
	DIO_u8SetPinValue(copy_DCmotor_PORT,copy_DCmotor_PIN2,DIO_PIN_HIGH);
}


void DCMotor_voidRotateCCW (DIO_Port_t copy_DCmotor_PORT, DIO_Pin_t copy_DCmotor_PIN1, DIO_Pin_t copy_DCmotor_PIN2)
{
	DIO_u8SetPinValue(copy_DCmotor_PORT,copy_DCmotor_PIN2,DIO_PIN_LOW);
	DIO_u8SetPinValue(copy_DCmotor_PORT,copy_DCmotor_PIN1,DIO_PIN_HIGH);
}


void DCMotor_voidStop (DIO_Port_t copy_DCmotor_PORT, DIO_Pin_t copy_DCmotor_PIN1, DIO_Pin_t copy_DCmotor_PIN2)
{
	DIO_u8SetPinValue(copy_DCmotor_PORT,copy_DCmotor_PIN2,DIO_PIN_LOW);
	DIO_u8SetPinValue(copy_DCmotor_PORT,copy_DCmotor_PIN1,DIO_PIN_LOW);
}
