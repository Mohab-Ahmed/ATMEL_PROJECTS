/*
 * (PDF.4)ATMEGA16_CHALLANGE-1.c
 *
 * Created: 21-Aug-20 3:23:25 AM
 * Author : mohab
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <util/delay.h>

#define NUM_OF_COUNT 122	//number of count to reach 1 seconds

uint8_t count_overflow=0;

ISR(TIMER0_OVF_vect)
{
	count_overflow++;
	if (count_overflow==NUM_OF_COUNT)
	{
		count_overflow=0;
		if (PORTD==9)
		{
			PORTD=0;
		}
		else
		{
			PORTD++;
		}
	}		
}

void initialize_timer(void)
{
	TCCR0=0x00;				//timer as normal mode
	
	TCCR0|=(1<<CS02);		//set prescaler to 256
	
	TCNT0=0x00;				//zeroing the timer to start counting from zero
	
	TIMSK|=(1<<TOIE0);		//enable timer interrupt
}

int main(void)
{
	DDRD=(1<<PD0) | (1<<PD1) | (1<<PD2) | (1<<PD3);
	PORTD=0;
	
	sei();
	
	initialize_timer();
	
    while (1) 
    {
    }
}

