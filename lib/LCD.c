#include "LCD.h"
#include "delay_ms.h"

//config HW
#define LCD_DATA P3
sbit LCD_RS = P2^0;
sbit LCD_EN = P2^1;


//LCD command MODE
void LCD_cmd(unsigned char cmd)
{
	LCD_RS = 0;
	LCD_DATA =  cmd;
	LCD_EN = 0;
	LCD_EN = 1;
	
	if (cmd <= 0x02)
	{
		delay_ms_timer(2);
	}	
	else
	{
		delay_ms_timer(1);
	}
}

//char current position
void LCD_chr_cp(unsigned char chr)	
{
	LCD_RS = 1;
	LCD_DATA =  chr;
	LCD_EN = 0;
	LCD_EN = 1;

	delay_ms_timer(2);
}

//string current position
void LCD_str_cp(unsigned char *str)
{
	unsigned int i = 0;
	while (str[i] != 0)
	{
		 LCD_chr_cp(str[i]);
		 i++;
	}
}

//LCD ClearScreen
void LCD_Clr()
{
	LCD_cmd(0x01);
}

//En = 1 to display pointer
void LCD_EnPnt(unsigned char En)
{
	if (En == 0)
	{
		LCD_cmd(0x0C);
	}
	else
	{
		 LCD_cmd(0x0E);
	}
}

//LCD INIT
void LCD_Init()
{
	LCD_cmd(0x30);
	delay_ms_timer(5);
	LCD_cmd(0x30);
	delay_ms_timer(1);
	LCD_cmd(0x30);

	LCD_cmd(0x38);		//2 dong, size 5x8
	//LCD_cmd(0x3C);		//2 dong, size 5x10
	//LCD_cmd(0x2C);		//(default) 1 dong, size 5x8

	LCD_EnPnt(0);
	LCD_Clr();
}

//Move pointer to line 2
void LCD_line2()
{
	LCD_cmd(0xC0);
}

//display char at any position
void LCD_chr(unsigned char col, unsigned char row, unsigned char chr)
{
   unsigned char cmd;
   cmd = (row==1?0x80:0xC0) + col - 1;
   LCD_cmd(cmd);

   LCD_chr_cp(chr);
}

//display string at any position
void LCD_str(unsigned char col, unsigned char row, unsigned char *str)
{
   unsigned char cmd;
   cmd = (row==1?0x80:0xC0) + col - 1;
   LCD_cmd(cmd);

   LCD_str_cp(str);
}