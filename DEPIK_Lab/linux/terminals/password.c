#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

int getpasswd(char *passwd)
{
  int ii=0;
  struct termios cuset,newset;
  char ch;

  /***Disable echo and canonical mode of processing***/
  tcgetattr(0,&cuset);
  newset=cuset;
  newset.c_lflag &= ~ICANON;
  newset.c_lflag &= ~ECHO;
  tcsetattr(0,TCSANOW,&newset);
 
  setbuf(stdin,NULL);
  setbuf(stdout,NULL);

  while((ch=getchar())!='\n')
  {
    passwd[ii++]=ch;
    putchar('*');
  } 
  passwd[ii++]=0;
  putchar('\n');
  tcsetattr(0,TCSANOW,&cuset);
}
int main()
{
  char pw[20];
  printf("Enter password : ");
  getpasswd(pw);
  printf("your password is %s\n",pw);
}  
