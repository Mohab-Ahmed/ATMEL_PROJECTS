/*
 * ATMEGA3290_PUSH-BUTTON.c
 *
 * Created: 15-Jul-20 5:44:43 PM
 * Author : mohab
 */ 

#include <avr/io.h>

#define  DELAY(X) while(X--)


int main(void)
{
	DDRA=0xff;
	DDRB=0x00;

    /* Replace with your application code */
	uint32_t lenght;
    while (1) 
    {
		lenght=6000;
		if ((PINB&(1<<PB4))==0x10)
		{
			PORTA^=0xff;
			DELAY(lenght);
		}
    }
}

