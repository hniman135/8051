#include "Soft_SPI.h"
#include "port.h"

void Soft_SPI_Init()
{
	SPI_CS = 1;
	SPI_SCLK = 0;
	SPI_MISO = 1;	
}

void Soft_SPI_Write(unsigned char b)
{
	unsigned char i;
	for (i=0; i<8; i++)
	{
		if(b&0x80 !=0)
			SPI_MOSI = 1;
		else
			SPI_MOSI = 0;
		SPI_SCLK = 1;
		SPI_SCLK = 0;
		b<<1;
	}	
}

unsigned char Soft_SPI_Read()
{
	unsigned char i, b;
	for (i=0; i<8; i++)
	[
		b<<1;
		SPI_SCLK =1;
		if(SPI_MISO)
			b|= 0x01;
		SPI_SCLK = 0;
	]
	return b;
}