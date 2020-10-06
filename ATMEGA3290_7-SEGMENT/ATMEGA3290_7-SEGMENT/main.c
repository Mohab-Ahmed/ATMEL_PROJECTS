/*
 * ATMEGA3290_7-SEGMENT.c
 *
 * Created: 14-Aug-20 4:56:30 AM
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
    DDRE|=(1<<PE0);
    DDRE|=(1<<PE1);
    DDRE|=(1<<PE2);
    DDRE|=(1<<PE3);
    while (1) 
    {
		for(uint8_t i=0;i<10;i++)
		{
			PORTE=i;
			_delay_ms(1000);
		}
    }
}

