#include <stdio.h>
#include <termios.h>
#include <fcntl.h>

int getPassWd(char *passwd)
{
  int ii=0;
  struct termios cuset,newset;
  char ch;


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
    
main()
{
  char pw[20];

  printf("Enter password : ");
  getPassWd(pw);
  printf("Your password: %s\n",pw);
}
