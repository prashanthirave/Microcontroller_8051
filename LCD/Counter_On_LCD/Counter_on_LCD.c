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
#include "lcd_header.h"

unsigned char a,b,i,j;
void main()
{
	delay(10);
	lcd_init();
	lcd_string("Counter");
	c_wr(0xc0);	
	
	 while(1)
	 {
		  b=0x30;
		for(j=0;j<10;j++)
	 	{	
	 		c_wr(0xc0);	
			d_wr(b);
			 a=0x30;
	 		for(i=0;i<10;i++)
	 		{	
	 			c_wr(0xc1);	
				d_wr(a);
				delay(1000);
				a++;	
	 		} 
				b++;
		 }
	}
	
}


