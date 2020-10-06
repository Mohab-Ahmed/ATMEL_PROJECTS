/*
 * ATMEGA16_EXERCISE-5.c
 *
 * Created: 11-Aug-20 2:20:19 AM
 * Author : mohab
 */ 

#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 1000000
#endif

#include <util/delay.h>

int main(void)
{
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

