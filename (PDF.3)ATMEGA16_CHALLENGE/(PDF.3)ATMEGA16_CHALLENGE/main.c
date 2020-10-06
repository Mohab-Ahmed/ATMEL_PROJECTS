/*
 * (PDF.3)ATMEGA16_CHALLENGE.c
 *
 * Created: 14-Aug-20 4:29:10 AM
 * Author : mohab
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 1000000
#endif

#include <util/delay.h>

uint8_t count=0;

ISR(INT2_vect)
{
	if ((PINB&(1<<PB2)))
	{
		_delay_ms(300);
		count++;
	}
}

int main(void)
{
	 DDRC|=(1<<PC0);
	 DDRC|=(1<<PC1);
	 DDRC|=(1<<PC2);
	 DDRC|=(1<<PC3);
	 
	 DDRB&=(~(1<<PB2));
	 
	 GICR|=(1<<INT2);
	 MCUCSR|=(1<<ISC2);
	 sei();
	 
	 
	 while (1)
	 {
		 if (count>9)
		 {
			 count=0;
		 }
		 PORTC=count;
	 }
}

