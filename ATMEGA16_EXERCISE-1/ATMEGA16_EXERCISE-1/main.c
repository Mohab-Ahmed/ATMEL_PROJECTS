/*
 * ATMEGA16_EXERCISE-1.c
 *
 * Created: 07-Oct-20 12:06:37 AM
 * Author : mohab
 */ 

#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <util/delay.h>


int main(void)
{
	DDRD|=(1<<PB6);			//configure pin as outtput
	PORTD|=(1<<PB6);		//set pin as high to turn off led
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(100);		//delay 1 second
		PORTD^=(1<<PB6);
    }
}

