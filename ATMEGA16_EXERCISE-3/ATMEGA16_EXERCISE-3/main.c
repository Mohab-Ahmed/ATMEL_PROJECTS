/*
 * ATMEGA16_EXERCISE-3.c
 *
 * Created: 10-Aug-20 3:49:49 AM
 * Author : mohab
 */ 

#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 1000000
#endif

#include <util/delay.h>

int main(void)
{
    DDRB&=(~(1<<PB0));	//initialize port B as input
    PORTB|=(1<<PB0);	//Enable pull up resistor
	
    DDRC|=(1<<PC0);		//initialize port c as output
	PORTC|=(1<<PC0);	//initialize the LED as closed 
	
	uint8_t check_button=0;
	
    while (1) 
    {
		//in case of switch connected in pull up configuration
 		if ((!(PINB&(1<<PB0))))
 		{
 			_delay_ms(30);
			 if (check_button==0)
			 {
				 PORTC^=(1<<PC0);
				 check_button=1;
			 }
 		}
		 else
		 {
			 check_button=0;
		 }

		
		//in case of switch connected in pull down configuration
/*
// 
//   		if ((PINB&(1<<PB0))==0x01)
//   		{
//   			_delay_ms(30);
//   			if (check_button==0)
// 			{
// 				PORTC^=(1<<PC0);
// 				check_button=1;
// 			}
//   		}
// 		else
// 		{
// 				check_button=0;
// 		}
*/


    }
}

