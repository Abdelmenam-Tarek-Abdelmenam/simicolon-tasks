/*
 * task3.c
 *
 * Created: 7/17/2022 11:14:49 PM
 * Author : Abdelmenam Tarek
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define sevenSeg PORTC

const unsigned char sagment[10]= {0b00111111 ,0b0000110 ,0b01011011 ,0b01001111 ,0b01100110 ,0b01101101 ,0b01111101 ,0b01000111 ,0xff,0b01101111 } ;


int main(void)
{
	DDRC = 0XFF;
	unsigned char num = 0;
	
    while (1) 
    {
		_delay_ms(1000);
		num ++ ;
		if(num == 10)num=0;
		PORTC = sagment[num];
		
    }
}

