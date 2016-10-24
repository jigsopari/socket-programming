#include <stdio.h>
main()
{
  printf("I am going to emerge a new process%d\n",getpid());
  fork();
  fork();
  printf("i am ppid=%d i am pid=%d\n",getppid(),getpid());
}  
