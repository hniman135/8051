#include "main.h"
#include "..\lib\UART_mode1.h"

void UART_mode1_Init()
{
    //mode 1
    SM0=0;
    SM1=1;
    //timer1 mode auto reload
    TMOD &= 0x0F;
	TMOD |= 0x20;

    //baud rate 9600
	#if (BAUD_RATE == 9600)
    TH1 = 0xFD;
	#elif (BAUD_RATE == 2400)
    TH1 = 0xF4;
	#elif (BAUD_RATE == 1200)
    TH1 = 0xE8;
	#elif (BAUD_RATE == 19200)
    TH1 = 0xFD;
	PCON |= 0x80;
	#else
	 #error "vui long chon baud rate la 1 trong cac gia tri 1200 2400 9600 hoac 19200"
	#endif
    //run timer1
    TR1=1;
    //san sang gui du lieu
    TI=1;
    //cho phep nhan du lieu
    REN=1;
}

void UART_Write(char c)
{
    while(TI==0);
    TI=0;
    SBUF=c;
}

char UART_Data_Ready()
{
    return RI;
}
char UART_Read()
{
    RI=0;
    return SBUF;
}