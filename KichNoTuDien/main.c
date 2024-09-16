#include "main.h"
#include "..\lib\delay_ms.h"


#define SEG P0
sbit BTN = P1^0;
sbit TRG = P2^0;
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
int main()
{
	signed char i;
	while(1)
	{
		if (BTN == 0)
		{
			
			while (BTN == 0);
			for (i=9; i>=0; i--)
			{
				SEG = Code7Seg[i];
				delay_ms_timer(1000);
			}
			TRG = 0;
			for (i=0; i<10; i++)
			{
				SEG = Code7Seg[i];
				delay_ms_timer(1000);
			}
			TRG = 1;
		}
	}
}