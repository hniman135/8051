#include <REGX52.H>

sbit LCD_RS = P2^0;
sbit LCD_RW = P2^1;
sbit LCD_EN = P2^2;

#define LCD_data P1
void delay_ms(unsigned int t){
	unsigned int x, y;
	for (x = 0; x < t; x++){
		for (y = 0; y < 125; y++);
	}
}

void LCD_Cmd(unsigned char cmd){
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_data = cmd;
	LCD_EN = 0;
	LCD_EN = 1;
	if (cmd<=0x02){
		delay_ms(2);
	}
	else{
		delay_ms(1);
	}
}

void LCD_char(unsigned char c){
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_data = c;
	LCD_EN = 0;
	LCD_EN = 1;
	delay_ms(1);
}

void LCD_string(unsigned char *str){
	unsigned int i = 0;
	while (str[i] != 0){
		LCD_char(str[i]);
		i++;
	}
}

void LCD_Init(){
	LCD_Cmd(0x30);
	delay_ms(5);
	LCD_Cmd(0x30);
	delay_ms(1);
	LCD_Cmd(0x30);
	
	//so dong: 2, font: 5x8
	LCD_Cmd(0x38);
	//clrscr
	LCD_Cmd(0x01);
	//bat hien thi va con tro
	LCD_Cmd (0x0E);
}

void main(void){
	LCD_Init();
	LCD_string("HUYEN");
	LCD_Cmd(0xC0);
	LCD_string("TRAM");
	while(1){
	
	}
}