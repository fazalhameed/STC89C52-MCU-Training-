
#include<reg51.h>
sbit led=P2^0;                /* set led pin0 of port2 */
void delay(unsigned int);
void timer0(void) interrupt 1
{
	unsigned char count;
count++;
if (count==110)
{	
	led=~led;               /* Toggle led pin */
	count=0;
}	
}
	void main(void)
{
	unsigned int h;
  TMOD = 0x02;    // Timer 0 Mode 2
  TH0= -84;     //initial value for 1ms
  IE=0x82;
  TR0 = 1;     // timer start
	while(1)
	{}
	}