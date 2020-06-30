/************************************************

* Organisation Name		: Dot Hex Pvt. Ltd.
* Developer Name		: Prashant P. Hirave.
* Controller			: At89C51RD2
* IDE					: Keil4, Keil5.
* Language				: Embedded C. 

*************************************************/

/*------------------------------------------------------------
If we consider 8 led's are connected to P0
for turn on led 
P0.0	P0.1	P0.2	P0.3	P0.4	P0.5	P0.6	P0.7
0		0		0		0		0		0		0		0	

for turn off led 
P0.0	P0.1	P0.2	P0.3	P0.4	P0.5	P0.6	P0.7
1		1		1		1		1		1		1		1	
---------------------------------------------------------------
*/

#include <REG51F.H>
sbit bz=P0^5;

void delay(unsigned int time);
void main()
{
	//unsigned char a;
	bz=1;
	while(ACC<=0xff)
	{
			P1=~bz;//0x00;
			delay(500);
			//P0=0xff;
			//delay();
			ACC++;
	}
}

void delay(unsigned int time)
{
	unsigned char i,j;

	for(i=0;i<time;i++)
	{
			for(j=0;j<255;j++);
	}

}
