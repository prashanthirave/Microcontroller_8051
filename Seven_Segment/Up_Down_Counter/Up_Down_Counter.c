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
	here is code create for Common Anode  up-down counter.
*/

#include <REG51F.H>
#include "delay.h"
void display();
void increment();
void decrement();
unsigned char r0,r1,r2,r3;
unsigned char a[]={0xfc,0x60,0xda,0x0f2,0x66,0x0b6,0x0be,0x0e0,0x0fe,0x0f6,0x0ee};

void main()
{
	r0=0;
	r1=0;
	r2=9;
	r3=9;
  	while(1)
	{
	for(B=0;B<200;B++)
	 display();
	 increment();
	 
	for(B=0;B<200;B++)
	 display();
	 decrement();
	}		   
}

 void display()
 {
 	P2=0x0e;
	P0=a[r0];
	delay(2);
	P2=0x0d;
	P0=a[r1];
	delay(2); 
	P2=0x0b;
	P0=a[r2];
	delay(2);
	P2=0x07;
	P0=a[r3];
	delay(2);
 }
 
 void increment()
 {
 	r0++;
	if(r0==10)
	{
	 r0=0;
	 r1++;
	 if(r1==10)
	 {
	  r1=0;
	 }
	}
}  
 

 void decrement()
{
 	r2--;
	if(r2==0)
	{
	 r2=10;
	 r3--;
	if(r3==0)
	{
	 r3=10;	
	}
	}
}
