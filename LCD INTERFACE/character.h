#include <reg51.h>
#define lcd_data P0
sbit rs=P2^6;
sbit rw=P2^5;
sbit en=P2^7;
void lcd_init();
void cmd(unsigned char a);
void dat(unsigned char b);
void show(unsigned char *s);
void lcd_delay();