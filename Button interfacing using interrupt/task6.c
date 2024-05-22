#include<reg51.h>
sbit led=P2^0;
sbit btn=P3^0;

void delay();
void main()
  {
   IE=0x84;                    // Activating the interrupts  EX1
   while(1)
	 {	
		delay();
	 };
  }
 void extr1(void) interrupt 2    //Subroutine EX with Interrupt 
  {
		if(btn == 1)
		{
    led=~led;
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