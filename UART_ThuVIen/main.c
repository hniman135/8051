#include "main.h"
#include "..\lib\UART_mode1.h"
#include <stdio.h>

int main()
{
	char c;
	UART_mode1_Init();
	printf("HELLO WORLD!!!");
	while(1)
	{
	   c = _getkey();
	   P2 = c;
	}
}							   