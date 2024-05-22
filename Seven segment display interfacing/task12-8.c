#include<reg51.h>
#define LED P0
sbit r=P2^4;
sbit t=P2^3;
sbit y=P2^2;
 
void delay(void);      //delay function
unsigned char display_num_7_seg[]={0x66,0x5b,0x4f, 0x6d, 0x66,0x5b,0x66, 0x6d};

void main()    //main function
{	
int k=0;
	while(1)
	{
		for(k=0;k<8;k++)
		{
		P0 = display_num_7_seg[k];
		delay();	
      }
	}
	}
	void delay()
  {
		 int i=0;
	for(i=0;i<20;i++)
{
  TMOD = 0x01;    // Timer 0 Mode 1
  TH0= 0xB8;     //initial value for 30ms
	TL0= 0x02;
  TR0=1;
  while (TF0==0);
	TR0=0;
  TF0=0;
   }	
 }
 
	

