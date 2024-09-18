#include "main.h"

int main()
{
	T2CON = 0x00;
	T2MOD = 0x02;

	RCAP2H = 0xF4;
	RCAP2L = 0x48;

	TR2 = 1;
	while(1)
	{

	}
}