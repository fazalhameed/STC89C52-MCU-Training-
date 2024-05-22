#include <reg51.h>
sbit led0 = P2^0;
sbit led1 = P2^1;
sbit led2 = P2^2;
sbit led3 = P2^3;
sbit button1 = P3^1;
sbit button2 = P3^0;
sbit button3 = P3^2;
sbit button4 = P3^3;
void delay(unsigned int t)
{
	unsigned int i,j;
 for(i=0; i<t; i++)
  for(j=0; j<100; j++);
}
void main ()
{
	while(1)
		{
			if (button1 == 0)
			{ 
				led0 = ~led0;
				delay();
				
			}
			else if (button2 == 0)
			{ 
				led1 = ~led1;
				delay();
				
			}
				else if (button3 == 0)
			{ 
				led2 = ~led2;
				delay();
				
			}
				else if (button4 == 0)
			{ 
				led3 = ~led3;
				delay();
				
			}
		}
	}