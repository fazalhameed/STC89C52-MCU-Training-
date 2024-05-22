#include<reg51.h>
int count_10ms = 0;    
int count_100ms = 0;
int count_1000ms = 0;
sbit led1=P2^0;                /* set led pin0 of port2 */
sbit led2=P2^1;                /* set led pin1 of port2 */
sbit led3=P2^2;               /* set led pin2 of port2 */

void delay(unsigned int);
void timer0(void) interrupt 1
{
	unsigned char count;
  count_10ms++;
	count_100ms++;
	count_1000ms++;
if (count_10ms==110)
{	
	led1=~led1;               /* Toggle led for 10ms */
	count_10ms=0;
}
	if (count_100ms==1100)
	{
	led2=~led2;               /* Toggle led for 100ms */
		count_100ms=0;
	}
		if (count_1000ms==11100)
		{
	led3=~led3;                /* Toggle led for 1000ms */
	count_1000ms=0;
}	
}
	void main(void)
{
	unsigned int h;
  TMOD = 0x02;    // Timer 0 Mode 2
  TH0= -84;     //initial value for 1ms
  IE= 0x82;
  TR0 = 1;     // timer start
	while(1)
	{}
	}