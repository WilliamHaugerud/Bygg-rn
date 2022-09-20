#define F_CPU 4915200UL
#include <avr/io.h>
#include<stdio.h>
#include <util/delay.h>
#define BASE_ADDRESS 0x1000
#define ADC_ADDRESS_SPACE 0x0400
#define SRAM_ADDRESS_SPACE 0x1800


void XMEM_init(void){
	MCUCR |= (1<<SRE); //enable XMEM
	SFIOR |= (1<<XMM2); // Masking P7-P4
}
void XMEM_write(uint8_t data, uint16_t addr){
	volatile char *ext_mem = (char *) BASE_ADDRESS;
	ext_mem[addr]= data;
}
uint8_t XMEM_read(uint16_t addr){
	volatile char *ext_mem = (char *) BASE_ADDRESS;
	uint8_t ret_val = ext_mem[addr];
	return ret_val;
}


int main(void)
{
	XMEM_init();
	
    /* Replace with your application code */
    while (1) 
    {
		
		XMEM_write(1, 0x0500);
		_delay_ms(1);
    }
}
