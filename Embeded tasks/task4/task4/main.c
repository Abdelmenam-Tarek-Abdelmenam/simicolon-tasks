/*
 * task4.c
 * calculator
 * Created: 7/20/2022 9:19:28 AM
 * Author : Abdelmenam
 */ 

#include "ECU\LCD\lcd.h"
#include "ECU\Kybad\keybad.h"


uint8_t num1 = 0;
uint8_t num2 = 0 ;
unsigned char op = '0' ; // 0 mean no operation 

int calculate();
void calculatorAction(unsigned char button);
void show_sum(int sum);


int main(void)
{
    lcdInit();
	lcdPrint("Somicolon Task4");
	lcdNewLine();
	lcdPrint("Menam elbahy");
	_delay_ms(1000);
	lcdClear();

	while (1) 
    {
		unsigned char button = detectKeyPressed();
		if(button != '\n'){
			if(button == 'C'){
				num1 = 0 ;
				num2 = 0;
				op = '0';
				lcdClear();
			} else if(button == '/' || button == '+' || button == '-' || button == '*'){
				op = button ;
				lcdWriteChar(button);
			}else if(button == '='){
				lcdWriteChar(button);
				int sum =  calculate();
				show_sum(sum);
			}else{
				calculatorAction(button);			
			}
		}
		
		
    }
}


void calculatorAction(unsigned char button){

	if(op == '0'){
		num1 = num1*10 +button - 48; 
		lcdWriteChar(button);
	}
	else{
		num2 = num2*10 + button - 48;
		lcdWriteChar(button);
	}
	
	
	
}

int calculate(){
	switch (op)
	{
		case '+' :
		return (num1 + num2) ;
		case '-' :
		return (num1 - num2) ;
		case '*' :
		return (num1 * num2) ;
		case '/' :
		return (num1 / num2) ;
	}
	return num1;

}

void show_sum(int sum){
	int counter=0 ;
	int array[10];
	while(sum != 0)
	{
		array[counter] = sum%10 ;
		counter ++ ;
		sum=sum/10;
	}
	counter -- ;
	for(counter ; counter >=0 ; counter -- ){
		lcdWriteChar(48+array[counter]);
	}
}

