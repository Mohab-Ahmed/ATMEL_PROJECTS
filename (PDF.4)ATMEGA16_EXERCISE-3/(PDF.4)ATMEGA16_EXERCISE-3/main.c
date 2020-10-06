/*
 * (PDF.4)ATMEGA16_EXERCISE-3.c
 *
 * Created: 21-Aug-20 5:21:44 PM
 * Author : mohab
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 1000000  
#endif

void initialize_timer(void)
{
	TCCR0=(1<<FOC0) | (1<<WGM01) | (1<<COM00) | (1<<CS00);	//non-pwm mode,CTC mode,toggle OC0,no prescale 
	/* Configure timer control register 
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. Toggle OC0 on compare match COM00=1 & COM01=0 
	 * 4. clock = CPU clock CS00=1 CS01=0 CS02=0
	 */ 
	TCNT0=0;											//zerowing intial value
	OCR0=250;											//F(required)=F(f_cpu)/N(prescaler)*256(no. of timer count)
}

int main(void)
{
	DDRB|=(1<<PB3);				//make pin 3 in port B as output which is the compare match pin for timer 0
	initialize_timer();
    while (1) 
    {
    }
}

