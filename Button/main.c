#include <REGX52.H>

void delay_ms(unsigned int t){
	unsigned int i, j;
	for (i = 0; i < t; i++){
		for (j = 0; j < 125; j++);
	}
}

void main (void)
{
	P2 &= ~(1 << 0);
	while (1)
	{
		if ((P2 & (1 << 1)) == 0)
		{
			delay_ms(20);
			if ((P2 & (1 << 1)) == 0){
				P2 ^= (1 << 0);
			}
		}
	}
}