/************************************************

* Organisation Name		: Dot Hex Pvt. Ltd.
* Developer Name		: Prashant P. Hirave.
* Controller			: At89C51RD2
* IDE					: Keil4, Keil5.
* Language				: Embedded C. 

*************************************************/
/*
Timer0 interrupt 16 bit mode

*/


//-----led blinking using timer-----//

#include<reg51.h>
//------------------------------//
void isr_to();
void init_timer0();
//------------------------------//
void main()
{
  P0=0x00;
  init_timer0();
  EA=1;
  while(1);
}
//------------------------------//
void init_timer0()
{
  TMOD=0x01;
  TH0=0x00;
  TL0=0X00;
  TR0=1;
  ET0=1;
}
//------------------------------//
void isr_to()interrupt 1 using 1
{
  init_timer0();
  P0=~P0;
}
