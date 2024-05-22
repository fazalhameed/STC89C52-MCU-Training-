#include<reg51.h>
#define LED P0
sbit r=P2^4;
sbit t=P2^3;
sbit y=P2^2;
void delay(unsigned int);
int count_20ms=0; 
void timer0(void) interrupt 1
{
	count_20ms ++ ;
	if (count_20ms = 100)                //if counter reaches 20 it means 200 ms have passed
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
		 count_20ms=0;
		
		
	}

}	

	void main(void)
{


  TMOD = 0x02;    // Timer 0 Mode 2
  TH0= 0xB8;     //initial value for 1ms
  IE=0x82;
  TR0 = 1;     // timer start
	while(1)
	{}
}