#include <REGX52.H>
void UART_mode0_Input()
{
    //uart mode 0
    SM0 = SM1 = 0;
    // cho phep nhan du lieu
    REN = 1;
}
int main()
{
    UART_mode0_Input();
    while (1)
    {
        //tao xung chot SH/LD 74165
        P3_2 = 0;
        P3_2 = 1;

        RI = 0;
        while (RI == 0);
        P2 = SBUF;
    }
    
}