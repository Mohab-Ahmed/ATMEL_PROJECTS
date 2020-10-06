/*
 * (PDF.4)ATMEGA16_CHALLANGE-2.c
 *
 * Created: 18-Sep-20 3:09:33 AM
 * Author : mohab
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <util/delay.h>

void intialize_timer()
{
	TCNT0=0;
	OCR0=125;	//for duty cycle 50%
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
	intialize_timer();	
    while (1) 
    {
    }
}

