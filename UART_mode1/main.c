#include <main.h>
#include "..\lib\UART_mode1.h"
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