/*
 * ATMEGA16_EXERCISE-2.c
 *
 * Created: 07-Aug-20 3:57:17 PM
 * Author : mohab
 */ 

#include <avr/io.h>

#ifndef F_CPU
#define  F_CPU 1000000
#endif

#include <util/delay.h>

int main(void)
{
    DDRB&=(~(1<<PB0));	// configure pin 0 of PORTB to be input pin
    DDRB&=(~(1<<PB1));	// configure pin 1 of PORTB to be input pin
	DDRC|=(1<<PC0);		// configure pin 0 of PORTC to be output pin
	DDRC|=(1<<PC1);		// configure pin 1 of PORTC to be output pin
	
	PORTC&=(~(1<<PC0));	//initialize LED 0 to be off
	PORTC&=(~(1<<PC1));	//initialize LED 1 to be off
	 
    while (1) 
    {
		if((PINB&(1<<PB0))==0x01)
		{
			PORTC|=(1<<PC0);	//LED ON
		}
		else
		{
			PORTC&=(~(1<<PC0));	//LED OFF
		}
		if((PINB&(1<<PB1))==0x02)
		{
			PORTC|=(1<<PC1);	//LED ON
		}
		else
		{
			PORTC&=(~(1<<PC1));	//LED OFF
		}
    }
}

