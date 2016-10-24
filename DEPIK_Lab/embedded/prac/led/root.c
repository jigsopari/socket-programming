
/*************************** File: root.c *************************/

#define LEDS_PORT 0x378
#define KEYS_PORT 0x379

#define BUSY_BIT 0x80

/******************** Digital I/O Functions ************************/

#define SIO_PORT_BASE 0x3f8
#define SIO_DATA_PORT SIO_PORT_BASE+0
#define SIO_STAT_PORT SIO_PORT_BASE+5

#define SIO_RXRDY_BIT   0x1
#define SIO_TXEMPTY_BIT 0x20

unsigned char drvKeysRead()
{
  unsigned char keys;

  keys = inb(KEYS_PORT);

  if(keys & BUSY_BIT)
    keys = keys & 0x7b;
  else
    keys = keys | BUSY_BIT;

  keys = ~keys;

  keys = keys >> 3;
  return keys;
}

void drvLedsWrite(unsigned char leds)
{ 
  outb(LEDS_PORT, leds);
}

root()
{
  unsigned char keys;
  unsigned char ch;

  while(1)
  {
    keys = drvKeysRead();

    drvLedsWrite(keys);
  }
}   
