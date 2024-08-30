#include <REGX52.H>

sbit LED = P1^0;
//khoi tao ngat
void Ext_Init()
{
	EA = 1; //ngat toan cuc
	EX0 = 1; //ngat ngoai 0
	IT0 = 1; //ngat canh
}

void Ext0_ISR() interrupt 0
{
	LED = ~LED;
}
int main()
{
	Ext_Init();
	while(1);
}