/*
 * ATMEGA3290_EXTERNAL-INTERRUPT.c
 *
 * Created: 19-Jul-20 3:16:46 AM
 * Author : mohab
 */ 

#ifndef F_CPU
#define F_CPU 16000000
#endif

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


 ISR(INT0_vect)
 {
 	uint8_t temp=PORTA;
 	if (!(PIND&(1<<PD1)))
 	{
 		_delay_ms(30);
		 PORTA=0xff;
		 for(uint8_t i=0;i<9;i++)
		 {
			 _delay_ms(50);
			 PORTA^=0xff;
		 }
 	}
 	PORTA=temp;	
 }



int main(void)
{
	DDRA=0xff;
	DDRD&=(~(1<<PD1));
	PORTD|=(1<<PD1);
	
	//handling the interrupt
	EIMSK|=(1<<INT0);
	EICRA=0x00;
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
		PORTA=0x01;
		_delay_ms(10);
		for (int i=0;i<8;i++)
		{
			PORTA<<=1;
			_delay_ms(10);
		}
    }
}

