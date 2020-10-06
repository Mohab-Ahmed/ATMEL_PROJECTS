/*
 * ATMEGA3290_LED.c
 *
 * Created: 14-Jul-20 1:18:06 AM
 * Author : mohab
 */ 

#include <avr/io.h>
#include <stdint.h>

#define  DELAY(X) while(X--)

int main(void)
{
	DDRA=0xff;			//direction whether it's input or output
	uint32_t lenght;
    /* Replace with your application code */
    while (1) 
    {
		lenght=1000;
		PORTA^=0x01;	//since port is output then here we toggle between high or low
		DELAY(lenght);
    }
}

