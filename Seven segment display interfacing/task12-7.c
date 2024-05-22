//To display 1-8 on 7_seg
#include<reg51.h>
#define display P0
sbit r=P2^4;
sbit t=P2^3;
sbit y=P2^2;
void delay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<10;j++);
}

void main(void)    //mainb function
{	
	while(1)
	{
	 {
		 r=1;
		 t=1;
		 y=1;
	   display = 0x06;
	   delay(10);
	 }
	 {
		 r=1;
		 t=1;
		 y=0;
     	display  = 0x5B;
	   delay(10);
	 }
	 {
		 r=1;
		 t=0;
		 y=1;
	    display = 0x4F;
		 delay(10);
	 }
	 {
		 r=1;
		 t=0;
		 y=0;
     display = 0x66;
		 delay(10);
	 }
	 {
		 r=0;
		 t=1;
		 y=1;
	    display = 0x6D;
		 delay(10);
	 }
	 {		
		 r=0;
		 t=1;
		 y=0;
    	 display = 0x7D;
		 delay(10);
	 }
	 {
		 r=0;
		 t=0;
		 y=1;
	    display = 0x07;
		 delay(10);
	 }
	 {
		 r=0;
		 t=0;
		 y=0;
	    display = 0x7F;
		 delay(10);
}	
}
}