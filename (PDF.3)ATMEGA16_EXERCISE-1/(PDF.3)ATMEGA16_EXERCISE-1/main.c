/*
 * (PDF.3)ATMEGA16_EXERCISE-1.c
 *
 * Created: 11-Aug-20 2:14:49 PM
 * Author : mohab
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 1000000
#endif

#include <util/delay.h>

ISR(INT0_vect)
{
	/*incase of switch pull down configuration*/
/*
// 	if (!(PIND&(1<<PD2)))
// 	{
// 		_delay_ms(300);		//switch bounce counter
// 		PORTC^=(1<<PC0);
// 	}
*/
	
	/*incase of switch pull up configuration*/
	if ((PIND&(1<<PD2)))
	{
		_delay_ms(300);		//switch bounce counter
		PORTC^=(1<<PC0);
	}
}

int main(void)
{
	DDRC|=(1<<PC0);			//set pin 0 in port C as output
	DDRD&=(~(1<<PD2));		//set pin 2 in port D as input
	
	//handling of the interrupt		/*incase of switch pull down configuration*/
	
/*
// 	GICR|=(1<<INT0);		//enable INT0 interrupt in global register
// 	MCUCR=0x00;				//set it to low level
// 	sei();					//enable I-bit in status register
*/
	
	
	//handling of the interrupt		/*incase of switch pull up configuration*/
	GICR|=(1<<INT0);				//enable INT0 interrupt in global register
	MCUCR|=(1<<ISC00);				//set it to high level
	sei();							//enable I-bit in status register
	
	while(1)
	{
	}
}

