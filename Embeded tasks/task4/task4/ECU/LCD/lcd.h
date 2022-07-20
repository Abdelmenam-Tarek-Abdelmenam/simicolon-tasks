#include "avr/io.h"

#define F_CPU 1000000
#include <util/delay.h>
#include <string.h>

#ifndef LCD_H_
#define LCD_H_

#define LCD_Dir DDRC		
#define LCD_Port PORTC

#define LCD_Command_Dir DDRA		/* Define LCD command port direction register */
#define LCD_Command_Port PORTA		/* Define LCD data port */	
#define RS PA0								
#define EN PA1				

void lcdInit();

void lcdWriteCmd(unsigned char cmd);

void lcdWriteChar(unsigned char charachter);
void lcdPrint(const char* text );
void lcdNewLine();
void lcdClear();



#endif /* LCD_H_ */