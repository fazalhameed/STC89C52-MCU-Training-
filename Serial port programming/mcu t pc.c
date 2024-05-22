#include<reg51.h>
void delay(unsigned int itime )
{
	int i,j;
	for(i=0;i<itime;i++)
	for(j=0;j<114;j++);
	
}

unsigned int u=0;
void main()
{
	unsigned char Mystring[]="Helo world\n";
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
	for(u=0;u<14;u++)
	{
	SBUF=Mystring[u];
	while(TI==0);
	TI=0;
}
delay(300);
	}