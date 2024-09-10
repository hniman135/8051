#include <main.h>
void UART_mode1_Init()
{
    //mode 1
    SM0=0;
    SM1=1;
    //timer1 mode auto reload
    TMOD = 0x20;
    //baud rate 9600
    TH1 = 0xFD;
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
int main()
{
    UART_mode1_Init();
    while(1)
    {
        if (UART_Data_Ready()==1)
        {
            P2 = UART_Read();
        }
    }
}