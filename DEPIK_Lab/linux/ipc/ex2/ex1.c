#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <termios.h>

main()
{
  int ii=0;
  char buf[512];
  struct termios cuset,newset;
  //printf("Enter the characters.....to be printed in toggled manner\n");
    tcgetattr(0,&cuset);
    newset=cuset;
    newset.c_lflag &= ~ICANON;
    newset.c_lflag &= ~ECHO;
    tcsetattr(0,TCSANOW,&newset);
    while(1)
    {
      
      read(fileno(stdin),&buf[ii],1);
      if(buf[ii]=='\n')
        break;
      if((buf[ii] >= 'A') && (buf[ii] <='Z'))
        buf[ii] += 0x20;
      else if((buf[ii] >= 'a') && (buf[ii] <='z'))
        buf[ii] -= 0x20;
      write(1,&buf[ii],1);	
      ii++;
    }
    tcsetattr(0,TCSANOW,&cuset);
} 
