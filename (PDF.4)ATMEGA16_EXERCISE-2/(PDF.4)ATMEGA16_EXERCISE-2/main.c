/*
 * (PDF.4)ATMEGA16_EXERCISE-2.c
 *
 * Created: 21-Aug-20 4:28:16 AM
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

ISR(TIMER0_COMP_vect)
{
	count_tick++;
	if (count_tick==OVERFLOW_NUM_OF_COUNT)
	{
		PORTC^=(1<<PC0);
		count_tick=0;
	}
}

void initialize_timer(uint8_t comp_value)
{
	TCCR0=(1<<WGM01);				//Enable timer 0 as CTC mode
	
	TCCR0=(1<<CS00)|(1<<CS02);		//set the clock prescaler to 1024	
	
	TCNT0=0x00;						//Zeroing the timer register so it start counting from zero
	
	OCR0=comp_value;				//set the output compare register to compare value
	
	TIMSK|=(1<<OCIE0);				//Enable timer overflow interrupt	
}

int main(void)
{
	DDRC|=(1<<PC0);					//Enable pin 0 of PORTC as output
	PORTC|=(1<<PC0);				//output high
	
	sei();							//Enable the interrupts
	
	initialize_timer(250);			//initialize the timer by calling it's function
	
	while (1)
	{
	}
}
