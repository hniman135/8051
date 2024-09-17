#include "main.h"
#include "..\lib\delay_ms.h"

unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
void Display(unsigned int N)
{
	unsigned char chucnghin, nghin, tram, chuc, dvi;
	chucnghin = N/10000;
	N %= 10000;
	nghin = N/1000;
	N %= 1000;
	tram = N/100;
	N %= 100;
	chuc = N/10;
	N %= 10;
	dvi = N/1;

	P0 = Code7Seg[chucnghin];
	P2_4 = 0;
	delay_ms_timer(1);
	P2_4 = 1;

	P0 = Code7Seg[nghin];
	P2_3 = 0;
	delay_ms_timer(1);
	P2_3 = 1;

	P0 = Code7Seg[tram];
	P2_2 = 0;
	delay_ms_timer(1);
	P2_2 = 1;

	P0 = Code7Seg[chuc];
	P2_1 = 0;
	delay_ms_timer(1);
	P2_1 = 1;

	P0 = Code7Seg[dvi];
	P2_0 = 0;
	delay_ms_timer(1);
	P2_0 = 1;
}

int main()
{
	unsigned char high, low;
	unsigned int number;	
	TMOD &= 0x0F;
	TMOD |= 0x50;
	TR1 = 1;

	while(1)
		
	{
		do{
		high = TH1;
		low = TL1;
		}while(high != TH1);
	
		number = high;
		number <<= 8;
		number |= low;
		Display(number);

	}
}