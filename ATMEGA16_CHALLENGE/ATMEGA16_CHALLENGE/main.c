/*
 * ATMEGA16_CHALLENGE.c
 *
 * Created: 14-Aug-20 5:22:32 AM
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
	DDRD|=(1<<PC0);
	DDRD|=(1<<PC1);
	DDRD|=(1<<PC2);
	DDRD|=(1<<PC3);
	
	DDRA&=(~(1<<PA0));
	DDRA&=(~(1<<PA1));
	
	uint8_t count=0;
	PORTD=count;
	while (1)
	{
		if ((PINA&(1<<PA0)))
		{
			_delay_ms(300);
			if (count==9)
			{
				continue;
			}
			count++;
			PORTD=count;
		}
		else if ((PINA&(1<<PA1)))
		{
			_delay_ms(300);
			if (count==0)
			{
				continue;
			}
			count--;
			PORTD=count;
		}
	}
}

