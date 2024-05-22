#include <reg51.h>
#include "lcd.h"
#define LCD_data P0
sbit rs = P2^6;
sbit rw = P2^5;
sbit en = P2^7;
sbit wr=P2^5;
void lcd_init();
void lcd_cmd(unsigned char);
void lcd_dat(unsigned char);
void msdelay(unsigned char);
void lcd_string(unsigned char *lcd_data);

void lcd_init()
{
	delay1(20);		/* LCD Power ON Initialization time >15ms */
	LCD_Command (0x38);	/* Initialization of 16X2 LCD in 8bit mode */
	LCD_Command (0x0E);	/* Display ON Cursor blinking */
	LCD_Command (0x06);	/* Auto Increment cursor */
	LCD_Command (0x01);	/* clear display */
	LCD_Command (0x80);	/* cursor at home position */

}
void lcd_string(unsigned char *lcd_data)
{
   while(*lcd_data)
   {
   lcd_write(*lcd_data++);
   }

}

void LCD_Command (unsigned char cmd)	
{
	LCD_data= cmd;
	rs=0;				/* command reg. */
	wr=0;				/* Write operation */
	en=1; 
	delay1(1);
	en=0;
	delay1(5);
}
void lcd_write(unsigned char lcd_data)
{
LCD_data=lcd_data;
rs=1;
wr=0;
en=1;
delay1(1);
en=0;

}
void delay1(unsigned int count)  /* Function to provide delay Approx 1ms */
{
	int i,j;
	for(i=0;i<count;i++)
	for(j=0;j<112;j++);
}
