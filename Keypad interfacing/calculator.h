#ifndef CALCULATOR_H
#define CALCULATOR_H
//pins
sbit r1 = P1^0;
sbit r2 = P1^1;
sbit r3 = P1^2;
sbit r4 = P1^3;
sbit c1 = P1^4;
sbit c2 = P1^5;
sbit c3 = P1^6;
sbit c4 = P1^7;


void calc();
void row_scan();
void delay(unsigned char);
void send_num(unsigned int);
void calculate();
//void lcd_init();
//void lcd_cmd(unsigned char);
//void lcd_dat(unsigned char);
//void msdelay(unsigned char);
//void lcd_string(unsigned char *);

#endif
