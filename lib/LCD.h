#ifndef _LCD_H_
#define _LCD_H_
#include <regx52.h>
void LCD_cmd(unsigned char cmd);		//LCD command MODE
void LCD_chr_cp(unsigned char chr);		//char current position
void LCD_str_cp(unsigned char *str);	//string current position
void LCD_Init();						//LCD INIT
void LCD_Clr();							//LCD Clear Screen
void LCD_EnPnt(unsigned char En);		//En = 1 to display pointer
void LCD_line2();						//Move pointer to line 2
void LCD_chr(unsigned char col, unsigned char row, unsigned char chr);	//display char at any position
void LCD_str(unsigned char col, unsigned char row, unsigned char *str);	//display string at any position


#endif