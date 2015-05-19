#ifndef __LCD1602_H
#define __LCD1602_H

#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int

//Port Definitions**********************************************************
sbit LcdRs		= P2^0;
sbit LcdRw		= P2^1;
sbit LcdEn  	= P2^2;
#define  DBPort P0

unsigned char LCD_Wait(void);
void LCD_Write(bit style, unsigned char input);
void LCD_SetDisplay(unsigned char DisplayMode);
void LCD_SetInput(unsigned char InputMode);
//void LCD_Move(unsigned char object, unsigned char direction)£»
void LCD_Initial(void);
void GotoXY(unsigned char x, unsigned char y);
void Print(unsigned char *str);
//void LCD_LoadChar(unsigned char user[8], unsigned char place);

#endif 
