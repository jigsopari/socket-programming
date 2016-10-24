#include <stdio.h>

void getCommand(char *cBuf,int len)
{
  int index = 0;
  char ch;
  while(1)
  {
    ch = getchar();
    putchar(ch);
    if(ch == '\r')
    {
      cBuf[index] = '\0';
      puts("carriage return\n\r");
      return; 
    }  
    else if(ch == '\b')  
    {  
      index -=1;
      putchar(' ');
      putchar('\b');
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
    puts("normal\n\r");
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
        puts("inner while\n\r");
        subString[ii] = *mainString;
	ii++;
	mainString++;
      }
      puts("if strnum = 0\n\r");
    }
    else if(strNum == 1)
    {  
      ii=0;
      mainString++;
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

main()
{
  char cmdbuf[100];
  char subString[20];
  getCommand(cmdbuf,100);
  extractString(cmdbuf,subString,0);
  printf("sub=%s",subString);
}
