#include "main.h"
#include "..\lib\UART_mode1.h"

int main()
{
	P1_0 = 0; //tat LED

	UART_mode1_Init();
	while(1)
	{
		 if (UART_Data_Ready())
		 {
		 	if(UART_Read()==0x01)
			{
				P1_0 = 1;
			}
			if(UART_Read()==0x00)
			{
				P1_0 = 0;
			}
		 }
	}
}