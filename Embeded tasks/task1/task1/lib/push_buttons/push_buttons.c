/*
 * push_buttons.c
 *
 * Created: 7/17/2022 10:48:30 PM
 *  Author: Abdelmenam Tarek
 */ 

#include "push_buttons.h"


void setButton(){
	buttonDirection &= ~(1<<buttonPin)  ;
}

void setPullUp(){
	buttonPort |= (1<< buttonPin ) ; 
}

char buttonValue(){
	return (PINC >>buttonPin) & 1 ;
}