#include <reg52.h>
#include "lcd1602.h"
#include "tlc5615.h"
#include "wavedata.h"

#define uchar unsigned char
#define uint unsigned int
uint temp = 0;
uint Frequency = 10;
uchar Number_sin = 120;
uchar Number_Frequency = 0;
uchar mode = 2;
uchar TempBuffer[10] = {' '};
sbit Freq_ad = P3^3;
sbit Freq_de = P3^4;
sbit sine = P3^2;
sbit tria = P3^1;
sbit squa = P3^0;

void IntToStr(unsigned int t, unsigned char *str, unsigned char n) 
{
	unsigned char a[4]; char i, j;                                 	
	a[0]=(t/100)%10;                                      	
	a[1]=(t/10)%10;                                       	
	a[2]=(t/1)%10;                                        	
                                                      
	for(i=0; i<n; i++)         //化为ASCII             	
		a[i]=a[i]+'0';                                    	
	for(i=0; a[i]=='0' && i<=3; i++);     //转换高位的0为空格
	for(j=0; j<i; j++)
		{ *str=' ';  str++; }
	for(; i<n; i++)            //填充数字字符 	                             	
		{ *str=a[i]; str++; }
	*str='\0'; 
} 

/***************************************
函数名称：Deal_key
功能描述：按键检测
***************************************/
void Deal_key( void)
{
	if (sine == 0)
	{
		mode = 0;
		GotoXY( 0, 1);
		Print("sine");
	}
	if (tria == 0)
	{
		mode = 1;
		GotoXY( 0, 1);
		Print("tria");
	}
	if (squa == 0)
	{
		mode = 2;
		GotoXY( 0, 1);
		Print("squa");
	}
	if (Freq_de == 0)
	{
		while (Freq_de == 0);
		Frequency -= 1;
		
		IntToStr(Frequency, TempBuffer,3);
		GotoXY( 9, 0);
		Print(&TempBuffer[0]);
	}
	if (Freq_ad == 0)
	{
		while (Freq_ad == 0);
		Frequency += 1;
		IntToStr(Frequency, TempBuffer,3);
		GotoXY( 9, 0);
		Print(&TempBuffer[0]);
	}
}

void Timer_init(void)
{
	TMOD = 0x01;
//	TH0 = -20;
//	TL0 = -20;
	TH0 = -(8333 / Frequency / 256);
	TL0 = -(8333 / Frequency % 256);
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}

int main( void)
{
	unsigned int Count = 0;
	
	P0 = 0xff;
	P1 = 0xff;
	P2 = 0xff;
	P3 = 0xff;
	LCD_Initial();
	GotoXY(0,0);
	Print("    Freq: 10  Hz");
	GotoXY(0,1);
	Print("squa   Vpp : 5 V");
	Timer_init();

	while(1)
	{
		if (P3 != 0xff)
		{
			Deal_key();
		}

		if (mode == 0)
		{
			DA_out(sin[Number_Frequency]);
		}
		else if (mode == 1)
		{
			DA_out(triangle[Number_Frequency]);
		}
		else if (mode == 2)
		{
			DA_out(square[Number_Frequency / 60]);
		}
	}
}

void T0_ISR( void) interrupt 1
{
	TH0 = -(8333 / Frequency / 256);
	TL0 = -(8333 / Frequency % 256);
		Number_Frequency ++;
		if (Number_Frequency == Number_sin)
		{
			Number_Frequency = 0;
		}
}
