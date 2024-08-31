#include <REGX52.H>
#include <..\lib\delay_ms.h>
void UART_mode0(sBUF)
{
    SM0 = SM1 = 0; //mode 0

    SBUF = sBUF; //data buf
    while (TI == 0); //co ngat truyen/nhan xong
    TI = 0;
	P3_2=0; //active shift register
	P3_2=1;
}
void delay_ms_timer(unsigned int t)
{
	unsigned int i;
	for (i=0; i<t; i++)
	{
		TMOD |= 0x01;
		TH0=0xFC;
		TL0=0x66;
		TR0=1;
		while (TF0 == 0);
		TR0 = 0;
		TF0 = 0;
	}
}
void main()
{
	
    while(1)
    {
        UART_mode0(0x00);
        delay_ms_timer(500);
        UART_mode0(0xFF);
        delay_ms_timer(500);
    }
}