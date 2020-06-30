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
	here is code create for Common Anode to display HELLO on 7_segment
*/

#include <REG51F.H>
#include "delay.h"
void display();
void increment();
unsigned char r0,r1,r2,r3,r4;
unsigned char a[]={0x00,0x6e,0x9e,0x1c,0x1c,0xfc,0x02};

void main()
{
	r0=0;
	r1=0;
	r2=0;
	r3=0;
	r4=0;
  	while(1)
	{
	for(B=0;B<255;B++)
	 display();
	 increment();
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
 	r4=r3;
	r3=r2;
	r2=r1;
	r1=r0;
	r0++;
	if(r0==7)
	{
	r0=0; 
 	}
 }
