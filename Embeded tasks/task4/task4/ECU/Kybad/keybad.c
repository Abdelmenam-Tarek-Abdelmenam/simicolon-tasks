/*
 * keybad.c
 *
 * Created: 7/20/2022 9:24:18 AM
 *  Author: Abdelmenam
 */ 

#include "keybad.h"

unsigned char keypadMaterix[4][4] = {	{'7','8','9','/'},
{'4','5','6','*'},
{'1','2','3','-'},
{'C','0','=','+'}};
	
	
char detectKeyPressed()
{
	KEY_DDR = 0x0F;           /* set port direction as input-output */
	KEY_PRT = 0xFF; // All on
	
	char val = '\n';
	unsigned char coll, row;
	for(row=0 ; row<4 ; row++ ){
		KEY_PRT &= ~(1<<row) ;
		for(coll=4 ; coll<8 ; coll++){
			unsigned char read = (KEY_PIN >>coll) & 1 ;
			if(read == 0){
				while(read == 0){
					read = (KEY_PIN >>coll) & 1 ;
					_delay_ms(1);
				}
				val = keypadMaterix[row][coll-4];
				break;
			}
			if(val != '\n') break;
						
		}
		KEY_PRT |= 1<<row ;
	}
	
	return val;

}