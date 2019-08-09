#include< reg52.h>

sbit rs=P3^5;  //Lcd controlling pins
sbit rw=P3^6;
sbit en=P3^7;

void delay()
{
unsigned int i,j;
for(i=0;i<3000;i++)
for(j=0;j<10;j++);
}

void command(unsigned int comand) //Sending initialing commands to lcd
{
P2=comand; rw=0; rs=0; en=0;
delay();
en=1;
delay();
en=0;
}

void lcddata(char value) //Sending data to be displayed on lcd screen
{
P2=value; rw=0; rs=1; en=0;
delay();
en=1;
delay();
en=0;
}

void lcd() //Initialing lcd
{
delay(); command(0x30); delay(); command(0x30); delay(); command(0x30);
delay(); command(0x38); delay(); command(0x01); delay(); command(0x0F);
delay(); command(0x0C); delay(); 
command(0x80); //Lcd rirst row selected for data printing
delay();
}

void main()
{
lcd(); //First initialize 16x2 lcd, 5x7 matrix display, cursor off

lcddata(' '); lcddata('*'); delay(); lcddata('*'); delay(); lcddata('L');
delay(); lcddata('y'); delay(); lcddata('m'); delay(); lcddata('b');
delay(); lcddata('E'); delay(); lcddata('d'); delay(); lcddata('g');
delay(); lcddata('E'); delay(); lcddata('*'); delay(); lcddata('*');
delay(); lcddata(' '); delay(); lcddata(' ');
delay();

command(0xC0); //Command to jump to second row of lcd
delay(); lcddata(' '); delay(); lcddata(' '); delay(); lcddata(' ');
delay(); lcddata('R'); delay(); lcddata('O'); delay(); lcddata('B');
delay(); lcddata('O'); delay(); lcddata('T'); delay(); lcddata('I');
delay(); lcddata('C'); delay(); lcddata('S'); delay(); lcddata(' '); delay(); lcddata(' '); delay(); lcddata(' ');
delay(); lcddata(' ');
delay();
}