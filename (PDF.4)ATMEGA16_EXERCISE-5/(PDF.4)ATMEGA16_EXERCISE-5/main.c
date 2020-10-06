/*
 * (PDF.4)ATMEGA16_EXERCISE-5.c
 *
 * Created: 17-Sep-20 5:57:19 PM
 * Author : mohab
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 1000000
#endif

#include <util/delay.h>

void intialize_timer(uint8_t duty_cycle)
{
	TCNT0=0;
	OCR0=duty_cycle;
	DDRB|=(1<<PB3);
	TCCR0=(1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01) ;
	/* Configure timer control register 
	 * 1. fast PWM Mode WGM01=1 & WGM00=1
	 * 2. clear OC0 on compare match, set OC0 at bottom COM00=0 & COM01=1 
	 * 3. clock = CPU clock/8 CS00=0 CS01=1 CS02=0
	 */ 
}

int main(void)
{
	intialize_timer(64);		//for duty cycle of 25%
	//intialize_timer(128);		//for duty cycle of 50%
	//intialize_timer(192);		//for duty cycle of 75%
	//intialize_timer(256);		//for duty cycle of 100%
	
	//configure input pins
	DDRA&=(~(1<<PA0));
	DDRA&=(~(1<<PA1));
	DDRA&=(~(1<<PA2));
	
	//configure output pins
	DDRC|=(1<<PC0);
	DDRC|=(1<<PC1);
	
	//stop motor at start
	PORTC|=(1<<PC0);
	PORTC|=(1<<PC1);

	while (1)
	{
		//check for button responsible for clock wise rotation
		if (PINA&(1<<PA0))
		{
			PORTC|=(1<<PC0);
			PORTC&=(~(1<<PC1));
		}
		//check for button responsible for anti clock wise rotation
		if (PINA&(1<<PA1))
		{
			PORTC&=(~(1<<PC0));
			PORTC|=(1<<PC1);
		}
		////check for button responsible for stoping the motor
		if (PINA&(1<<PA2))
		{
			PORTC|=(1<<PC0);
			PORTC|=(1<<PC1);
		}
		
	}
}

