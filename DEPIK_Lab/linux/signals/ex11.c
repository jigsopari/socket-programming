#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <signal.h>

struct termios cuset,newset;

void sig_handler(int signo)
{
  if(signo==SIGINT) 
  {
    printf("I received interrupt signal\n");
  }
  else if(signo==SIGQUIT)
  {
    printf("I received quit signal\n");
  }
  else
  {
    printf("I received signal %d \n",signo);
  }
    //tcsetattr(0,TCSANOW,&cuset);
    exit(1);
  
}  
  
int getPassWd(char *passwd)
{
  int ii=0;
  char ch;

  tcgetattr(0,&cuset);
  newset=cuset;
  newset.c_lflag |= ICANON;
  newset.c_lflag |= ECHO;
  tcsetattr(0,TCSANOW,&newset);

  setbuf(stdin,NULL);
  setbuf(stdout,NULL);

  while((ch=getchar())!='\n')
  {
      passwd[ii++]=ch;
      putchar('*');
  }
    passwd[ii]=0;
    putchar('\n');
    //tcsetattr(0,TCSANOW,&cuset);
}  
    
main()
{
  char pw[20];
  signal(SIGINT,sig_handler);
  signal(SIGQUIT,sig_handler);
  
  printf("Enter password : ");
  getPassWd(pw);
  printf("Your password: %s\n",pw);
}  
