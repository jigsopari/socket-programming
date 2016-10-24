
/*************************** File: root.c *************************/

#define SIO_PORT_BASE 0x3f8
#define SIO_DATA_PORT SIO_PORT_BASE+0
#define DIV_LATCH_LOW SIO_PORT_BASE+0
#define DIV_LATCH_HIGH SIO_PORT_BASE+1
#define LCR SIO_PORT_BASE+3
#define SIO_STAT_PORT SIO_PORT_BASE+5

#define ADDR_PORT 0x70
#define DATA_PORT 0x71

#define SIO_RXRDY_BIT   0x1
#define SIO_TXEMPTY_BIT 0x20

#define MAX_CMDS 10 
#define MAX_CMD_LEN 100

unsigned char *commands[MAX_CMDS] = {"help","cb","spkon","spkoff","sound","dtime","reboot","ledon","ledoff","exit"};

unsigned char mygetchar()
{
  unsigned char ch;
  while(! ( inb(SIO_STAT_PORT) & SIO_RXRDY_BIT))
  {
  }
  ch = inb(SIO_DATA_PORT);
  return ch;
}

void myputchar(unsigned char ch)
{
  while(!(inb(SIO_STAT_PORT) & SIO_TXEMPTY_BIT))
  {
  }
  outb(SIO_DATA_PORT,ch);
}  

void myputs(char *str)
{
  while(*str)
    myputchar(*str++);
}

void getCommand(char *cBuf,int len)
{
  int index = 0;
  char ch;
  while(1)
  {
    ch = mygetchar();
    myputchar(ch);
    if(ch == '\r')
    {
      cBuf[index] = '\0';
      return; 
    }  
    else if(ch == '\b')  
    {  
      index -=1;
      myputchar(' ');
      myputchar('\b');
    }  
    else if(index == len-1)
    {
      cBuf[index] = '\0';
      return;
    }  
    else 
    {
      cBuf[index] = ch; 
      index++;
    } 
  }
}
void extractString(char *mainString, char *subString,int strNum)
{
  int ii;
  while(*mainString != '\0' && *mainString != ' ')
  {
    if(strNum == 0)
    {
      ii = 0;
      while(*mainString != '\0' && *mainString != ' ')
      {
        subString[ii] = *mainString;
	ii++;
	mainString++;
      }
      subString[ii] = '\0';
    }
    else if(strNum == 1)
    {  
      ii=0;
      //mainString++;
      while(*mainString != ' ')
      {
        subString[ii] == *mainString;
        ii++;
        mainString++;
      }
      mainString++;
      strNum--;
    }
  }
}  


changeBaud(int baudRate)
{
  unsigned char temp;
  unsigned char divisor;
  temp = inb(LCR);
  temp = temp | 0x80;
  outb(LCR,temp);
  myputs("start\n\r");
  switch(baudRate)
  {
    case 9600:
         outb(DIV_LATCH_LOW,0x0c);
         outb(DIV_LATCH_HIGH,0x00);
         temp = temp & ~0x80;
         outb(LCR, temp);
	 break;
    case 19200:
         outb(DIV_LATCH_LOW,0x06);
         outb(DIV_LATCH_HIGH,0x00);
         temp = temp & ~0x80;
         outb(LCR, temp);
	 break;
    case 38400:
         outb(DIV_LATCH_LOW,0x03);
         outb(DIV_LATCH_HIGH,0x00);
         temp = temp & ~0x80;
         outb(LCR, temp);
	 break;
    case 57600:
         outb(DIV_LATCH_LOW,0x02);
         outb(DIV_LATCH_HIGH,0x00);
         temp = temp & ~0x80;
         outb(LCR, temp);
	 break;
    case 115200:
         outb(DIV_LATCH_LOW,0x01);
         outb(DIV_LATCH_HIGH,0x00);
         temp = temp & ~0x80;
         outb(LCR, temp);
	 break;
    default:
         myputs("invalid baud Rate\n\r");
         return;
  } 
}

int atoi(char *digitString)
{
  int sum = 0;
  while(*digitString != '\0')
  {
    sum = (sum * 10) + (*digitString - '0');
    digitString++;
  }
  return sum;
}  

void speakeron()
{
  unsigned char reg;
  reg = inb(0x61);
  reg = reg | 0x03;
  outb(0x61,reg);
}  

void speakeroff()
{
  unsigned char reg;
  reg = inb(0x61);
  reg = reg & ~0x03;
  outb(0x61,reg);
}  
  
