#include <>reg51.h>
#include "task3.h"
#include<stdio.h>
#define LCD_Port P0				/* P2 port as data_port */
sbit rs=P2^6;							/* Register select pin */
sbit rw=P2^5;							/* Read/Write pin */
sbit en=P2^7;							/* Enable pin */
d LCD_Init (void);
unsigned char i;
unsigned char k;
unsigned char hour[2];
unsigned char Min[2];
unsigned char sec[2];
unsigned char colon;
unsigned char Mystring[8];	