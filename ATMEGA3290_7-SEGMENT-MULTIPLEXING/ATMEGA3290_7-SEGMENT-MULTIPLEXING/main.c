/*
 * ATMEGA3290_7-SEGMENT-MULTIPLEXING.c
 *
 * Created: 14-Aug-20 4:52:02 PM
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
	
	DDRF|=(1<<PF0);
	DDRF|=(1<<PF1);
	DDRF|=(1<<PF2);
	
	
    while (1) 
    {
    }
}

