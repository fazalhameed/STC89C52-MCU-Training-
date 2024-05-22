#include<reg51.h>
#define LED P0
sbit r=P2^4;
sbit t=P2^3;
sbit y=P2^2;
void timerdelay();
void display();
 
void main(void)
{	
	 r=0,t=0,y=0;
	  display();
		 r=0,t=0,y=1;
     	 display();
		 r=0,t=1,y=0;
	    display();
		 r=0,t=1,y=1;
    	 display();
		 r=1,t=0,y=0;
	    display();
		 r=1,t=0,y=1;
    	 display();
		 r=1,t=1,y=0;
	    display();
		 r=1,t=1,y=1;
	    display();
}	

	void timerdelay(void)
{
  TMOD = 0x01;    // Timer 0 Mode 1
  TH0= 0x93;     //initial value for 30ms
	TL0= 0xD6;
   TR0=1;
    while (TF0==0);
		TR0=0;
	  TF0=0;
 
}
void display()
{  
	int i;
	P0 = 0x3F;  
		for (i=0; i<30; i++)   // Total of 600 ms delay
	{
		timerdelay();  //30 ms
	}
	P0 = 0x06;  
		for (i=0; i<30; i++)   // Total of 600 ms delay
	{
		timerdelay();  //30 ms
	} 
	P0 = 0x5b;  
		for (i=0; i<30; i++)   // Total of 600 ms delay
	{
		timerdelay();  //30 ms
	}
	
	P0 = 0x4f;  
		for (i=0; i<30; i++)   // Total of 600 ms delay
	{
		timerdelay();  //30 ms
	}
	P0 = 0x66;  
		for (i=0; i<30; i++)   // Total of 600 ms delay
	{
		timerdelay();  //25 ms
	}
	P0 = 0x6d;  
		for (i=0; i<30; i++)   // Total of 600 ms delay
	{
		timerdelay();  //30 ms
	} 
	P0 = 0x7d;  
		for (i=0; i<30; i++)   // Total of 600 ms delay
	{
		timerdelay();  //30 ms
	}
	P0 = 0x07;  
		for (i=0; i<30; i++)   // Total of 600 ms delay
	{
		timerdelay();  //30 ms
	}
	P0 = 0x7f;  
		for (i=0; i<30; i++)   // Total of 600 ms delay
	{
		timerdelay();  //30 ms
	}
	P0 = 0x6f;  
		for (i=0; i<30; i++)   // Total of 600 ms delay
	{
		timerdelay();  //30 ms
	}
}





