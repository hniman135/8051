#include <REGX52.H>

//void delay_ms(unsigned int t){
//	unsigned int x, y;
//	for (x = 0; x < t; x++){
//		for (y = 0; y < 125; y++);
//	}
//}
void delay_ms_timer(unsigned int t)
{
	unsigned int i;
	for (i=0; i<t; i++)
	{
		TMOD |= 0x01;
		TH0=0xFC;
		TL0=0x66;
		TR0=1;
		while (TF0 == 0);
		TR0 = 0;
		TF0 = 0;
	}
}
void main (void){
	while (1){
		P1 ^= 0x01;
		//delay_ms(1000);
		delay_ms_timer(1000);
	}
}