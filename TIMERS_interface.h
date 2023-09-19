#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

void TIMER0_voidInit(void);
uint8 TIMER0_u8SetCallBack(void(*copy_pvNotificationFunc)(void));

void TIMER1_voidInit(void);
uint8 TIMER1_u8SetCallBack(void(*copy_pvNotificationFunc)(void));
void TIMER1_voidSetCompVal(uint16 Copy_u16Val);
void Timer1_voidSetTimerVal(uint16 copy_u16Val);
uint16 Timer1_u6GetTimerVal(void);

#endif
