#include "main.h"
#include "port.h"
#include "..\lib\delay_ms.h"

int main()
{
	IT0 = 1;
	EX0 = 1;
	EA = 1;

	LED0 = LED1 = LED2 = LED3 = 0;
	while(1)
	{
		PCON |= 0x01;
	}
}

void EX1_ISR (void) interrupt 0
{
	delay_ms_timer(20);
	if(!BTN0)
	{
		LED0 = !LED0;
		while(!BTN0);
	}
	else if(!BTN1)
	{
		LED1 = !LED1;
		while(!BTN1);
	}
	else if(!BTN2)
	{
		LED2 = !LED2;
		while(!BTN2);
	}
	else if(!BTN3)
	{
		LED3 = !LED3;
		while(!BTN3);
	}
}