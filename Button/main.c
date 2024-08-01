#include <REGX52.H>

void main (void)
{
	P2 &= ~(1 << 0);
	while (1)
	{
		if ((P2 & (1 << 1)) == 0)
		{
			P2 ^= 0x01;
		}
	}
}