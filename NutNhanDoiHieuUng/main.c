#include "main.h"
#include "..\lib\delay_ms.h"

#define LED P2
sbit BTN = P1^0;

unsigned char DelayNCheck()
{
	unsigned int i;
	for (i=0; i<50; i++)
	{
		delay_ms_timer(10);
		if(BTN == 0)
		{
			while(BTN == 0);
			return 1;
		}
	}
	return 0;
}
int main()
{
	unsigned int i;
	while(1)
	{
		
		LED = 0x00;
		for (i=0; i<20; i++)
		{
			if(DelayNCheck())
				break;
			LED = ~LED;
		}

		LED = 0x55;
		for (i=0; i<20; i++)
		{
			if(DelayNCheck())
				break;
			LED = ~LED;
		}

		LED = 0x0F;
		for (i=0; i<20; i++)
		{
			if(DelayNCheck())
				break;
			LED = ~LED;
		}
	}
}