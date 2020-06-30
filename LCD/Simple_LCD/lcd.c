/************************************************

* Organisation Name		: Dot Hex Pvt. Ltd.
* Developer Name		: Prashant P. Hirave.
* Controller			: At89C51RD2
* IDE					: Keil4, Keil5.
* Language				: Embedded C. 

*************************************************/
/*
	On P0.0 - P0.3 attched for control of LCD
	On P0.4 - P0.7 used 4bit of Lcd(pins D4 - D7)
	Here code is designed for 4-bit LCD architecture.
*/

#include <REG51F.H>
#include "delay.h"

sbit BK=P0^0;
sbit RS=P0^1;
sbit RW=P0^2;
sbit EN=P0^3;


void d_wr();
void c_wr();
void lcd_init();

unsigned char a,b;


void main()
{
	delay(10);
	lcd_init();
	ACC='A';
	d_wr();
	while(1);
}

void lcd_init()
{
	ACC=0x03;
	c_wr();
   	ACC=0x03;
	c_wr();
	ACC=0x03;
	c_wr();
	ACC=0x02;
	c_wr();
	ACC=0x28;
	c_wr();

	ACC=0x0e;
	c_wr();
	ACC=0x01;
	c_wr();
}

void c_wr()
{
	B=ACC;
	ACC=ACC&0xf0;

	P0=ACC;
	RS=0;
	RW=0;
	
	EN=1;
	delay(5);
	EN=0;

	B=B<<4;
	B=B&0xf0;
	P0=B;


	RS=0;
	RW=0;

	EN=1;
	delay(5);
	EN=0;
}
		 
void d_wr()
{
	B=ACC;
	ACC=ACC&0xf0;

	P0=ACC;
	RS=1;
	RW=0;
	
	EN=1;
	delay(5);
	EN=0;

	B=B<<4;
	B=B&0xf0;
	P0=B;


	RS=1;
	RW=0;

	EN=1;
	delay(5);
	EN=0;
}

