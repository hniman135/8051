#include <REGX52.H>

void delay_ms(unsigned int t){
	unsigned int x, y;
	for (x = 0; x < t; x++){
		for (y = 0; y < 125; y++);
	}
}

void main (void){
	while (1){
		P1 ^= 0x01;
		delay_ms(1000);
	}
}