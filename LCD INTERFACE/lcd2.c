#include <reg51.h>
#include "lcd2.h"    //header

void lcd_init()   //LCD initialization
{    
	  lcdcmd(0x83);
    lcdcmd(0x38);
    lcdcmd(0x01);
    lcdcmd(0x0c);
	
}
void lcdcmd(unsigned char f)
{
    lcd_data=f;
    rs=0;
    rw=0;
    en=1;
    lcd_delay();
    en=0;
}

void ldata(unsigned char a)
{
    lcd_data=a;
    rs=1;
    rw=0;
    en=1;
    lcd_delay();
    en=0;
}
void show(unsigned char *z)
{
    while(*z) {
        ldata(*z++);
    }
}

void lcd_delay()
{
    unsigned int i;
    for(i=0;i<20000;i++);
}

int main()
{
    unsigned int j;
    lcd_init();
    while(1) {
        lcdcmd(0x83);
        show("   hey   ");
        lcdcmd(0xc0);
			  for(j=0;j<1000;j++);
        show(" how are u ");
        lcdcmd(0x01);
    }
}