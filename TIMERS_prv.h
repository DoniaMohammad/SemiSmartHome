#ifndef TIMERS_PRV_H
#define TIMERS_PRV_H

#define NORMAL			       	0u
#define PHASE_CORRECT_PWM      	1u
#define CTC				       	2u
#define FAST_PWM		       	3u

#define DISCONNECTED	       	0u

#define PRESCALER_MASK			0b11111000

#define DIVISION_BY_1			1u
#define DIVISION_BY_8			2u
#define DIVISION_BY_64			3u
#define DIVISION_BY_256			4u
#define DIVISION_BY_1024		5u

#endif
