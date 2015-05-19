
#include "lcd1602.h"

//内部等待函数**************************************************************
unsigned char LCD_Wait(void)
{
	LcdRs=0;
	LcdRw=1;	_nop_();
	LcdEn=1;	_nop_();
//	while(DBPort&0x80);
	LcdEn=0;
	return DBPort;		
}
//向LCD写入命令和数据*****************************************************
#define LCD_COMMAND			0      // Command
#define LCD_DATA			1      // Data
#define LCD_CLEAR_SCREEN	0x01      // ??
#define LCD_HOMING  		0x02      // ??????
void LCD_Write(bit style, unsigned char input)
{
	LcdEn=0;
	LcdRs=style;
	LcdRw=0;		_nop_();
	DBPort=input;	_nop_();//????
	LcdEn=1;		_nop_();//????
	LcdEn=0;		_nop_();
	LCD_Wait();	
}

//设置显示模式***********************************************************
#define LCD_SHOW			0x04    //???
#define LCD_HIDE			0x00    //???	  

#define LCD_CURSOR			0x02 	//????
#define LCD_NO_CURSOR		0x00    //???		     

#define LCD_FLASH			0x01    //????
#define LCD_NO_FLASH		0x00    //?????

void LCD_SetDisplay(unsigned char DisplayMode)
{
	LCD_Write(LCD_COMMAND, 0x08|DisplayMode);	
}

//设置输入模式**************************************************
#define LCD_AC_UP			0x02
#define LCD_AC_DOWN			0x00      // default

#define LCD_MOVE			0x01      // ?????
#define LCD_NO_MOVE			0x00      //default

void LCD_SetInput(unsigned char InputMode)
{
	LCD_Write(LCD_COMMAND, 0x04|InputMode);
}

//???????************************************************************
/*
#define LCD_CURSOR		0x02      
#define LCD_SCREEN		0x08
#define LCD_LEFT		0x00
#define LCD_RIGHT		0x04
void LCD_Move(unsigned char object, unsigned char direction)
{
	if(object==LCD_CURSOR)
		LCD_Write(LCD_COMMAND,0x10|direction);
	if(object==LCD_SCREEN)
		LCD_Write(LCD_COMMAND,0x18|direction);
}
*/
//初始化LCD************************************************************
void LCD_Initial(void)
{
	LcdEn=0;
	LCD_Write(LCD_COMMAND,0x38);           //8?????,2???,5*7??
	LCD_Write(LCD_COMMAND,0x38);
	LCD_SetDisplay(LCD_SHOW|LCD_NO_CURSOR);    //????, ???
	LCD_Write(LCD_COMMAND,LCD_CLEAR_SCREEN);   //??
	LCD_SetInput(LCD_AC_UP|LCD_NO_MOVE);       //AC??, ????
}

//************************************************************************
void GotoXY(unsigned char x, unsigned char y)
{
	if(y==0)
		LCD_Write(LCD_COMMAND,0x80|x);
	if(y==1)
		LCD_Write(LCD_COMMAND,0x80|(x-0x40));
}
void Print(unsigned char *str)
{
	while(*str!='\0')
	{
		LCD_Write(LCD_DATA,*str);
		str++;
	}
}
/*
void LCD_LoadChar(unsigned char user[8], unsigned char place)
{
	unsigned char i;
	LCD_Write(LCD_COMMAND,0x40|(place*8));
	for(i=0; i<8; i++)
		LCD_Write(LCD_DATA,user[i]);
}
*/

