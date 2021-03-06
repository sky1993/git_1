
#ifndef __WAVEDATA_H
#define __WAVEDATA_H

#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int

code uint sin[120] = {
	512 ,538 ,565 ,592 ,618 ,
	644 ,670 ,695 ,720 ,744 ,
	767 ,790 ,812 ,833 ,854 ,
	873 ,892 ,909 ,925 ,940 ,
	954 ,967 ,979 ,989 ,998 ,
	1006 ,1012 ,1017 ,1020 ,1022 ,
	1023 ,1022 ,1020 ,1017 ,1012 ,
	1006 ,998 ,989 ,979 ,967 ,
	954 ,940 ,925 ,909 ,892 ,
	873 ,854 ,833 ,812 ,790 ,
	767 ,744 ,720 ,695 ,670 ,
	644 ,618 ,592 ,565 ,538 ,
	512 ,485 ,458 ,431 ,405 ,
	379 ,353 ,328 ,303 ,279 ,
	256 ,233 ,211 ,190 ,169 ,
	150 ,131 ,114 ,98 ,83 ,
	69 ,56 ,44 ,34 ,25 ,
	17 ,11 ,6 ,3 ,1 ,
	0 ,1 ,3 ,6 ,11 ,
	17 ,25 ,34 ,44 ,56 ,
	69 ,83 ,98 ,114 ,131 ,
	150 ,169 ,190 ,211 ,233 ,
	256 ,279 ,303 ,328 ,353 ,
	379 ,405 ,431 ,458 ,485 ,
};

code uint triangle[120] = {
	0 , 17 , 34 , 51 , 68 , 
	85 , 102 , 119 , 136 , 153 , 
	171 , 188 , 205 , 222 , 239 , 
	256 , 273 , 290 , 307 , 324 , 
	341 , 358 , 375 , 392 , 409 , 
	426 , 443 , 460 , 477 , 494 , 
	512 , 529 , 546 , 563 , 580 , 
	597 , 614 , 631 , 648 , 665 , 
	682 , 699 , 716 , 733 , 750 , 
	767 , 784 , 801 , 818 , 835 , 
	853 , 870 , 887 , 904 , 921 , 
	938 , 955 , 972 , 989 , 1006 , 
	1023 , 1006 , 989 , 972 , 955 , 
	938 , 921 , 904 , 887 , 870 , 
	853 , 835 , 818 , 801 , 784 , 
	767 , 750 , 733 , 716 , 699 , 
	682 , 665 , 648 , 631 , 614 , 
	597 , 580 , 563 , 546 , 529 , 
	512 , 494 , 477 , 460 , 443 , 
	426 , 409 , 392 , 375 , 358 , 
	341 , 324 , 307 , 290 , 273 , 
	256 , 239 , 222 , 205 , 188 , 
	171 , 153 , 136 , 119 , 102 , 
	85 , 68 , 51 , 34 , 17 ,
};
code uint square[2] = {	0 , 1023 };

#endif 