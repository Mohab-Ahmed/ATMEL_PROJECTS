/*
 * ATMEGA3290_DC-MOTOR.c
 *
 * Created: 17-Jul-20 5:27:41 PM
 * Author : mohab
 */ 

#include <avr/io.h>


int main(void)
{
	DDRE=0xff;
	uint32_t lenght;
    /* Replace with your application code */
    while (1) 
    {
		if ((PINA&(1<<PA0))==0x01)
		{
			lenght=100000;
			PORTE=0x01;
			while(lenght--);
			PORTE=0x02;
			lenght=100000;
			while(lenght--);
		}else{PORTE=0x00;}
		
    }
}

