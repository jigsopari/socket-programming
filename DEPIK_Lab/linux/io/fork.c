#include <stdio.h>

 main()
{
  
  int status;
  printf("i am parent\n");
  if(fork() == 0)
  {
  printf("child started");
  execl("/bin/ls","ls",0);
  printf("child ended\n");
  }
  waitpid(0,&status,0);
  printf("child exited with %d status\n",status);
}  
