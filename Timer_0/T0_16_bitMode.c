/************************************************

* Organisation Name		: Dot Hex Pvt. Ltd.
* Developer Name		: Prashant P. Hirave.
* Controller			: At89C51RD2
* IDE					: Keil4, Keil5.
* Language				: Embedded C. 

*************************************************/
/*
	Timer 0 used 16bit mode
	Delay = (65536 - 1 -XXYY)x 1.085 x 10^-6
*/

#include <REG51F.H>

sbit led=P0^6;

void main()
{
	P0=0x00;
	while(1)
	{
		TMOD =0X01;
		TL0 =0XFD;
		TH0 =0X4B;
		TR0=1;
		while(TF0==0);
		TF0=0;
		led=~led;	
	}			 
}
