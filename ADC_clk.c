#define F_CPU 4915200L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
	DDRD |= (1<<DDD5);
	
	TCCR1A = (1<<COM1A1)|(1<<WGM11);  // Clear OCnA/OCnB on Compare Match, set OCnA/OCnB at TOP.
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10);   // Fast PWM, TOP=ICRn, Update OCRnx on TOP. // Prescaler = 1
	ICR1 = 4;
	OCR1A = 2;
	
    do{
    } while(1); 
}
