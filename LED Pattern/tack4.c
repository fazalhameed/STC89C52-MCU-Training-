#include <reg52.h>
#define  led P2 //led port declaration
//delay function declaration
void delay (unsigned int);
void delay (unsigned int t) 
{
	unsigned int i,j;
	for(i=0; i<t; i++)
				for(j=0; j<112; j++);
}
void main()
{
while(1)
{
	led=0xAA;
	delay(500);
	led=0x55;
	delay(500);
}
}