#include <reg51.h>
sbit r = P2^4;
sbit t = P2^3;
sbit y = P2^2;
void timer_delay ()
  {
		unsigned char count;
    for(count=0;count<20;count++)
		{
    TMOD = 0x01;    // Timer 0 Mode 1
    TH0= 0x44;     //initial value for 500ms
    TL0 = 0x80;
    TR0 = 1;     // timer start
    while (TF0 == 0); // check overflow condition
    TR0 = 0;    // Stop Timer
    TF0 = 0;   // Clear flag
  }
}
void main()
	{ 
	 r=0,t=0,y=0;
	P0 = 0xFF;
   timer_delay ();
		 r=0,t=0,y=1;
	P0 = 0xFF;
   timer_delay ();
		 r=0,t=1,y=0;
	P0 = 0xFF;
   timer_delay ();
		 r=0,t=1,y=1;
	P0 = 0xFF;
   timer_delay ();
		 r=1,t=0,y=0;
	P0 = 0xFF;
   timer_delay ();
		 r=1,t=0,y=1;
	P0 = 0xFF;
   timer_delay ();
		 r=1,t=1,y=0;
	P0 = 0xFF;
   timer_delay ();
				 r=1,t=1,y=1;
	P0 = 0xFF;
   timer_delay ();

	}