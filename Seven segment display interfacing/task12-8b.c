#include<reg51.h>
#define LED P0
sbit r=P2^4;
sbit t=P2^3;
sbit y=P2^2;
void delay();   //delay funtion
unsigned char display_7_seg[]={9,5,5,0,1,0,5,4};
unsigned int num[] = {0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6f};
void  disp(unsigned char);
unsigned int i;
char h;
char z;
void main(void)   //main
{	
	while(1)
	{
		 r=1,t=1,y=1;
	   disp(0) ;
		 r=1,t=1,y=0;
     disp(1);
		 r=1,t=0,y=1;
	   disp(2);
		 r=1,t=0,y=0;
     disp(3);
		 r=0,t=1,y=1;
	   disp(4);
		 r=0,t=1,y=0;
     disp(5);
		 r=0,t=0,y=1;
	   disp(6);
     r=0,t=0,y=0;
	   disp(7);	
      }
		}
	void delay(void)
  {	
	for( i=0;i<1000;i++);
		for( i=0;i<50;i++);
}	
 void  disp(unsigned char h)
 {
	 z=h;
	{
	 if(display_7_seg [h]==0)
	 { 
		for(z=0;z<50;z++)
		 {
       P0=num[0];
		   delay();
			}
		}
	 if(display_7_seg [h]==1)
	 { 
		for(z=0;z<50;z++)
		 {
       P0=num[1];
		   delay();
	    }
    }
		if(display_7_seg [h]==2)
		{ 
		for(z=0;z<50;z++)
		 {
       P0=num[2];
		   delay();
				}
			}
		if(display_7_seg [h]==3)
		{
			for(z=0;z<50;z++)
		  {
        P0=num[3];
		    delay();
				}
			}
		if(display_7_seg [h]==4)
		{ 
			for(z=0;z<50;z++)
		  {
        P0=num[4];
		    delay();
				}
			}
		if(display_7_seg [h]==5)
		{ 
			for(z=0;z<50;z++)
		  {
        P0=num[5];
		    delay();
				}
			}
		if(display_7_seg [h]==6)
		{ 
			for(z=0;z<50;z++)
		  {
       P0=num[6];
		   delay();
				}
			}
		if(display_7_seg [h]==7)
		{ 
		 for(z=0;z<50;z++)
		 {
      P0=num[7];
		  delay();
			}
		}
		if(display_7_seg [h]==8)
		{ 
		 for(z=0;z<50;z++)
		 {
      P0=num[8];
		  delay();
			}
		}
		if(display_7_seg [h]==9)
		{ 
		 for(z=0;z<50;z++)
		 {
      P0=num[9];
		  delay();
			}
		}
	}
}
 