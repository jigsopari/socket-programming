
/*************************** File: root.c *************************/

#define SIO_PORT_BASE 0x3f8
#define SIO_DATA_PORT SIO_PORT_BASE+0
#define SIO_STAT_PORT SIO_PORT_BASE+5

#define SIO_RXRDY_BIT   0x1
#define SIO_TXEMPTY_BIT 0x20
int i=20;
int j;

/*** Input a character from serial channel in polling mode ***/
unsigned char getchar()
{
  unsigned char ch;
  while(!(inb(SIO_STAT_PORT) & SIO_RXRDY_BIT))
  {
  }
  ch = inb(SIO_DATA_PORT);
  return ch;
}

/*** output a character on to serial channel in polling mode ***/
void putchar(unsigned char ch)
{
  while(!(inb(SIO_STAT_PORT) & SIO_TXEMPTY_BIT))
  {
  }
  outb(SIO_DATA_PORT,ch);
}  

void puts(char *str)
{
  while(*str)
    putchar(*str++);
}

/*** Simple echo function. This function receives one character over 
*    serial channel and echos the same char on the serial channel***/
root()
{
  char ch;

  puts("First embedded program by durga\n\r");
  while(1)
  {
    ch = getchar();
    putchar(ch);

  if(ch == 3)
    break;
  }
}  
