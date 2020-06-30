/************************************************

* Organisation Name		: Dot Hex Pvt. Ltd.
* Developer Name		: Prashant P. Hirave.
* Controller			: At89C51RD2
* IDE					: Keil4, Keil5.
* Language				: Embedded C. 

*************************************************/
/*
	On P0.0 - P0.7 attched four 7_segments
	and P2.0 - P2.3 used for control the anode of segment 
	here is code create for Common Anode 
*/

#include <REG51F.H>
#include "delay.h"

void row1();

sbit s1=P2^0;
sbit s2=P2^1;
sbit s3=P2^2;
sbit s4=P2^3;
sbit k4=P2^4;
sbit k5=P2^5;
sbit k6=P2^6;
sbit k7=P2^7;

unsigned char a[]={0xfc,0x60,0xda,0x0f2,0x66,0x0b6,0x0be,0x0e0,0x0fe,0x0f6};
unsigned char i;

void main()
{	 
	P0=0x00;
	while(1)
	{
	row1();
	P0=a[i];
	}
}

void row1()
{
	s1=0;
	s2=s3=s4=1;
	while(k4==0)
	{
	 P0=a[i];
	delay(500);
	i++;
	if(i==10)
	{
		i=0;
	}
	} 	
}
