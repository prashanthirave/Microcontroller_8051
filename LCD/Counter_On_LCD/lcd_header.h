sbit BK=P0^0;
sbit RS=P0^1;
sbit RW=P0^2;
sbit EN=P0^3;


void lcd_string(unsigned char *p);
void d_wr(unsigned char ch);
void c_wr(unsigned char ch);
void lcd_init();

void lcd_init()
{

	c_wr(0x03);
   
	c_wr(0x03);
	
	c_wr(0x03);
	
	c_wr(0x02);

	c_wr(0x28);

	c_wr(0x0e);

//	c_wr(0x06);
	
	c_wr(0x01);
}
void lcd_string(unsigned char *p)
{
	while(*p!='\0')
	{
		d_wr(*p);
		p++;
	}
}
void c_wr(unsigned char ch)
{
	ACC=ch;
	ACC=ACC&0xf0;

	P0=ACC;
	RS=0;
	RW=0;
	
	EN=1;
	delay(5);
	EN=0;
	
	B=ch;
	B=B<<4;
	B=B&0xf0;
	P0=B;


	RS=0;
	RW=0;

	EN=1;
	delay(5);
	EN=0;
}
		 
void d_wr(unsigned char ch)
{
	ACC=ch;
	ACC=ACC&0xf0;

	P0=ACC;
	RS=1;
	RW=0;
	
	EN=1;
	delay(5);
	EN=0;
	B=ch;
	B=B<<4;
	B=B&0xf0;
	P0=B;


	RS=1;
	RW=0;

	EN=1;
	delay(5);
	EN=0;
}