/*
 * ATMEGA16_EXERCISE-4.c
 *
 * Created: 14-Aug-20 5:06:54 AM
 * Author : mohab
 */ 

#include <avr/io.h>
#include <stdint.h>

#ifndef F_CPU
#define F_CPU 1000000
#endif

#include <util/delay.h>


int main(void)
{
    DDRC|=(1<<PC0);
    DDRC|=(1<<PC1);
    DDRC|=(1<<PC2);
    DDRC|=(1<<PC3);
	
	DDRD&=(~(1<<PD4));
	
	uint8_t count=0;
    while (1) 
    {
		if (count>9)
		{
			count=0;
		}
		PORTC=count;
		if ((PIND&(1<<PD4)))
		{
			_delay_ms(300);
			count++;
		}
    }
}

