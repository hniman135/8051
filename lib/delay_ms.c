#include "delay_ms.h"
void delay_ms_timer(unsigned int t)
    {
        unsigned int i;
		TMOD &= 0xF0;
        TMOD |= 0x01; //timer 0 mode 1 = mode 16bit
        for (i=0; i<t; i++)
        {	
            TH0=0xFC; 
            TL0=0x2B;
            TR0=1; //timer run
            while (TF0 == 0); //tran timer
            TR0 = 0;
            TF0 = 0;
        }
    }