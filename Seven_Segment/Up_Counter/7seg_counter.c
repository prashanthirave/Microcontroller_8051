/************************************************

* Organisation Name		: Dot Hex Pvt. Ltd.
* Developer Name		: Prashant P. Hirave.
* Controller			: At89C51RD2
* IDE					: Keil4, Keil5.
* Language				: Embedded C. 

*************************************************/
#include <REG51F.H>
#include "delay.h"
void display();
void increment();
unsigned char r0,r1,r2,r3,ch;
unsigned int a[]={0xfc,0x60,0xda,0x0f2,0x66,0x0b6,0xbe,0xe0,0xfe,0xf6,0xee};

void main()
{
	r0=r1=r2=r3=6;
	
  	while(1)
	{
		for(ch=0;ch<100;ch++)
		{
			display();
		}
	 increment();
	}		   
}

 void display()
 {
 	P2=0xfe;
	P0=a[r0];
	delay(5);
 }
 
 void increment()
 {
		r0++;
	 if(r0==9)
	 {
			r0=0;
	 }
 }
