/************************************************

* Organisation Name		: Dot Hex Pvt. Ltd.
* Developer Name		: Prashant P. Hirave.
* Controller			: At89C51RD2
* IDE				: Keil4, Keil5.
* Language			: Embedded C. 

*************************************************/
/*
	UART useing timer1 28800/3 = 9600 baudrate.
*/
#include <REG51F.H>
#include "delay.h"
void tx(unsigned char ch);
//unsigned char rx();


unsigned char rec_data,ch;

void main()
{
	P0=0x00;
	TMOD= 0x20;
	SCON= 0x52;
	TH1= 0xfd;
	TR1=1;
	EA=1;
	ES=1;
	
	while(1)
	{	
		ch='A';
		P0=0x55;
		delay(1000);
		tx(ch);
		
		
		
	
	}
}

void tx(unsigned char ch)
{
 	
	while(TI==0) ;
	SBUF =ch;
	TI=0;
}

//unsigned char rx()
////void isr_serial() interrupt 5 
//{
//
//	//while(RI==0);
//	ACC=SBUF;
//	RI=0;
//	P0=ACC;
//	//return ACC;
//}
