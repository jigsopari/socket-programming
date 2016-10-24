
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

unsigned char *commands[MAX_CMDS] = {"help","add","sub","mul","div","mod","exit"};

  char cmdBuf[MAX_CMD_LEN];
  char subStr[16];
  int num1;
  int num2;


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
      //myputs("if strnum = 0\n\r");
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
      //myputs("if strnum=1");
    }
     else if(strNum == 2)
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
      //myputs("if strnum=1");
    }
  }
}  

// itoh(un)



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
 
void *mymemset(char *cBuf, int c, int size)
{
  int ii;
  for(ii=0;ii<size;ii++)
  {
    cBuf[ii] = c;
  }
  return cBuf;
}  
   

void dispAsHexNumber(int val)
{
  int i=0,hex;
  char array[4];
  while(val)
  {
    hex=val%16;
    if(hex<10)
    array[i++]=(val%16)+'0';
    else
    array[i++]=(val%16)+'a'-10;
    val=val/16;
  }
  myputs("\n\rResult in HexaDecimal form:");
  while(i>0)
  {
    myputchar(array[--i]);
  }
}

void itoa(int val)
{
  int ii =0;
  char array[20];
  while(val)
  {
    array[ii] = (val % 10) + '0';
    val = val/10;
    ii++;
  }
  myputs("\n\rResult in Decimal form:");
  while(ii>0)
  myputchar(array[--ii]);
} 

int htoi(char *buf)
{
  int sum = 0;
  while(*buf)
  {
    if((*buf-'0') < 10)
      sum = (sum * 16) + (*buf - '0');
    else if((*buf >= 'a') && (*buf <= 'f'))
      sum = (sum * 16) + (*buf - 'a');
    else if((*buf >= 'A') && (*buf <= 'F'))
      sum = (sum * 16) + (*buf - 'A');
    buf++;   
  }
  return sum;
}


cliMain()
{
  char cmdBuf[MAX_CMD_LEN];
  char ch;
  int ii;
  char subStr[16];
  while(1)
  {
    myputs("\n\rDurgaCalc> ");
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
	  myputs("add <num1> <num2> :Addition\n\r");
	  myputs("sub <num1> <num2> :subtraction\n\r");
	  myputs("mul <num1> <num2> :multiplication\n\r");
	  myputs("div <num1> <num2> :division\n\r");
	  myputs("mod <num1> <num2> :modulo division\n\r");
	  myputs("exit              :to come to dpboot prompt\n\r");
	  break;
       case 1:
            extractString(cmdBuf,subStr,1);
	    if(mystrncmp(subStr,"0x",2) == 0)
	    {
             num1 = htoi(subStr);
	     }
	    else   
             num1 = atoi(subStr);
	     
            extractString(cmdBuf,subStr,2);
	    if(mystrncmp(subStr,"0x",2) == 0)
             num2 = htoi(subStr);
	    else   
             num2 = atoi(subStr);
	     
	     num1 = num1 + num2;
             itoa(num1);
             dispAsHexNumber(num1);
            break;
       case 2:
            extractString(cmdBuf,subStr,1);
	    if(mystrncmp(subStr,"0x",2) == 0)
             num1 = htoi(subStr);
	    else   
             num1 = atoi(subStr);
	     
            extractString(cmdBuf,subStr,2);
	    if(mystrncmp(subStr,"0x") == 0)
             num2 = htoi(subStr);
	    else   
             num2 = atoi(subStr);
	     
	     num1 = num1 - num2;
             itoa(num1);
             dispAsHexNumber(num1);
            break;

       case 3:
            extractString(cmdBuf,subStr,1);
	    if(mystrncmp(subStr,"0x",2) == 0)
             num1 = htoi(subStr);
	    else   
             num1 = atoi(subStr);
	     
            extractString(cmdBuf,subStr,2);
	    if(mystrncmp(subStr,"0x") == 0)
             num2 = htoi(subStr);
	    else   
             num2 = atoi(subStr);
	     
	     num1 = num1 * num2;
             itoa(num1);
             dispAsHexNumber(num1);
            break;

       case 4:
            extractString(cmdBuf,subStr,1);
	    if(mystrncmp(subStr,"0x",2) == 0)
             num1 = htoi(subStr);
	    else   
             num1 = atoi(subStr);
	     
            extractString(cmdBuf,subStr,2);
	    if(mystrncmp(subStr,"0x") == 0)
             num2 = htoi(subStr);
	    else   
             num2 = atoi(subStr);
	     
	     num1 = num1 / num2;
             itoa(num1);
             dispAsHexNumber(num1);
            break;

       case 5:
            extractString(cmdBuf,subStr,1);
	    if(mystrncmp(subStr,"0x",2) == 0)
             num1 = htoi(subStr);
	    else   
             num1 = atoi(subStr);
	     
            extractString(cmdBuf,subStr,2);
	    if(mystrncmp(subStr,"0x",2) == 0)
             num2 = htoi(subStr);
	    else   
             num2 = atoi(subStr);
	     
	     num1 = num1 % num2;
             itoa(num1);
            dispAsHexNumber(num1);
            break;
       case 6:
            myputs("press ctrl+c..........\n\r");
	    return;
      default:
            myputs("invalid command\n\r");
	    break;
      }
    }
  }
}
int mystrncmp(char *s1, char *s2,int size)
{
  while((*s1 == *s2) && *s1 && *s2)
  {
      s1++;
      s2++;
      size--;
      if(size==1)
       break;
  } 
  return *s1 - *s2;
}
int mystrcmp(char *s1, char *s2)
{
  while((*s1==*s2) && *s1 && *s2)
  {
    s1++;
    s2++;
  }
  return (*s1 - *s2);
}  
