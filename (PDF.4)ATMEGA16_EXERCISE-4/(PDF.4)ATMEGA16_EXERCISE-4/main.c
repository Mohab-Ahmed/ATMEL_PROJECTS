/*
 * (PDF.4)ATMEGA16_EXERCISE-4.c
 *
 * Created: 17-Sep-20 5:05:23 PM
 * Author : mohab
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef F_CPU
#define F_CPU 1000000
#endif

void intialize_timer(uint8_t duty_cycle)
{
	TCNT0=0;
	OCR0=duty_cycle;
	TCCR0=(1<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<CS01) ;
	/* Configure timer control register 
	 * 1. fast PWM Mode WGM01=1 & WGM00=1
	 * 2. clear OC0 on compare match, set OC0 at bottom COM00=0 & COM01=1 
	 * 3. clock = CPU clock/8 CS00=0 CS01=1 CS02=0
	 */ 
}

int main(void)
{
    DDRB|=(1<<PB3);
	intialize_timer(125);	//for duty cycle 50%
	_delay_ms(5000);
	intialize_timer(63);	//for duty cycle 25%
    while (1) 
    {
    }
}

