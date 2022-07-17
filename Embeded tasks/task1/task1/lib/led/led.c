/*
 * led.c
 *
 * Created: 7/17/2022 8:41:47 PM
 *  Author: Abdelmenam Tarek
 */ 

#include "led.h"


void setLed(){
	ledDirection |= (1<< ledPin ) ;
}


void toggleLed(){
	ledPort ^= 1 << ledPin ;
}

void ledOn(){
	ledPort |= 1<<ledPin; 
}

void ledOff(){
	ledPort &= ~(1<<ledPin);
}