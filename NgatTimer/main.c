#include "main.h"
#include "..\lib\delay_ms.h"

unsigned char cnt = 10;

int main()
{
	TMOD &= 0xF0;
	TMOD |= 0x01;

	TH0= 0x3C;
	TL0= 0xB0;

	ET0 = 1;	//cho phep ngat timer0
	EA = 1;		//ngat toan cuc
	TR0 = 1;

	while(1)
	{
		PCON |= 0x01;
	}
}

void Timer0OverFlow (void) interrupt 1
{
	TH0 = 0x3C;
	TL0 = 0xB0;
	cnt --;
	if (cnt ==0)
	{
		cnt = 10;
		P2 = ~P2;
	}	
}