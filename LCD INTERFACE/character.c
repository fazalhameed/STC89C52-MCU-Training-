//CUSTUM CHARACTOR
#include <reg51.h>
#include "character.h"
void lcd_init()
{
    cmd(0x38);
    cmd(0x0c);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);
}

void cmd(unsigned char a)
{
    lcd_data=a;
    rs=0;
    rw=0;
    en=1;
    lcd_delay();
    en=0;
}

void dat(unsigned char b)
{
    lcd_data=b;
    rs=1;
    rw=0;
    en=1;
    lcd_delay();
    en=0;
}

void show(unsigned char *s)
{
    while(*s)
{
        dat(*s++);
    }
}

void lcd_delay()
{
    unsigned int lcd_delay;
    for(lcd_delay=0;lcd_delay<=6000;lcd_delay++);
}
void store()
{
    cmd(64);          //First location
    dat(0);
    dat(10);
    dat(21);
    dat(17);
    dat(10);
    dat(4);
    dat(0);
    dat(0);
    cmd(0xc0);     //location for character
	  dat(0);         //display character created at 0x64 adddress
	  lcd_delay();
	
    cmd(72);          //Second location
    dat(4);
    dat(14);
    dat(14);
    dat(14);
    dat(31);
    dat(0);
    dat(4);
    dat(0);
		cmd(0xc2);
	  dat(1);
	  lcd_delay();

    cmd(80);            //Third location
    dat(31);
    dat(21);
    dat(31);
    dat(31);
    dat(14);
    dat(10);
    dat(27);
    dat(0);
		cmd(0xc4);
	  dat(2);
	  lcd_delay();
		
		
		
		cmd(88);            //4TH location
    dat(0);
    dat(1);
    dat(3);
    dat(22);
    dat(28);
    dat(8);
    dat(0);
    dat(0);
		cmd(0xc6);
	  dat(3);
	  lcd_delay();
		
		cmd(96);            //5TH location
    dat(1);
    dat(3);
    dat(15);
    dat(15);
    dat(15);
    dat(3);
    dat(1);
    dat(0);
		cmd(0xc8);
	  dat(4);
	  lcd_delay();
		
		
		cmd(104);            //6TH location
    dat(1);
    dat(3);
    dat(5);
    dat(9);
    dat(9);
    dat(11);
    dat(27);
    dat(24);
		cmd(0xca);
	  dat(5);
	  lcd_delay();
		
		cmd(112);            //7TH location
    dat(0);
    dat(14);
    dat(21);
    dat(27);
    dat(14);
    dat(14);
    dat(0);
    dat(0);
		cmd(0xcc);
	  dat(6);
	  lcd_delay();
		
		cmd(120);            //8TH location
    dat(14);
    dat(17);
    dat(17);
    dat(31);
    dat(27);
    dat(27);
    dat(31);
    dat(0);
		cmd(0xce);
	  dat(7);
	  lcd_delay();	
}
void main()
{
    lcd_init();
	show("CUSTOM CHARACTER");
    while(1) 
{
       store();	 
    }
}
