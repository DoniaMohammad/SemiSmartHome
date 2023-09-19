#ifndef PORT_CFG_H
#define PORT_CFG_H

/*Configure pin direction: Options: 	1- INPUT
										2- OUTPUT
*/

#define PORTA_PIN0_DIR		INPUT		/*LDR*/
#define PORTA_PIN1_DIR		OUTPUT		/*CLCD*/
#define PORTA_PIN2_DIR		OUTPUT		/*CLCD*/
#define PORTA_PIN3_DIR		OUTPUT		/*CLCD*/
#define PORTA_PIN4_DIR		OUTPUT		/*CLCD*/
#define PORTA_PIN5_DIR		OUTPUT		/*CLCD*/
#define PORTA_PIN6_DIR		OUTPUT		/*CLCD*/
#define PORTA_PIN7_DIR		INPUT		/*LM35*/


#define PORTB_PIN0_DIR		INPUT
#define PORTB_PIN1_DIR		INPUT
#define PORTB_PIN2_DIR		INPUT
#define PORTB_PIN3_DIR		OUTPUT		/*DC motor*/
#define PORTB_PIN4_DIR		INPUT       /*KPD rows*/
#define PORTB_PIN5_DIR		INPUT       /*KPD rows*/
#define PORTB_PIN6_DIR		INPUT       /*KPD rows*/
#define PORTB_PIN7_DIR		INPUT       /*KPD rows*/


#define PORTC_PIN0_DIR		OUTPUT      /*LED array*/
#define PORTC_PIN1_DIR		OUTPUT      /*LED array*/
#define PORTC_PIN2_DIR		OUTPUT      /*LED array*/
#define PORTC_PIN3_DIR		OUTPUT      /*LED array*/
#define PORTC_PIN4_DIR		OUTPUT      /*LED array*/
#define PORTC_PIN5_DIR		OUTPUT      /*LED array*/
#define PORTC_PIN6_DIR		OUTPUT      /*LED array*/
#define PORTC_PIN7_DIR		OUTPUT      /*LED array*/


#define PORTD_PIN0_DIR		INPUT       /*Bluetooth module*/
#define PORTD_PIN1_DIR		OUTPUT      /*Bluetooth module*/
#define PORTD_PIN2_DIR		OUTPUT      /*KPD columns*/
#define PORTD_PIN3_DIR		OUTPUT      /*KPD columns*/
#define PORTD_PIN4_DIR		OUTPUT      /*KPD columns*/
#define PORTD_PIN5_DIR		OUTPUT      /*KPD columns + servo motor*/
#define PORTD_PIN6_DIR		OUTPUT
#define PORTD_PIN7_DIR		OUTPUT



/*Configure pin initial value: Options: for output:	1- HIGH
													2- LOW
										for input: 	3- PULLED_UP
													4- FLOATING		
*/
#define PORTA_PIN0_INITIAL_VALUE		FLOATING
#define PORTA_PIN1_INITIAL_VALUE		FLOATING
#define PORTA_PIN2_INITIAL_VALUE		FLOATING
#define PORTA_PIN3_INITIAL_VALUE		FLOATING
#define PORTA_PIN4_INITIAL_VALUE		FLOATING
#define PORTA_PIN5_INITIAL_VALUE		FLOATING
#define PORTA_PIN6_INITIAL_VALUE		FLOATING
#define PORTA_PIN7_INITIAL_VALUE		FLOATING


#define PORTB_PIN0_INITIAL_VALUE		FLOATING
#define PORTB_PIN1_INITIAL_VALUE		FLOATING
#define PORTB_PIN2_INITIAL_VALUE		FLOATING
#define PORTB_PIN3_INITIAL_VALUE		FLOATING
#define PORTB_PIN4_INITIAL_VALUE		PULLED_UP
#define PORTB_PIN5_INITIAL_VALUE		PULLED_UP
#define PORTB_PIN6_INITIAL_VALUE		PULLED_UP
#define PORTB_PIN7_INITIAL_VALUE		PULLED_UP


#define PORTC_PIN0_INITIAL_VALUE		LOW
#define PORTC_PIN1_INITIAL_VALUE		LOW
#define PORTC_PIN2_INITIAL_VALUE		LOW
#define PORTC_PIN3_INITIAL_VALUE		LOW
#define PORTC_PIN4_INITIAL_VALUE		LOW
#define PORTC_PIN5_INITIAL_VALUE		LOW
#define PORTC_PIN6_INITIAL_VALUE		LOW
#define PORTC_PIN7_INITIAL_VALUE		LOW


#define PORTD_PIN0_INITIAL_VALUE		FLOATING
#define PORTD_PIN1_INITIAL_VALUE		FLOATING
#define PORTD_PIN2_INITIAL_VALUE		LOW
#define PORTD_PIN3_INITIAL_VALUE		LOW
#define PORTD_PIN4_INITIAL_VALUE		LOW
#define PORTD_PIN5_INITIAL_VALUE		LOW
#define PORTD_PIN6_INITIAL_VALUE		LOW
#define PORTD_PIN7_INITIAL_VALUE		FLOATING

#endif