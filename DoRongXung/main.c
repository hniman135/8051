#include "main.h"
#include "..\lib\LCD4.h"

int main()
{
	unsigned int F, width;
	Lcd_Init();
	Lcd_Out(1,1, "Width = ");
	Lcd_Out(2,1, "F = ");
	TMOD &= 0xF0;
	TMOD |= 0x09;

	while(1)
	{
		TH0 = 0;
		TL0 = 0;
		
		while(INT0);	//bypass muc 1 dau tien
		while(!INT0);	//bypass muc 0 dau tien
		
		TR0 = 1;
		while(INT0);
		TR0 = 0;
		
		width = TH0;
		width <<= 8;
		width |= TL0;
		
		Lcd_Chr(1, 9, width/10000 + 0x30);
		Lcd_Chr_Cp(width%10000/1000 + 0x30);
		Lcd_Chr_Cp(width%1000/100 + 0x30);
		Lcd_Chr_Cp(width%100/10 + 0x30);
		Lcd_Chr_Cp(width%10/1 + 0x30);
		
		F = 1000000/width/2;
		Lcd_Chr(2, 9, F/10000 + 0x30);
		Lcd_Chr_Cp(F%10000/1000 + 0x30);
		Lcd_Chr_Cp(F%1000/100 + 0x30);
		Lcd_Chr_Cp(F%100/10 + 0x30);
		Lcd_Chr_Cp(F%10/1 + 0x30);	
	}
}