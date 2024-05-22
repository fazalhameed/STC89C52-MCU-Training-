#ifndef LCD_H
#define LCD_H

void lcd_init();
void lcd_cmd(unsigned char);
void lcd_dat(unsigned char);
void msdelay(unsigned char);
void lcd_string(unsigned char *);
void LCD_Command (unsigned char);

void dataa(unsigned char lcd_data);
void MSDelay(unsigned int itime);
void lcd_write(unsigned char);
void delay1(unsigned int);
#endif