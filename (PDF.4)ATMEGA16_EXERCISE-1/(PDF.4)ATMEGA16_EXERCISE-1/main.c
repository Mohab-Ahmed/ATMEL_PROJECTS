/*
 * (PDF.4)ATMEGA16_exercise-1.c
 *
 * Created: 20-Aug-20 6:05:12 PM
 * Author : mohab
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 1000000
#endif

#include <util/delay.h>

#define OVERFLOW_NUM_OF_COUNT 2		//for half a second since we using a prescaler of 1024 to reach an overflow rate of ~0.26s

uint8_t count_tick=0;

ISR(TIMER0_OVF_vect)
{
	count_tick++;
	if (count_tick==OVERFLOW_NUM_OF_COUNT)
	{
		PORTC^=(1<<PC0);
		count_tick=0;
	}
}

/*
int main(void)
{
	DDRC|=(1<<PC0);			//Enable pin 0 of PORTC as output
	PORTC|=(1<<PC0);		//output high
	
	TCCR0=0x00;				//Enable timer 0 as normal mode
	TCCR0|=(1<<CS00);		//set the clock prescaler to 1024
	TCCR0&=(~(1<<CS01));	//continue above
	TCCR0|=(1<<CS02);		//continue above
	
	TCNT0=0x00;				//Zeroing the timer register so it start counting from zero
	
	TIMSK|=(1<<TOIE0);		//Enable timer overflow interrupt
	
	sei();					//Enable the interrupts
	
    while (1) 
    {
    }
}
*/





/*another way to do it is to make the whole intialize timer thing in a function alone*/


void initialize_timer(void)
{
	TCCR0=0x00;				//Enable timer 0 as normal mode
	
	TCCR0=(1<<CS00)|(1<<CS02);		//set the clock prescaler to 1024	
	
	TCNT0=0x00;				//Zeroing the timer register so it start counting from zero
	
	TIMSK|=(1<<TOIE0);		//Enable timer overflow interrupt	
}

int main(void)
{
	DDRC|=(1<<PC0);			//Enable pin 0 of PORTC as output
	PORTC|=(1<<PC0);		//output high
	
	sei();					//Enable the interrupts
	
	initialize_timer();		//initialize the timer by calling it's function
	
	while (1)
	{
	}
}
