#include "main.h"
#include "..\lib\UART_mode1.h"
#include "..\lib\delay_ms.h"
int main()
{
	UART_mode1_Init();
	while(1)
	{
		//ON button
		if (P1_0 == 0)
		{
			delay_ms_timer(20);
			UART_Write(0x01);
			while(P1_0 == 0);
		}
		//OFF button
		if (P1_1 == 0)
		{
			delay_ms_timer(20);
			UART_Write(0x00);
			while(P1_1 == 0);
		}
	}
}