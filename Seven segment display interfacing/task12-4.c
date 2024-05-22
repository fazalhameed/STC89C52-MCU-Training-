#include<reg51.h>
#define LED P0
sbit r=P2^4;
sbit t=P2^3;
sbit y=P2^2;
void delay(unsigned int);     // delay
int count_10ms=0; 
void timer0(void) interrupt 1    //inturrupt
{
	count_10ms ++ ;
	if (count_10ms = 100)                //if counter reaches 10 it means 100 ms have passed
	{
	 r=0,t=0,y=0;
	   P0 = 0xFF;
  
		 r=0,t=0,y=1;
     	P0 = 0xFF;
   
		 r=0,t=1,y=0;
	   P0 = 0xFF;
   
		 r=0,t=1,y=1;
    	P0 = 0xFF;
   
		 r=1,t=0,y=0;
	   P0 = 0xFF;
   
		 r=1,t=0,y=1;
    	P0 = 0xFF;
   
		 r=1,t=1,y=0;
	   P0 = 0xFF;
  
		 r=1,t=1,y=1;
	   P0 = 0xFF;
		 count_10ms=0;
	}
}	

	void main(void)   //main
{
  TMOD = 0x02;    // Timer 0 Mode 2
  TH0= 0xDC;     //initial value for 1ms
  IE=0x82;
  TR0 = 1;     // timer start
	while(1)
	{}
}