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
	On P2.4 - P2.7 attached hex keypad 
	here is code create for Common Anode  
*/


#include <REG51F.H>

void row1();
void row2();
void row3();
void row4();
void disp();

sbit s1=P2^0;
sbit s2=P2^1;
sbit s3=P2^2;
sbit s4=P2^3;
sbit k4=P2^4;
sbit k5=P2^5;
sbit k6=P2^6;
sbit k7=P2^7;

void main()
{

	row1();
	row2();
	row3();
	row4();	
			

}

void row1()
{
	s1=0;
	s2=s3=s4=1;
	while(k4==0)
	{
	 P0=0xfc;
	}
		
	while(k5==0)
	{
	 P0=0x60;	
	}
	while(k6==0)
	{
	 P0=0xda;	
	}		
	while(k7==0)
	{
	 P0=0xf2;	
	}
	P0=0x00;
}

void row2()
{
	s2=0;
	s1=s3=s4=1;
	while(k4==0)
	{ 	
		disp();	
	 	P0=0x66;
	}
		
	while(k5==0)
	{
		disp();
	 	P0=0xb6;	
	}
	while(k6==0)
	{
	 	disp();	
		P0=0xbe;	
	}		
	while(k7==0)
	{
	 	disp();	
		P0=0xe0;	
	} 
	P0=0x00;

}

void row3()
{
	s3=0;
	s2=s1=s4=1;
	while(k4==0)
	{
		disp();	
	 	P0=0xfe;
	}
		
	while(k5==0)
	{
		disp();	
	 	P0=0xf6;	
	}
	while(k6==0)
	{
		disp();	
	 	P0=0xee;	
	}		
	while(k7==0)
	{
		disp();	
	 	P0=0x3e;	
	}	
	P0=0x00;	
}
 
void row4()
{
	s4=0;
	s2=s3=s1=1;
	while(k4==0)
	{
		disp();	
	 	P0=0x9c;
	}
			
	while(k5==0)
	{
		disp();	
	 	P0=0x7a;	
	}
	while(k6==0)
	{
	 	disp();	
	 	P0=0x9e;	
	}		
	while(k7==0)
	{
	 	disp();	
		P0=0x8e;	
	}
} 
   
void disp()
{
	s1=0;
	s2=s3=s4=1;
}
