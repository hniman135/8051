#include "main.h"
#include "..\lib\delay_ms.h"
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
sbit RED = P0^0;
sbit YELLO = P0^1;
sbit GREEN = P0^2;

#define CHUC P2
#define DVI P3

int main()
{
	signed char i;
	while(1)
	{
		//RED LED
		RED = 0;
		YELLO = 1;
		GREEN = 1;
		for (i=20; i>=0; i--)
		{
			CHUC = Code7Seg[i/10];
			DVI = Code7Seg[i%10];
			delay_ms_timer(1000);		
		}

		//GREEN LED
		RED = 1;
		YELLO = 1;
		GREEN = 0;
		for (i=16; i>=0; i--)
		{
			CHUC = Code7Seg[i/10];
			DVI = Code7Seg[i%10];
			delay_ms_timer(1000);		
		}

		 //RED LED
		RED = 1;
		YELLO = 0;
		GREEN = 1;
		for (i=4; i>=0; i--)
		{
			CHUC = Code7Seg[i/10];
			DVI = Code7Seg[i%10];
			delay_ms_timer(1000);		
		}

	}
}