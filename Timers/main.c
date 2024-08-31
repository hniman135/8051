#include <REGX52.H>
void delay_ms_timer(unsigned int t)
    {
        unsigned int i;
        for (i=0; i<t; i++)
        {
            TMOD |= 0x01; //timer 0 mode 1 = mode 16bit
            TH0=0xFC; 
            TL0=0x66;
            TR0=1; //timer run
            while (TF0 == 0); //tran timer
            TR0 = 0;
            TF0 = 0;
        }
    }
int main()
{
    while (1);
}