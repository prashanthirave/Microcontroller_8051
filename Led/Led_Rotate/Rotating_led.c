/************************************************

* Organisation Name		: Dot Hex Pvt. Ltd.
* Developer Name		: Prashant P. Hirave.
* Controller			: At89C51RD2
* IDE					: Keil4, Keil5.
* Language				: Embedded C. 

*************************************************/

/*------------------------------------------------------------
If we consider 8 led's are connected to P0

P0.0	P0.1	P0.2	P0.3	P0.4	P0.5	P0.6	P0.7
0		0		0		0		0		0		0		0	

---------------------------------------------------------------
*/
#include <REG51F.H>
#include "delay.h"


void main()
{
 	unsigned char a;
	do
	{ 
		B=0x01;
 		for(a=0;a<8;a++)
		{
		P0=B;
		delay();
		B=B<<1;
		}	
	 	B=0x80;
		for(a=0;a<8;a++)
		{
			P0=B;
			delay();
			B=B>>1;
		}		   
	}while(1);
}

