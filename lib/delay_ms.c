#include "delay_ms.h"
void delay_ms_timer(unsigned int t)
    {
        unsigned int i;
        for (i=0; i<t; i++)
        {
            TMOD |= 0x00; //timer 0 mode 0 = mode 13bit
            TH0=0xE0; 
            TL0=0x18;
            TR0=1; //timer run
            while (TF0 == 0); //tran timer
            TR0 = 0;
            TF0 = 0;
        }
    }