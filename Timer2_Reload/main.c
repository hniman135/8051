#include "main.h"

void delay_1s()
{
	unsigned char i;
	TR2 = 1;
	for (i=0; i<20; i++)
	{
		while(!TF2);
		TF2 = 0;
	}
	TR2 = 0;
}
int main()
{
	T2CON = 0x00;
	T2MOD = 0x00;

	RCAP2H = 0x3C;
	RCAP2L = 0xB0;
	TH2 = 0x3C;
	TL2 = 0xB2;
	while(1)
	{
	 	P2 = ~P2;
		delay_1s();
	}
}