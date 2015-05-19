#include "tlc5615.h"

void DA_out(uint value)
{
	uchar i = 0;
	
	CS = 0;
	for (i = 0; i < 10; i++)
	{
		if (value & (0x0200 >> i))
		{
			DIN = 1;
		}
		else
		{
			DIN = 0;
		}
		CLK  = 1;
		
		CLK  = 0;
	}
	CLK  = 1;
	CLK  = 0;

	CLK  = 1;
	CLK  = 0;

	CS = 1;
}
