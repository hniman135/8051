#include "delay.h"

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