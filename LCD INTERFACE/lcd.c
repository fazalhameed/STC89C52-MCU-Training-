#include <reg51.h>
#include "lcd.h"

void lcd_delay(unsigned int k)
{
    int i,j;
    for(i=0;i<k;i++);
	 for(j=0;j<2000;j++);
}

void lcdcmd(unsigned char f)
{
    lcd_data=(lcd_data & 0x0F) |(f & 0xF0);
    rs=0;
	  rw=0;
    en=1;
    lcd_delay(1);
    en=0;
	  lcd_delay(1);
	  lcd_data=(lcd_data & 0x0F) |(f <<4);
    rs=0;
    en=1;
    lcd_delay(1);
    en=0;
}

void ldata(unsigned char a)
{
	lcd_data=(lcd_data & 0x0F) |(a & 0xF0);
    rs=1;
	  rw=0;
    en=1;
    lcd_delay(1);
    en=0;
	  lcd_delay(1);
	  lcd_data=(lcd_data & 0x0F) |(a <<4);
    rs=1;
    en=1;
    lcd_delay(1);
    en=0;
    
}
void LCD_String (char *str)	/* Send string to LCD function */
{
	int h;
	for(h=0;str[h]!=0;h++)  /* Send each char of string till the NULL */
	{
		ldata (str[h]);  /* Call LCD data write */
	}
}

void LCD_String_xy (char row, char pos, char *str)      /* Send string to LCD function */
{
	if (row == 0)
	lcdcmd((pos & 0x0F)|0x80);
	else if (row == 1)
	lcdcmd((pos & 0x0F)|0xC0);
	LCD_String(str);  	/* Call LCD string function */
}
void lcd_init()
{    
	  lcd_delay(20);      /* LCD Power ON Initialization time >15ms */
	  lcdcmd(0x02);       /* 4bit mode */
	  lcdcmd(0x28);       /* Initialization of 16X2 LCD in 4bit mode */
    lcdcmd(0x38);        /* 2 line */
    lcdcmd(0x01);        /* Clear display */
    lcdcmd(0x0c);       /* Display ON Cursor OFF */
  
}


void main()
{
    unsigned int j;
    lcd_init();
    while(1) {
      
        LCD_String("  HELLO   ");
        lcdcmd(0xc0);
        LCD_String(" Fazal Here  ");

        for(j=0; j<30000; j++);
        lcdcmd(0x01);
        for(j=0; j<30000; j++);
    }
}