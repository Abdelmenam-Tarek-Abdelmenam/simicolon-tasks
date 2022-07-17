/*
 * task2.c
 *
 * Created: 7/17/2022 11:14:49 PM
 * Author : Abdelmenam Tarek
 */ 

#include <avr/io.h>

#define num1 PINA
#define num2 PINB

#define sevenSeg PORTC

const unsigned char sagment[10]= {0b00111111 ,0b0000110 ,0b01011011 ,0b01001111 ,0b01100110 ,0b01101101 ,0b01111101 ,0b01000111 ,0xff,0b01101111 } ;


int main(void)
{
    DDRA = 0X00;
	DDRB = 0X00;
	DDRC = 0XFF;
	
    while (1) 
    {
		unsigned char sum = num1 + num2 ;
		PORTC = sagment[sum];
		
    }
}

