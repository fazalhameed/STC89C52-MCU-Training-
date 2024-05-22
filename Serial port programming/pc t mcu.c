#include<reg51.h>
#include<stdio.h>
#define LCD_Port P0				/* P2 port as data_port */
sbit rs=P2^6;							/* Register select pin */
sbit rw=P2^5;							/* Read/Write pin */
sbit en=P2^7;							/* Enable pin */
unsigned char i;
unsigned char k;
unsigned char Mystring[16];
																																												
void delay(unsigned int count)    			/* Function to provide delay Approx 1ms with 12 Mhz crystal*/
{
     int i,j;
     for(i=0;i<count;i++)
     for(j=0;j<114;j++);
}

void LCD_Cmd (char f)										/* LCD16x2 command funtion */
{
	LCD_Port = f;	/* Send upper nibble */
	rs=0;																					/* Command reg. */
	rw=0;																					/* Write operation */
	en=1; 
	delay(1);
	en=0;
	delay(2);
}
void LCD_dat (char d)  										/* 	LCD_data write function */
{

	LCD_Port  = d;/*  Send upper nibble */
	rs=1;  																						/*	Data reg.*/
	rw=0;  																						/*Write operation*/
	en=1;  
	delay(1);
	en=0;
	delay(2);
}

void LCD_String (char *str)					/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)  					/* Send each character of string till the NULL */
	{
		LCD_dat (str[i]); 							/* Call LCD_data write */
	}
}

void LCD_String_xy (char row, char pos, char *str)  /* Send string to LCD function */
{
	if (row == 0)
	LCD_Cmd((pos & 0x0F)|0x80);
	else if (row == 1)
	LCD_Cmd((pos & 0x0F)|0xC0);
	LCD_String(str);  																/* Call LCD string function */
}

void LCD_Init (void)								/* LCD Initialize function */
{	
	delay(20);		/* LCD Power ON Initialization time >15ms */
	LCD_Cmd (0x38);	/* Initialization of 16X2 LCD in 8bit mode */
	LCD_Cmd (0x0C);	/* Display ON Cursor OFF */
	LCD_Cmd (0x06);	/* Auto Increment cursor */
	LCD_Cmd (0x01);	/* clear display */
	LCD_Cmd (0x80);	/* cursor at home position */
}
void main()
{
LCD_Init();	

	TMOD=0x20;
	TH1=0xFD; 
	SCON=0x50;
	PCON=0x00;
	TR1=1;
	while(1)
	{
	for(i=0;i<16;i++)
		{ 
			while(RI==0);
			RI = 0;
			Mystring[i] = SBUF;
		LCD_Cmd (0xC0);
		}
		

}
	}