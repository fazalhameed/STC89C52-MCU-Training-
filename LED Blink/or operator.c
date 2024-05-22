#include <reg51.h>
sbit led =P2^0; //led pin declaration

void delay () //delay function declaration
{
	int i,j;
	for(i=0; i<500; i++)
				for(j=0; j<58; j++);
}
void main()
{
	P2=0xff;
	led=oxff |~0x01;
	while(1)
	{
		led=1;
		delay();
		led=0;
		delay();
	}
}