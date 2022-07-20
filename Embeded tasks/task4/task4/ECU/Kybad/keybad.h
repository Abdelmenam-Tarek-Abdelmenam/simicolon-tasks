#define F_CPU 1000000
#include "avr/io.h"
#include <util/delay.h>


#ifndef KEYBAD_H_
#define KEYBAD_H_


#define KEY_PRT PORTD
#define KEY_DDR	DDRD
#define KEY_PIN	PIND

char detectKeyPressed();


#endif /* KEYBAD_H_ */