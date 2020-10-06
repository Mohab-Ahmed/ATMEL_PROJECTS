/*
 * (PDF.3)ATMEGA16_EXERCISE-2.c
 *
 * Created: 14-Aug-20 3:51:51 AM
 * Author : mohab
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#ifndef F_CPU
#define F_CPU 1000000
#endif

#include <util/delay.h>

ISR(INT1_vect)
{
	uint8_t temp=PORTC;
	if ((PIND&(1<<PD3)))
	{
		_delay_ms(300);		//switch bounce counter
		PORTC=0xff;
		for(uint8_t i=0;i<9;i++)
		{
			_delay_ms(500);
			PORTC^=0xff;
		}
	}
	PORTC=temp;
}


int main(void)
{
	DDRC|=0xff;				//set port C as output
	DDRD&=(~(1<<PD3));		//set pin 3 in port D as input
	
	sei();					//enable I-bit in status register
	GICR|=(1<<INT1);		//enable INT1 interrupt in global register
	MCUCR|=(1<<ISC10);		//set it to high level
	
    while (1) 
    {
		PORTC|=(1<<PC0);
		for(uint8_t i=0;i<8;i++)
		{
			_delay_ms(300);
			PORTC<<=1;
		}
    }
}

