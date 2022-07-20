/*
 * lcd.c
 * Created: 7/19/2022 8:48:03 PM
 *  Author: Abdelmenam
 */ 
#include "lcd.h"

void lcdWriteCmd(unsigned char cmd){
	LCD_Port= cmd;
	LCD_Command_Port &= ~(1<<RS);	/* RS=0 command reg. */
	LCD_Command_Port |= (1<<EN);	/* Enable pulse */
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(3);
	
}


void  lcdInit(){
	LCD_Command_Dir = 0xFF;	/* Make LCD command port direction as o/p */
	LCD_Dir = 0xFF;	/* Make LCD data port direction as o/p */

	_delay_ms(20);		/* LCD Power ON delay always >15ms */
	lcdWriteCmd(0x38);	/* Initialization of 16X2 LCD in 8bit mode */
	lcdWriteCmd(0x0C);	/* Display ON Cursor OFF */
	lcdWriteCmd(0x06);	/* Auto Increment cursor */
	lcdWriteCmd(0x01);	/* clear display */
	lcdWriteCmd(0x80);	/* cursor at home position */
}

void lcdWriteChar(unsigned char charachter){
	LCD_Port = charachter;
	LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
	LCD_Command_Port |= (1<<EN);	/* Enable Pulse */
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(1);
}


void lcdPrint(const char* text ){
	
	for(uint8_t i=0 ; i< strlen(text) ; i++){
		lcdWriteChar(text[i]);
	}
}

void lcdNewLine(){
		lcdWriteCmd(0xC0);		/* Go to 2nd line*/
}

void lcdClear(){
	lcdWriteCmd(0x01);
}