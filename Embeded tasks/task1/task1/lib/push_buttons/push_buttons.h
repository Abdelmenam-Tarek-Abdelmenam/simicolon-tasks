#include "avr/io.h"

#define buttonPin PC1
#define buttonDirection DDRC
#define buttonPort PORTC
#define buttonPIN PINC




#ifndef PUSH_BUTTONS_H_
#define PUSH_BUTTONS_H_


void setButton();

void setPullUp();
char buttonValue();




#endif /* PUSH_BUTTONS_H_ */