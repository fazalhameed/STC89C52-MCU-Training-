#include <reg51.h>
#define lcd_data P0
sbit rs=P2^6;
sbit rw=P2^5;
sbit en=P2^7;
void lcd_init();
void lcdcmd(unsigned char f);
void ldata(unsigned char a);
void lcd_delay();