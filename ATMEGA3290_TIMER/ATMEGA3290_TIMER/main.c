/*
 * ATMEGA3290_TIMER.c
 *
 * Created: 21-Aug-20 5:18:40 AM
 * Author : mohab
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 16000000
#endif

#define NUM_OF_COUNT 31
uint8_t count_flow=0;

void initialize_timer(void)
{
	TCCR0A=(1<<FOC0A)|(1<<CS00)|(1<<CS02);
	
	TCNT0=0x00;
	
	TIMSK0|=(1<<TOIE0);	
}

ISR(TIMER0_OVF_vect)
{
	count_flow++;
	if (count_flow==NUM_OF_COUNT)
	{
		PORTA^=0xff;
		count_flow=0;
	}
}

int main(void)
{
	DDRA|=0xff;
	PORTA=0xff;
	
	sei();
	
	initialize_timer();
	
    while (1) 
    {
    }
}

