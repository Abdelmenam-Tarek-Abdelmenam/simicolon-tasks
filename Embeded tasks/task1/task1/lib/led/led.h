#include "avr/io.h"

#define ledPin PC0
#define ledDirection DDRC
#define ledPort PORTC


#ifndef LED_H_
#define LED_H_

void setLed();

void toggleLed();
void ledOn();
void ledOff();


#endif /* LED_H_ */