char *mymemset(char *cBuf, int c, int size)
{
  int ii;
  for(ii=0;ii<size;ii++)
  {
    cBuf[ii] = c;
  }
  return cBuf;
}  
   
int changeFrequency(int soundFreq)
{
  unsigned short count = (1190000/soundFreq);
  outb(0x43,0xb6);
  outb(0x42,count&0xff);
  outb(0x42,(count>>8)&0xff);
}  

void puthex(unsigned char value)
{
  unsigned char hex;
    hex = value>>4;
    if(hex < 10)
     myputchar((hex) + '0');
    else
     myputchar((hex) + '0'+39);

    hex = value & 0x0f;
    if(hex < 10)
     myputchar((hex) + '0');
    else
     myputchar((hex) + '0'+39);
}

void displayCmosTime()
{
  unsigned char value;
  outb(ADDR_PORT,0x04);
  value = inb(DATA_PORT);
  puthex(value);
     myputs(":");
  outb(ADDR_PORT,0x02);
  value = inb(DATA_PORT);
  puthex(value);
     myputs(":");
  outb(ADDR_PORT,0x00);
  value = inb(DATA_PORT);
  puthex(value);
}
    
void rebootHardware()
{
  outb(0x64,0xfe);
  return;
}  
 
void ledon(char *subStr)
{
  unsigned char num;
  unsigned char led;
  num = atoi(subStr);
  num = 1 << (num-1);
  led = inb(0x378);
  led = led | num;
  outb(0x378,led);
}
void ledoff(char *subStr)
{
  unsigned char num;
  unsigned char led;
  num = atoi(subStr);
  num = 1 << (num-1);
  led = inb(0x378);
  led = led & ~num;
  outb(0x378,led);
}
  
  
cliMain()
{
  char cmdBuf[MAX_CMD_LEN];
  char ch;
  int ii;
  char subStr[16];
  while(1)
  {
    myputs("\n\rDurgaCli> ");
    getCommand(cmdBuf,MAX_CMD_LEN);
    //myputs(cmdBuf);
    extractString(cmdBuf,subStr,0);
    //myputs(subStr);

    for(ii=0; ii<MAX_CMDS; ii++)
    {
      if(mystrcmp(subStr, commands[ii]) == 0)
        break;
    }
    if(ii < MAX_CMDS)
    {
      switch(ii)
      {
        case 0:
	  myputs("help          :List all commands help strings\n\r");
	  myputs("cb <baudRate> :Change the bauderate of the serial communication\n\r");
	  myputs("spkon         :speaker should start beeping\n\r");
	  myputs("spkoff        :speaker should stop beeping\n\r");
	  myputs("sound <frequency> :program the timer chip for given frequency\n\r");
	  myputs("dtime             :Display the time by reading from CMOS clock chip\n\r");
	  myputs("reboot            :Reboot the hardware\n\r");
	  myputs("ledon <led Num>   :power on the given LED\n\r");
	  myputs("ledoff <led Num>  :power off the given LEDs without affecting other LEDs\n\r");
	  myputs("exit              :to come to dpboot prompt\n\r");
	  break;
       case 1:
            extractString(cmdBuf,subStr,1);
	    changeBaud(atoi(subStr));
            break;
       case 2:
            speakeron();
	    break; 
       case 3:
            speakeroff();
	    break;
       case 4:
            extractString(cmdBuf,subStr,1);
	    changeFrequency(atoi(subStr));
	    break;
       case 5:
            displayCmosTime();
	    break;
      case 6:
            rebootHardware();
	    break;
     case 7:
           extractString(cmdBuf,subStr,1);
           myputs(subStr);
	   ledon(subStr);
	   break;
     case 8:
           extractString(cmdBuf,subStr,1);
	   ledoff(subStr);
	   break;
          
       case 9:	  
            myputs("\n\rpress ctrl+c.............\n\r");
	    ch = mygetchar();
            if(ch == 3)
            return;
      }
	  mymemset(cmdBuf,'\0',MAX_CMD_LEN);
	  mymemset(subStr,'\0',16);
    }
  }
}   
int mystrcmp(char *s1, char *s2)
{
  while((*s1 == *s2) && *s1 && *s2)
  {
      s1++;
      s2++;
  } 
  return *s1 - *s2;
}

/*** output a character on to serial channel in polling mode ***/

