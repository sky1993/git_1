
#ifndef __TLC5615_H
#define __TLC5615_H

#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit CS  	= P1^2;
sbit CLK  	= P1^3;
sbit DIN  	= P1^1;
sbit DOUT  	= P1^0;

void DA_out(uint value);

#endif 