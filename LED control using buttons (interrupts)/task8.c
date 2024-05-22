#include <reg51.h>
sbit led0 = P2^0;
sbit led1 = P2^1;
sbit led2 = P2^2;
sbit led3 = P2^3;

sbit button3 = P3^2;
sbit button4 = P3^3;
void delay();
	void main ()
{
	IE=0x85;
	while (1)
	{
		delay();
		
	}
}
 void extr1() interrupt 2    //Subroutine EX with Interrupt 
  {
		if(button3 == 0)
		{
    led0=~led0;
			led1=~led1;
	  delay();
		 }
		else if(button4 == 0)
		{
    led2=~led2;
			led3=~led3;
	  delay();
		 }
  }
	void delay()
   {
     int i;
     TMOD = 0x01;      // Timer0 mode1
     for(i=0;i<300;i++)
     {
       TH0=0xF8;              //initial values for 1 sec delay
       TL0=0xCC;
       TR0 = 1;               // timer0 start
       while (TF0 == 0);   // check overflow condition
       TR0 = 0;               // Stop Timer
       TF0 = 0;               // Clear flag
       }

}