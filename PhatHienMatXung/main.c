#include "main.h"

int main()
{
	T2CON = 0x08;
	T2MOD = 0x00;

	RCAP2H = 0x3C;
	RCAP2L = 0xB0;

	P2 = 0x00;

	ET2 = 1;	//ngat tim2
	EA = 1;		//ngat toan cuc
	while(1)
	{

	}
}

void Timer2_Overflow(void) interrupt  5
{
	if(EXF2)
	{
		TR2 =1;
		EXF2 =0;	
	}
	else
	{
		TR2 = 0;
		P2++;
		TF2 =0;
	}	
}