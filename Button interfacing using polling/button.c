#include <reg51.h>
sbit led =P2^0; // led pin initialization
sbit button = P3^1;  //button initioalization
void delay (unsigned int);  // delay function
void delay (unsigned int t)
	{
	unsigned int i,j;
  for(i=0; i<t; i++)
   for(j=0; j<100;j++);
	}
void main() 
{
	
    while(1) 
			{
        if (button == 0)
 {
					led=~led;
					delay(500);
        }
    }
}