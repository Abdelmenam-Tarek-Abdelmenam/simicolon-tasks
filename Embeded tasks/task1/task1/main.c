/*
 * Task 1.c
 * Read the input from push button and put it on led
 *
 * Created: 7/17/2022 8:30:45 PM
 * Author : Abdelmenam Tarek
 */ 

#include "avr/io.h"



#include "lib/push_buttons/push_buttons.h"
#include "lib/led/led.h"


int main(void)
{

	setButton();
	setPullUp();
	setLed();
  
    while (1) 
    {
		if(buttonValue() == 0){
			ledOn();
		}else{
			ledOff();
		}
		
    }
}

